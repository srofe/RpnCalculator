#pragma once

#include <string>
#include <any>

using EventData = std::any;

class Observer {
public:
    explicit Observer(std::string_view name);
    virtual ~Observer() = default;
    virtual void update(const EventData &eventData) = 0;
    inline const std::string name() const { return  observerName; }

private:
    std::string observerName;
};
