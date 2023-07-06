#pragma once

#include <list>
#include <Observer.h>
#include <Exception.h>

using ObserverList = std::list<Observer*>;

class Publisher {
public:
    void attach(Observer *observer);
    void detach(const std::string &name);
    void registerEvent(const std::string &eventName);
    std::list<std::string> eventNames() const;

protected:
    ObserverList observers;
    std::map<std::string, ObserverList> events;
    void notify();
};

void Publisher::attach(Observer *observer) {
    observers.push_back(observer);
}

void Publisher::detach(const std::string &name) {
    auto toDelete = std::find_if(
            observers.begin(),
            observers.end(),
            [name](Observer *item) { return item->name() == name;}
            );
    if (toDelete == observers.end()) {
        throw Exception("Cannot detach Observer: Unknown observer name.");
    }
    observers.erase(toDelete);
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

void Publisher::notify() {
    for (auto observer : observers) {
        observer->update(EventData());
    }
}
