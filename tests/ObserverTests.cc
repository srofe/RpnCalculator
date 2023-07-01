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
    data = std::any_cast<double>(eventData);
}

double TestObserver::getData() const {
    return this->data;
}

TEST(Observer, TestDoubleObserverConvertsDoubleFromUpdate) {
    TestObserver testObserver;
    testObserver.update(34.2);

    ASSERT_EQ(testObserver.getData(), 34.2) << "A concrete Observer of double shall convert the value passed to update() to a double.";
}
