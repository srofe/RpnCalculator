#pragma once

#include <any>

using EventData = std::any;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const EventData &eventData) = 0;
};
