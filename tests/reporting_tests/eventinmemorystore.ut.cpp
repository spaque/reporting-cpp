#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <thread>

#include <eventinmemorystore.ut.cpp>

using namespace reporting;
using namespace testing;

namespace {

void checkWrittenEvents(const EventInMemoryStore& store, size_t expected)
{
    ASSERT_EQ(expected, store.getNumWrittenEvents());
}

}

class eventinmemorystore_tests : public ::testing::Test
{
    protected:
        eventinmemorystore_tests() {}
};

TEST_F(eventinmemorystor_tests, breathing)
{
    EventInMemoryStore store;

    ASSERT_EQ(0, store.getNumWrittenEvents());
    ASSERT_TRUE(store.removeAllEvents().empty());
}

TEST_F(eventinmemorystor_tests, write)
{
    EventInMemoryStore store;

    Event evt("test", "https://test.com", 0);
    store.write(evt);

    std::thread t1(checkWrittenEvents, std::cref(store), 1);
    ASSERT_EQ(1, store.getNumWrittenEvents());
    t1.join();

    ASSERT_EQ(1, store.removeAllEvents().size());
    ASSERT_EQ(0, store.removeAllEvents().size());
}

