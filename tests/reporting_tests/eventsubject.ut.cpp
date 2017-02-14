#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <reporting_mocks.h>
#include <eventsubject.h>

using namespace reporting;
using namespace testing;

class eventsubject_tests : public ::testing::Test
{
    protected:
        eventsubject_tests() {}
};

TEST_F(eventsubject_tests, breathing)
{
    EventSubject subject;
}

TEST_F(eventsubject_tests, notify)
{
    EventSubject subject;

    MockEventObserver* observer_p = new MockEventObserver();
    IEventObserverPtr observer_sp(observer_p);
    subject.registerObserver(observer_sp);

    Event evt("test", "http://test.com", 0);

    EXPECT_CALL(*observer_p, onEvent(evt)).Times(1);

    subject.notify(evt);
}

