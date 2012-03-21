#include "cell/transport/walker.hh"

namespace game{
  void WalkerProducer::addConsumer(WalkerConsumer *consumer,Route route){
    size_type size=this->routes.count(consumer);
    this->routes.insert(pair<WalkerConsumer*,Route>(consumer,route);
    if(size==0){
      const set<Resource> accepts=consumer->getResourcesConsumed();
      for(set<Resource>::const_iterator it=accepts.begin();it!=accept.end();++it){
        this->consumers.insert(pair<Resource,WalkerConsumer*>(*it,consumer)
        this->active.insert(pair<pair<Resource,WalkerConsumer*>,bool>(pair<Resource,WalkerConsumer*>(*it,consumer),true);
      }
    }
  }
  const set<Route> WalkerProducer::getRoutes(WalkerConsumer *consumer){
    return set<Route>(this->routes.lower_bound(*consumer),this->routes.upper_bound(*consumer));
  }
  void WalkerProducer::updateState(WalkerConsumer *consumer,Resource resource,bool state){
    this->accept.insert(pair(pair(resource,consumer),state));
  }
  const set<WalkerConsumer*> WalkerProducer::getConsumers(Resource resource){
    return set<WalkerConsumer*>(this->consumers.lower_bound(resource),this->consumers.upper_bound(resource));
  }
  
  void WalkerConsumer::addProducer(WalkerProducer *producer){
    this->producers.insert(producer)
  }
  void WalkerConsumer::updateState(Resource resource,bool state){
    for(set<WalkerProducer*>::const_iterator it=this->producers.begin();it!=this->producers.end();++it){
      (*it)->updateState(this,resource,state);
    }
  }
  
}