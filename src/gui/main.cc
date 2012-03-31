#include "main.hh"
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
using namespace std;

class Wanderer {
public:
	Wanderer(TexturePack*,bool);
	void update(int);
	int lastupdate;
	void draw(float);
	int x;
	bool goingright;
	TextureCard* card;
	bool alive;
};

Wanderer::Wanderer(TexturePack* texpack, bool right) {
	goingright = right;
	lastupdate = 0;
	if (goingright) {
		x = 0;
		card = texpack->getCard("walk_limesphere");
	}
	else {
		x = 50;
		card = texpack->getCard("walk_darkgreensphere");
	}
}

void Wanderer::draw(float delta) {
	if (alive) {
		if (goingright)
			card->draw(core::position2d<s32>(48+16*x+(float)(16*delta/1000),64));
		else
			card->draw(core::position2d<s32>(48+16*x-(float)(16*delta/1000),64));
	}
}

void Wanderer::update(int newupdate) {
	if (alive and newupdate > lastupdate) {
		if (goingright)
			x++;
		else
			x--;
		lastupdate = newupdate;
	}
}

enum State { LOAD, COLLECT, PUSH, DRAW, DEAD };

struct SharedData {
	map<int,int> commandtrack1;
	map<int,int> commandtrack2;
	bool loaded;
	bool connected;
	int now;
	int begin;
	int push1;
	int push2;
	State state;
};

