#include <gmock/gmock.h>

using EventData = std::any;

class Observer {
public:
    virtual void update(const EventData &eventData) = 0;
};

class TestObserver : public  Observer {
public:
    double data = 0.0;
    void update(const EventData &data) override;
    double getData() const;
};

void TestObserver::update(const EventData &eventData) {
    this->data = std::any_cast<double>(data);
}

double TestObserver::getData() const {
    return this->data;
}

TEST(Observer, InitialFailingTest) {
    TestObserver testObserver;
    testObserver.update(34.2);

    ASSERT_EQ(testObserver.getData(), 34.2) << "An Observer shall allow double data types to be passed to the update() method.";
}
