#pragma once

#include <list>
#include <Observer.h>

class Exception : std::exception {
public:
    explicit Exception(const std::string message) : exceptionMessage(message) {}
    explicit Exception(const char* message) : exceptionMessage(message) {}
    ~Exception() noexcept override = default;
    const char * what() const noexcept override { return exceptionMessage.c_str(); }

private:
    std::string exceptionMessage;
};

class Publisher {
public:
    void attach(Observer *observer);
    void detach(const std::string &name);

protected:
    std::list<Observer*> observers;
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
