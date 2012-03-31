#include "main.hh"
#include <vector>
#include <cmath>
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

struct SharedData {
	vector<int> commandtrack1;
	vector<int> commandtrack2;
	bool loaded;
	bool connected;
	int now;
	int begin;
};

int main() {
	
	SharedData sd;
	sd.loaded = false;
	sd.connected = false;
	sd.now = 0;
	
	/*
#pragma omp parallel sections num_threads(2) shared(sd)
{
#pragma omp section
	{
		*/
		TD::Socket sock;
		char buffer [127];
		bool server;
		try {
			sd.now = 5;
			cout << "Trying to connect..." << endl;
			sock.connect("localhost", 6666);
			std::cout << "Connected to " << sock.getHostName() << std::endl;
			server = false;
		}
		catch(int e) {
			sd.now = 12;
			cout << "No connection, hosting instead" << endl;
			TD::Socket server;
			server.bind(6666);
			server.listen();		
			sock = server.accept();
			std::cout << "Connected to " << sock.getHostName() << std::endl;
			server.close();
			server = true;
		}
			
		sprintf(buffer,"%d",sd.now);
		sock.sendln(buffer);
		cout << sock.recv() << endl;
		sock.close();

		
		
		
		sd.connected = true;
		/*
		while (not sd.loaded)
			sleep(1);
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
		//cout << sd.begin << endl;
		
		//begin main loop!
		while (irrscreen->run()) {
			
			//run timer
			sd.now = irrscreen->device->getTimer()->getTime() - sd.begin;
			//cout << sd.now << endl;
			f32 dt = (f32)(sd.now - then) / 1000.f; // Time in seconds
			then = sd.now;
			int nowsec = sd.now/500;
			int nowdelta = 2*( sd.now % 500);
			if (nowsec > oldsec) {
				newround = true;
			}
			else {
				newround = false;
			}
			oldsec = nowsec;
			
			//RUN GAME SIM
			
			if (newround) {
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
					onequeue++;
					printf("PING\n");
				}
				lmwasdown = false;
			}
			
			if (irrscreen->receiver->IsKeyDown(KEY_SPACE)) {
				spacewasdown = true;
			}
			else {
				if (spacewasdown) {
					twoqueue++;
					printf("PANG\n");
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
	}
}

*/
return 0;

}