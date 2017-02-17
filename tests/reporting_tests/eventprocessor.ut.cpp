#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <reporting_mocks.h>

#include <eventprocessor.h>

using namespace reporting;
using namespace testing;

class eventprocessor_tests : public ::testing::Test
{
    protected:
        eventprocessor_tests() {}
};

TEST_F(eventprocessor_tests, sourceExit)
{
    MockEventSource* source_p = new MockEventSource();
    IEventSourcePtr source_sp(source_p);
    MockEventTarget* target_p = new MockEventTarget();
    IEventTargetPtr target_sp(target_p);
    MockEventFilter* filter_p = new MockEventFilter();
    IEventFilterPtr filter_sp(filter_p);

    EventProcessor proc(source_sp, target_sp, filter_sp);

    Event evt("test", "http://test.com/", 0);
    EXPECT_CALL(*source_p, readEvent(_))
        .WillOnce(DoAll(SetArgReferee<0>(evt), Return(true)))
        .WillOnce(Return(false));
    EXPECT_CALL(*filter_p, filter(evt)).WillOnce(Return(false));
    EXPECT_CALL(*target_p, writeEvent(evt)).WillOnce(Return(true));
    EXPECT_CALL(*source_p, ack(true)).WillOnce(Return(true));

    proc.start();
}

TEST_F(eventprocessor_tests, targetExit)
{
    MockEventSource* source_p = new MockEventSource();
    IEventSourcePtr source_sp(source_p);
    MockEventTarget* target_p = new MockEventTarget();
    IEventTargetPtr target_sp(target_p);
    MockEventFilter* filter_p = new MockEventFilter();
    IEventFilterPtr filter_sp(filter_p);

    EventProcessor proc(source_sp, target_sp, filter_sp);

    Event evt("test", "http://test.com/", 0);
    EXPECT_CALL(*source_p, readEvent(_)).WillOnce(DoAll(SetArgReferee<0>(evt), Return(true)));
    EXPECT_CALL(*filter_p, filter(evt)).WillOnce(Return(false));
    EXPECT_CALL(*target_p, writeEvent(evt)).WillOnce(Return(false));
    EXPECT_CALL(*source_p, ack(false)).WillOnce(Return(true));

    proc.start();
}

TEST_F(eventprocessor_tests, ackExit)
{
    MockEventSource* source_p = new MockEventSource();
    IEventSourcePtr source_sp(source_p);
    MockEventTarget* target_p = new MockEventTarget();
    IEventTargetPtr target_sp(target_p);
    MockEventFilter* filter_p = new MockEventFilter();
    IEventFilterPtr filter_sp(filter_p);

    EventProcessor proc(source_sp, target_sp, filter_sp);

    Event evt("test", "http://test.com/", 0);
    EXPECT_CALL(*source_p, readEvent(_))
        .WillOnce(DoAll(SetArgReferee<0>(evt), Return(true)));
    EXPECT_CALL(*filter_p, filter(evt)).WillOnce(Return(false));
    EXPECT_CALL(*target_p, writeEvent(evt)).WillOnce(Return(true));
    EXPECT_CALL(*source_p, ack(true)).WillOnce(Return(false));

    proc.start();
}

TEST_F(eventprocessor_tests, filter)
{
    MockEventSource* source_p = new MockEventSource();
    IEventSourcePtr source_sp(source_p);
    MockEventTarget* target_p = new MockEventTarget();
    IEventTargetPtr target_sp(target_p);
    MockEventFilter* filter_p = new MockEventFilter();
    IEventFilterPtr filter_sp(filter_p);

    EventProcessor proc(source_sp, target_sp, filter_sp);

    Event evt("test", "http://test.com/", 0);
    EXPECT_CALL(*source_p, readEvent(_))
        .WillOnce(DoAll(SetArgReferee<0>(evt), Return(true)))
        .WillOnce(Return(false));
    EXPECT_CALL(*filter_p, filter(evt)).WillOnce(Return(true));
    EXPECT_CALL(*target_p, writeEvent(_)).Times(0);
    EXPECT_CALL(*source_p, ack(_)).Times(0);

    proc.start();
}

