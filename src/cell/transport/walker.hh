#include "resource.hh"
#include <set>
#include <map>
#include <multimap>

#ifndef CELL_TRANSPORT_WALKER
#define CELL_TRANSPORT_WALKER

typedef int Route;

namespace game{

  class WalkerConsumer;

  class WalkerProducer{
    private:
      multimap<WalkerConsumer*,Route> routes;
      multimap<Resource,WalkerConsumer*> consumers;
      map<pair<Resource,WalkerConsumer*>,bool> active;
    public:
      void addConsumer(WalkerConsumer *consumer,Route route);
      const set<Route> getRoutes(WalkerConsumer *consumer);
      void updateState(WalkerConsumer *consumer,Resource resource,bool state);
      const set<WalkerConsumer*> getConsumers(Resource resource);
  }

  class WalkerConsumer{
    private:
      set<WalkerProducer*> producers;
    public:
      virtual const set<Resource> getResourcesConsumed()=0;
      void addProducer(WalkerProducer *producer);
      void updateState(Resource resource,bool state);
      virtual Quantity provideResource(Resource resource,Quantity resource)=0;
      virtual void recieveResource(Resource resource,bool success)=0;
  }

}

#endif