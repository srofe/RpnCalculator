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

class PublisherObserverTests : public testing::Test {
public:
    MockPublisher sut;
};

TEST(Observer, ObserverHasName) {
    MockObserver mockObserver("observer");
    ASSERT_EQ(mockObserver.name(), "observer") << "An Observer shall have a name.";
}

TEST_F(PublisherObserverTests, RegisterSingleEventAddsEvent) {
    sut.registerEvent("FirstEvent");
    ASSERT_EQ(sut.eventNames().front(), "FirstEvent") << "Registering a single event shall add the event.";
}

TEST_F(PublisherObserverTests, RegisterSameEventTwiceDoesNotAddSecondEvent) {
    sut.registerEvent("FirstEvent");
    sut.registerEvent("FirstEvent");
    ASSERT_EQ(sut.eventNames().size(), 1) << "A Publisher shall not allow duplicate event names.";
}

TEST_F(PublisherObserverTests, RegisterTwoEventsAddsTwoEvents) {
    sut.registerEvent("FirstEvent");
    sut.registerEvent("SecondEvent");
    ASSERT_EQ(sut.eventNames().size(), 2) << "Registering multiple events shall add multiple events.";
    ASSERT_EQ(sut.eventNames().front(), "FirstEvent");
    ASSERT_EQ(sut.eventNames().back(), "SecondEvent");
}

TEST_F(PublisherObserverTests, AttachingSubscriberToPublisherIncrementsSubscriberCount) {
    MockObserver mockObserver { "observer" };
    sut.attach(&mockObserver);
    ASSERT_EQ(sut.observerCount(), 1) << "Attaching an Observer to a Publisher shall increase the observers count by one.";
}

TEST_F(PublisherObserverTests, DetatchingSubscribberDecrementsSubscriberCount) {
    MockObserver mockObserver1 { "observer1" };
    MockObserver mockObserver2 { "observer2" };
    sut.attach(&mockObserver1);
    sut.attach(&mockObserver2);
    ASSERT_EQ(sut.observerCount(), 2) << "Confirm there are two observers attached.";
    sut.detach("observer2");
    ASSERT_EQ(sut.observerCount(), 1) << "Detaching an Observer from a Publisher shall decrease the observers count by one.";
}

TEST_F(PublisherObserverTests, DetatchingUnknownObserverThrowsException) {
    ASSERT_ANY_THROW(sut.detach("observer")) << "Attempting to detach an Observer that has not been attached to a Publisher shall throw an exception.";
}

TEST_F(PublisherObserverTests, CallingPublisherNotifyUpdatesAllObservers) {
    MockObserver mockObserver1 { "Observer1" };
    MockObserver mockObserver2 { "Observer2" };
    sut.attach(&mockObserver1);
    sut.attach(&mockObserver2);
    sut.notify();
    ASSERT_TRUE(mockObserver1.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer1.";
    ASSERT_TRUE(mockObserver2.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer2.";
}
