#include "resource.hh"
#include <set>
#include <map>
#include <functional>

#ifndef CELL_TRANSPORT_WALKER
#define CELL_TRANSPORT_WALKER

typedef int Route;

namespace game{
  
  using namespace std;

  class WalkerConsumer;
  
  struct pairsort{
    less<WalkerConsumer*> l1;
    less<Resource> l2;
    bool operator()(const pair<Resource,WalkerConsumer*> p1,const pair<Resource,WalkerConsumer*> p2){
      if(p1.first==p2.first)
        return l1(p1.second,p2.second);
      else
        return l2(p1.first,p2.first);
    }
  };

  class WalkerProducer{
    private:
      multimap<WalkerConsumer*,Route> routes;
      multimap<Resource,WalkerConsumer*> consumers;
      map<pair<Resource,WalkerConsumer*>,bool,pairsort> active;
    public:
      void addConsumer(WalkerConsumer *consumer,Route route);
      const set<Route> getRoutes(WalkerConsumer *consumer);
      void updateState(WalkerConsumer *consumer,Resource resource,bool state);
      const set<WalkerConsumer*> getConsumers(Resource resource);
  };

  class WalkerConsumer{
    private:
      set<WalkerProducer*> producers;
    public:
      virtual const set<Resource> getResourcesConsumed()=0;
      void addProducer(WalkerProducer *producer);
      void updateState(Resource resource,bool state);
      virtual Quantity provideResource(Resource resource,Quantity quantity)=0;
      virtual void recieveResource(Resource resource,bool success)=0;
  };

}

#endif