#include <gmock/gmock.h>
#include <Publisher.h>
#include <Observer.h>

class MockPublisher : public Publisher {
public:
    size_t observerCount();
};

size_t MockPublisher::observerCount() {
    return observers.size();
}

class MockObserver : public  Observer {
    void update(const EventData &eventData) override {}
public:
    explicit MockObserver(std::string_view name);
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
    ASSERT_EQ(mockPublisher.observerCount(), 2);
    mockPublisher.detach("observer2");

    ASSERT_EQ(mockPublisher.observerCount(), 1) << "Detaching an Observer from a Publisher shall decrease the observers count by one.";
}

TEST(PublisherObserver, DetatchingUnknownObserverThrowsException) {
    MockPublisher mockPublisher;
    ASSERT_ANY_THROW(mockPublisher.detach("observer"));
}
