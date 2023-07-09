#include <gmock/gmock.h>
#include <Publisher.h>
#include <Observer.h>

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

const std::string observerName = "Observer";
const std::string observerOne = "ObserverOne";
const std::string observerTwo = "ObserverTwo";
const std::string firstEvent = "FirstEvent";
const std::string secondEvent = "SecondEvent";

class PublisherObserverTests : public testing::Test {
public:
    MockPublisher sut;

protected:
    void SetUp() override {
        sut.registerEvent(firstEvent);
    }
};

TEST(Observer, ObserverHasName) {
    MockObserver mockObserver(observerName);
    ASSERT_EQ(mockObserver.name(), observerName) << "An Observer shall have a name.";
}

TEST_F(PublisherObserverTests, RegisterSingleEventAddsEvent) {
    ASSERT_EQ(sut.eventNames().front(), firstEvent) << "Registering a single event shall add the event.";
}

TEST_F(PublisherObserverTests, RegisterSameEventTwiceDoesNotAddSecondEvent) {
    sut.registerEvent(firstEvent);
    ASSERT_EQ(sut.eventNames().size(), 1) << "A Publisher shall not allow duplicate event names.";
}

TEST_F(PublisherObserverTests, RegisterTwoEventsAddsTwoEvents) {
    sut.registerEvent(secondEvent);
    ASSERT_EQ(sut.eventNames().size(), 2) << "Registering multiple events shall add multiple events.";
    ASSERT_EQ(sut.eventNames().front(), firstEvent) << "Registering an event shall provide an event name";
    ASSERT_EQ(sut.eventNames().back(), secondEvent) << "Registering an event shall provide an event name";
}

TEST_F(PublisherObserverTests, AttachingObserverToPublisherIncrementsObserverCount) {
    MockObserver mockObserver { observerName };
    sut.attach(firstEvent, &mockObserver);
    ASSERT_EQ(sut.eventObserverCount(firstEvent), 1) << "Attaching an Observer to a Publisher shall increase the observers count by one.";
}

TEST_F(PublisherObserverTests, DetatchingObserverDecrementsObserverCount) {
    MockObserver mockObserver1 { observerOne };
    MockObserver mockObserver2 { observerTwo };
    sut.attach(firstEvent, &mockObserver1);
    sut.attach(firstEvent, &mockObserver2);
    ASSERT_EQ(sut.eventObserverCount(firstEvent), 2) << "Confirm there are two observers attached.";
    sut.detach(firstEvent, observerTwo);
    ASSERT_EQ(sut.eventObserverCount(firstEvent), 1) << "Detaching an Observer from a Publisher shall decrease the observers count by one.";
}

TEST_F(PublisherObserverTests, DetatchingUnknownObserverThrowsException) {
    ASSERT_THROW(sut.detach(observerName, firstEvent), Exception) << "Attempting to detach an Observer that has not been attached to a Publisher shall throw an exception of type 'Exception'.";
}

TEST_F(PublisherObserverTests, CallingPublisherNotifyUpdatesAllObservers) {
    MockObserver mockObserver1 { observerOne };
    MockObserver mockObserver2 { observerTwo };
    sut.attach(firstEvent, &mockObserver1);
    sut.attach(firstEvent, &mockObserver2);
    sut.notify(firstEvent);
    ASSERT_TRUE(mockObserver1.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer1.";
    ASSERT_TRUE(mockObserver2.updateCalled) << "The Publisher notify() method shall notify an Observer by calling its update() method - observer2.";
}
