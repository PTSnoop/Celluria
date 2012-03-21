#include "cell/transport/walker.hh"

namespace game{

  using namespace std;
  
  void WalkerProducer::addConsumer(WalkerConsumer *consumer,Route route){
    size_t size=this->routes.count(consumer);
    this->routes.insert(pair<WalkerConsumer*,Route>(consumer,route));
    if(size==0){
      const set<Resource> accepts=consumer->getResourcesConsumed();
      for(set<Resource>::const_iterator it=accepts.begin();it!=accepts.end();++it){
        this->consumers.insert(pair<Resource,WalkerConsumer*>(*it,consumer));
        this->active.insert(pair<pair<Resource,WalkerConsumer*>,bool>(pair<Resource,WalkerConsumer*>(*it,consumer),true));
      }
    }
  }
  const set<Route> WalkerProducer::getRoutes(WalkerConsumer *consumer){
    set<Route> set;
    for(multimap<WalkerConsumer*,Route>::const_iterator it=this->routes.lower_bound(consumer);it!=this->routes.upper_bound(consumer);++it)
      set.insert(it->second);
    return set;
  }
  void WalkerProducer::updateState(WalkerConsumer *consumer,Resource resource,bool state){
    this->active.insert(pair<pair<Resource,WalkerConsumer*>,bool>(pair<Resource,WalkerConsumer*>(resource,consumer),state));
  }
  const set<WalkerConsumer*> WalkerProducer::getConsumers(Resource resource){
    set<WalkerConsumer*> set;
    for(multimap<Resource,WalkerConsumer*>::const_iterator it=this->consumers.lower_bound(resource);it!=this->consumers.upper_bound(resource);++it)
      set.insert(it->second);
    return set;
  }
  
  void WalkerConsumer::addProducer(WalkerProducer *producer){
    this->producers.insert(producer);
  }
  void WalkerConsumer::updateState(Resource resource,bool state){
    for(set<WalkerProducer*>::const_iterator it=this->producers.begin();it!=this->producers.end();++it){
      (*it)->updateState(this,resource,state);
    }
  }
  
}