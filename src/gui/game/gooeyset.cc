#include "gooeyset.hh"

namespace game {
	GooeySet::GooeySet() {
		active = -1;
	}
	
	void GooeySet::addGooey(Gooey* ggooey) {
		set.push_back(ggooey);
	}
	
	void GooeySet::changeToGooey(int cto) {
		active = cto;
	}
	
	Gooey* GooeySet::getCurrent() {
		return set.at(active);
	}
	
	void GooeySet::load() {
		for (vector<Gooey*>::iterator it = set.begin(); it != set.end(); it++) {
			(*it)->load();
		}
	}
	
	void GooeySet::update() {
		for (vector<Gooey*>::iterator it = set.begin(); it != set.end(); it++) {
			(*it)->update();
		}
	}
	
	void GooeySet::draw() {
		set.at(active)->draw();
	}
	
	void GooeySet::clickNoise(core::position2d<s32> noise) {
		set.at(active)->clickNoise(noise);
	}
	
	void GooeySet::moveNoise(core::position2d<s32> noise) {
		set.at(active)->moveNoise(noise);
	}
}