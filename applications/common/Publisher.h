#pragma once

#include <list>
#include <map>
#include <Observer.h>
#include <Exception.h>

using ObserverList = std::list<Observer*>;
using EventMap = std::map<std::string, ObserverList>;

class Publisher {
public:
    void attach(const std::string &eventName, Observer *observer);
    void detach(const std::string &eventName, const std::string &name);
    void registerEvent(const std::string &eventName);
    std::list<std::string> eventNames() const;

protected:
    EventMap events;
    void notify(const std::string &eventName, const EventData& eventData);
};
