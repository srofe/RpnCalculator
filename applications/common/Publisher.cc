#include <Publisher.h>

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
    for (const auto &event : events) {
        eventNames.push_back(event.first);
    }
    return eventNames;
}

void Publisher::notify(const std::string &eventName, const EventData& eventData) {
    for (auto observer : events[eventName]) {
        observer->update(eventData);
    }
}
