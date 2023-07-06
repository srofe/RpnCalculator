#include <gmock/gmock.h>
#include <Publisher.h>
#include <Observer.h>

class MockPublisher : public Publisher {
public:
    using Publisher::notify;
    inline size_t observerCount() { return observers.size(); }
};

class MockObserver : public  Observer {
    void update(const EventData &eventData) override { updateCalled = true; }
public:
    explicit MockObserver(std::string_view name);
    bool updateCalled = false;
};

MockObserver::MockObserver(std::string_view name) : Observer(name) {}

TEST(Observer, ObserverHasName) {
    MockObserver mockObserver("observer");
    ASSERT_EQ(mockObserver.name(), "observer") << "An Observer shall have a name.";
}

TEST(PublisherObserver, AttachingSubscriberToPublisherIncrementsSubscriberCount) {
    MockObserver mockObserver { "observer" };
    MockPublisher mockPublisher;

    mockPublisher.attach(&mockObserver);

    ASSERT_EQ(mockPublisher.observerCount(), 1) << "Attaching an Observer to a Publisher shall increase the observers count by one.";
}

TEST(PublisherObserver, DetatchingSubscribberDecrementsSubscriberCount) {
    MockObserver mockObserver1 { "observer1" };
    MockObserver mockObserver2 { "observer2" };
    MockPublisher mockPublisher;

    mockPublisher.attach(&mockObserver1);
    mockPublisher.attach(&mockObserver2);
    ASSERT_EQ(mockPublisher.observerCount(), 2) << "Confirm there are two observers attached.";
    mockPublisher.detach("observer2");

    ASSERT_EQ(mockPublisher.observerCount(), 1) << "Detaching an Observer from a Publisher shall decrease the observers count by one.";
}

TEST(PublisherObserver, DetatchingUnknownObserverThrowsException) {
    MockPublisher mockPublisher;
    ASSERT_ANY_THROW(mockPublisher.detach("observer")) << "Attempting to detach an Observer that has not been attached to a Publisher shall throw an exception.";
}

TEST(PublisherObserver, CallingPublisherNotifyUpdatesAllObservers) {
    MockObserver mockObserver1 { "Observer1" };
    MockObserver mockObserver2 { "Observer2" };
    MockPublisher mockPublisher;
    mockPublisher.attach(&mockObserver1);
    mockPublisher.attach(&mockObserver2);
    mockPublisher.notify();
    ASSERT_TRUE(mockObserver1.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer1.";
    ASSERT_TRUE(mockObserver2.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer2.";
}
