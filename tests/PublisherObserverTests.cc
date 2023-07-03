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
};

TEST(PublisherObserver, AttachingSubscriberToPublisherIncrementsSubscriberCount) {
    MockObserver mockObserver;
    MockPublisher mockPublisher;

    mockPublisher.attach(&mockObserver);

    ASSERT_EQ(mockPublisher.observerCount(), 1) << "Attaching an Observer to a Publisher shall increase the observers count by one.";
}
