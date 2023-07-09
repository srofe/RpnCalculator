#pragma once

#include <Observer.h>
#include <Publisher.h>

class MockPublisher : public Publisher {
public:
    using Publisher::notify;
    inline size_t eventObserverCount(const std::string &eventName) { return events[eventName].size(); }
};

class MockObserver : public  Observer {
    void update(const EventData &eventData) override { updateCalled = true; }
public:
    explicit MockObserver(std::string_view name);
    bool updateCalled = false;
};

MockObserver::MockObserver(std::string_view name) : Observer(name) {}
