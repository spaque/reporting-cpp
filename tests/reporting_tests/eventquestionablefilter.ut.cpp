#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <eventquestionablefilter.h>

using namespace reporting;
using namespace testing;

class eventquestionable_tests : public ::testing::Test
{
    protected:
        eventquestionable_tests() {}
};

TEST_F(eventquestionable_tests, positive)
{
    EventQuestionableFilter filter;
    Event evt("test", "http://test.com/test", 0);
    ASSERT_TRUE(filter.filter(evt));

    evt.url("http://test.com/xxx");
    ASSERT_TRUE(filter.filter(evt));
}

TEST_F(eventquestionable_tests, negative)
{
    EventQuestionableFilter filter;
    Event evt("test", "http://test.xxx/test", 0);
    ASSERT_FALSE(filter.filter(evt));

    evt.url("http://www.bieber.com/test");
    ASSERT_FALSE(filter.filter(evt));
}

