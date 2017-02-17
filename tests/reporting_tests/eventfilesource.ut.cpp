#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <eventfiledump.h>
#include <eventfilesource.h>

#include <cstdio>

using namespace reporting;
using namespace testing;

namespace {

const char TEMP_FILENAME[] = "test.txt";

}

class eventfilesource_tests : public ::testing::Test
{
protected:
    eventfilesource_tests() {}
    ~eventfilesource_tests()
    {
        remove(TEMP_FILENAME);
    }
};

TEST_F(eventfilesource_tests, creation)
{
    EventFileSource source("xyz.txt");

    ASSERT_FALSE(source.isValid());
}

TEST_F(eventfilesource_tests, empty)
{
    {
        EventFileDump dump(TEMP_FILENAME);
    }
    EventFileSource source(TEMP_FILENAME);

    ASSERT_TRUE(source.isValid());

    Event evt;
    ASSERT_FALSE(source.readEvent(evt));
    ASSERT_FALSE(source.isValid());
}

TEST_F(eventfilesource_tests, invalidDevice)
{
    {
        std::ofstream stream(TEMP_FILENAME);
        stream << "test line\n";
        stream.close();
    }
    EventFileSource source(TEMP_FILENAME);

    ASSERT_TRUE(source.isValid());

    Event evt("test", "http://test.com/test", 0);
    ASSERT_FALSE(source.readEvent(evt));
    ASSERT_TRUE(source.isValid());

    ASSERT_STREQ("test", evt.device().c_str());
    ASSERT_STREQ("http://test.com/test", evt.url().c_str());
    ASSERT_EQ(0, evt.timestamp());

    ASSERT_FALSE(source.readEvent(evt));
    ASSERT_FALSE(source.isValid());
}

TEST_F(eventfilesource_tests, invalidTimestamp)
{
    {
        std::ofstream stream(TEMP_FILENAME);
        stream << "device: 7a-d7-09-2b-f2-b7\n"
               << "url: https://test.com\n"
               << "timestamp: abc";
        stream.close();
    }
    EventFileSource source(TEMP_FILENAME);

    ASSERT_TRUE(source.isValid());

    Event evt("test", "http://test.com/test", 0);
    ASSERT_FALSE(source.readEvent(evt));
    // No newline after timestamp, so the source should become invalid
    ASSERT_FALSE(source.isValid());

    ASSERT_STREQ("test", evt.device().c_str());
    ASSERT_STREQ("http://test.com/test", evt.url().c_str());
    ASSERT_EQ(0, evt.timestamp());
}

TEST_F(eventfilesource_tests, valid)
{
    {
        EventFileDump dump(TEMP_FILENAME);
        dump.onEvent(Event("test", "http://test.com/test", 0));
    }
    EventFileSource source(TEMP_FILENAME);

    ASSERT_TRUE(source.isValid());

    Event evt;
    ASSERT_TRUE(source.readEvent(evt));
    ASSERT_TRUE(source.isValid());

    ASSERT_STREQ("test", evt.device().c_str());
    ASSERT_STREQ("http://test.com/test", evt.url().c_str());
    ASSERT_EQ(0, evt.timestamp());

    ASSERT_FALSE(source.readEvent(evt));
    ASSERT_FALSE(source.isValid());
}
