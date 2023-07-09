#pragma once

#include <list>
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
    void notify(const std::string &eventName);
};

void Publisher::attach(const std::string &eventName, Observer *observer) {
    events[eventName].push_back(observer);
}

void Publisher::detach(const std::string &eventName, const std::string &name) {
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
