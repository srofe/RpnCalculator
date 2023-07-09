#pragma once

#include <list>
#include <Observer.h>
#include <Exception.h>

using ObserverList = std::list<Observer*>;
using EventMap = std::map<std::string, ObserverList>;

class Publisher {
public:
    void attach(Observer *observer, const std::string &eventName = "");
    void detach(const std::string &name, const std::string &eventName = "");
    void registerEvent(const std::string &eventName);
    std::list<std::string> eventNames() const;

protected:
    EventMap events;
    void notify(const std::string &eventName);
};

void Publisher::attach(Observer *observer, const std::string &eventName) {
    events[eventName].push_back(observer);
}

void Publisher::detach(const std::string &name, const std::string &eventName) {
    auto toDelete = std::find_if(
            events[eventName].begin(),
            events[eventName].end(),
            [name](Observer *item) { return item->name() == name; }
    );
    if (toDelete == events[eventName].end()) {
        throw Exception("Cannot detach Observer: Unknown observer name.");
    }
    events[eventName].erase(toDelete);
}

void Publisher::registerEvent(const std::string &eventName) {
    events.insert({eventName, ObserverList {} });
}

std::list<std::string> Publisher::eventNames() const {
    std::list<std::string> eventNames;
    for ( auto event : events) {
        eventNames.push_back(event.first);
    }
    return eventNames;
}

void Publisher::notify(const std::string &eventName) {
    for (auto observer : events[eventName]) {
        observer->update(EventData());
    }
}