int main() {
	
	SharedData sd;
	sd.loaded = false;
	sd.connected = false;
	sd.now = 0;
	sd.state = LOAD;
	
	sd.commandtrack1[0] = 0;
	sd.commandtrack1[1] = 0;
	sd.commandtrack2[0] = 0;
	sd.commandtrack2[1] = 0;
	
	
#pragma omp parallel sections num_threads(2) shared(sd)
{
#pragma omp section
	{
		TD::Socket sock;
		char buffer [127];
		bool server;
		try {
			cout << "Trying to connect..." << endl;
			sock.connect("localhost", 6666);
			std::cout << "Connected to " << sock.getHostName() << std::endl;
			server = false;
		}
		catch(int e) {
			TD::Socket server;
			cout << "No connection, hosting instead" << endl;
			sleep(1);
			server.bind(6666);
			cout << "Listening for connections." << endl;
			server.listen();		
			sock = server.accept();
			std::cout << "Connected to " << sock.getHostName() << std::endl;
			server.close();
			server = true;
		}
			
		sd.connected = true;
		while (not sd.loaded)
			sleep(1);
		
		int lastround = 0;
		int thisround = 0;
		
		if (server) {
			while (sd.state != DEAD) {
				thisround = sd.now / 1000;
				string recvish = sock.recvln();
				cout << "<" << recvish << endl;
				stringstream recvishish (recvish);
				
				int wround,w2;
				recvishish >> wround;
				recvishish >> w2;
				
				int w1 = sd.push1;
				sd.push1 = 0;
				
				stringstream sendish;
				sendish << wround << " " << w1 << " " << w2;
				
				cout << ">" << sendish.str() << endl;
				sock.sendln(sendish.str().c_str());
				sd.commandtrack1[wround] = w1;
				sd.commandtrack2[wround] = w2;
			}
		}
		else { // client
			while (sd.state != DEAD) {
				thisround = sd.now / 1000;
				if (thisround != lastround) {
					stringstream sendthing;
					sendthing << thisround + 1 << " " << sd.push2;
					sd.push2 = 0; 
					cout << ">" << sendthing.str() << endl;
					sock.sendln(sendthing.str().c_str());
					
					string recvthing = sock.recvln();
					cout << "<" << recvthing << endl;
					int vround, v1, v2;
					
					stringstream recvthingthing ( recvthing );
					recvthingthing >> vround;
					recvthingthing >> v1;
					recvthingthing >> v2;
					
					sd.commandtrack1[vround] = v1;
					sd.commandtrack2[vround] = v2;
				}
				lastround = thisround;

			}
		}
		
		sock.close();
	}
#pragma omp section
	{
		// set up environment
		IrrlichtScreen * irrscreen = new IrrlichtScreen;
		
		gui::IGUIFont* font = irrscreen->device->getGUIEnvironment()->getBuiltInFont();

		TexturePack * texpack = new TexturePack(irrscreen);
		texpack->addTexture("org_yellowsphere", "textures/cell/map/organelles/64/yellowsphere.png");
		texpack->addTexture("org_greensphere", "textures/cell/map/organelles/64/greenhalfsphere.png");
		texpack->addTexture("walk_limesphere", "textures/cell/map/walkers/limesphere.png");
		texpack->addTexture("walk_darkgreensphere", "textures/cell/map/walkers/darkgreensphere.png");

		TextureCard* orgyellow = texpack->getCard("org_yellowsphere");
		TextureCard* orggreen = texpack->getCard("org_greensphere");

		TextureCard* wyellow = texpack->getCard("walk_limesphere");
		TextureCard* wgreen = texpack->getCard("walk_darkgreensphere");
		
		orgyellow->setPosition( core::position2d<s32>(48,48) );
		orggreen->setPosition( core::position2d<s32>(800+48,48) );
		
		bool lmwasdown = false;
		bool spacewasdown = false;
		
		//set up timer	
		int oldsec = 0;
		bool newround = false;
		u32 then = irrscreen->device->getTimer()->getTime();
		
		//set up entities
		int onequeue = 0;
		int twoqueue = 0;
		vector<Wanderer*> wanderers;
		bool p1dead = false;
		bool p2dead = false;
		
		sd.loaded = true;
		irrscreen->run();
		irrscreen->beginScene();
		irrscreen->endScene();
		
		while (not sd.connected)
			sleep(1);
		
		irrscreen->run();
		sd.begin = irrscreen->device->getTimer()->getTime();
		
		//begin main loop!
		while (irrscreen->run()) {
			
			//run timer
			sd.now = irrscreen->device->getTimer()->getTime() - sd.begin;
			//cout << sd.now << endl;
			f32 dt = (f32)(sd.now - then) / 1000.f; // Time in seconds
			then = sd.now;
			int nowsec = sd.now/1000;
			int nowdelta = (sd.now % 1000);
			if (nowsec > oldsec) {
				newround = true;
			}
			else {
				newround = false;
			}
			oldsec = nowsec;
			

			
			//RUN GAME SIM
			
			if (newround) {
				onequeue += sd.commandtrack1[nowsec];
				twoqueue += sd.commandtrack2[nowsec];
				if (onequeue > 0) {
					wanderers.push_back( new Wanderer (texpack,true) );
					onequeue--;
				}
				if (twoqueue > 0) {
					wanderers.push_back( new Wanderer (texpack,false) );
					twoqueue--;
				}
			}
			
			//is game over?
			for (vector<Wanderer*>::iterator w = wanderers.begin(); w != wanderers.end(); w++) {
				if ((*w)->goingright and (*w)->x > 50)
					p2dead = true;
				if (not (*w)->goingright and (*w)->x < 0)
					p1dead = true;
			}
			
			// collision detection
			for (vector<Wanderer*>::iterator w = wanderers.begin(); w != wanderers.end(); w++) {
				for (vector<Wanderer*>::iterator v = wanderers.begin(); v != wanderers.end(); v++) {
					if ((*w)->alive and (*v)->alive) {
						if ((*w)->goingright != (*v)->goingright) {
							if (abs((*w)->x - (*v)->x) < 2) {
								(*w)->alive = false;
								(*v)->alive = false;
								printf("Kill\n");
							}
						}
					}
				}
			}
			
			//update wanderers
			for (vector<Wanderer*>::iterator w = wanderers.begin(); w != wanderers.end(); w++) {
				(*w)->update(nowsec);
			}
			
			//Handle player input
			if (irrscreen->receiver->mouse.leftButtonDown) {
				lmwasdown = true;
			}
			else {
				if (lmwasdown) {
					sd.push1++;
				}
				lmwasdown = false;
			}
			
			if (irrscreen->receiver->IsKeyDown(KEY_SPACE)) {
				spacewasdown = true;
			}
			else {
				if (spacewasdown) {
					sd.push2++;
				}
				spacewasdown = false;
			}

			// DRAW TO SCREEN
			irrscreen->beginScene();
			
			if (not p1dead)
				orgyellow->draw();
			if (not p2dead)
				orggreen->draw();
			
			for (vector<Wanderer*>::iterator w = wanderers.begin(); w != wanderers.end(); w++) {
				(*w)->draw(nowdelta);
			}
			
			core::stringw printnowsec = L"";
			printnowsec += nowsec;
			core::stringw printnowdelta = L"";
			printnowdelta += nowdelta;
			core::stringw printonequeue = L"";
			printonequeue += onequeue;
			core::stringw printtwoqueue = L"";
			printtwoqueue += twoqueue;
			
			font->draw(printnowsec,core::rect<s32>(130,10,300,50),video::SColor(255,255,255,255));
			font->draw(printnowdelta,core::rect<s32>(170,10,350,50),video::SColor(255,255,255,255));
			font->draw(printonequeue,core::rect<s32>(48,150,48+50,250),video::SColor(255,255,255,255));
			font->draw(printtwoqueue,core::rect<s32>(48+800,150,48+800+50,250),video::SColor(255,255,255,255));
			
			irrscreen->endScene();

			int fps = irrscreen->driver->getFPS();
			core::stringw str = L"Celluria - FPS:";
			str += irrscreen->driver->getFPS();
			irrscreen->device->setWindowCaption(str.c_str());

		}
		sd.state = DEAD;
	}
}
return 0;

}