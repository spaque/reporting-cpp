#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <reporting_mocks.h>
#include <eventstoreprocessor.h>

#include <thread>

using namespace reporting;
using namespace testing;

class eventstoreprocessor_tests : public ::testing::Test
{
    protected:
        eventstoreprocessor_tests() {}
};

TEST_F(eventstoreprocessor_tests, breathing)
{
    MockEventStore* store_p = new MockEventStore();
    IEventStorePtr store_sp(store_p);

    MockEventSubject* subject_p = new MockEventSubject();
    IEventSubjectPtr subject_sp(subject_p);

    EventStoreProcessor proc(store_sp, subject_sp, 1);

    Event evt("test", "http://test.com", 0);
    std::vector<Event> events;
    events.push_back(evt);

    EXPECT_CALL(*store_p, removeAllEvents()).WillOnce(Return(events));
    EXPECT_CALL(*subject_p, notify(evt));

    std::thread t1(&EventStoreProcessor::start, &proc);
    t1.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    proc.shutdown();
}

