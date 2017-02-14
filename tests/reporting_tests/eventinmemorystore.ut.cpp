#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <thread>

#include <eventinmemorystore.h>

using namespace reporting;
using namespace testing;

class eventinmemorystore_tests : public ::testing::Test
{
    protected:
        eventinmemorystore_tests() {}
};

TEST_F(eventinmemorystore_tests, breathing)
{
    EventInMemoryStore store;

    ASSERT_EQ(0, store.getNumWrittenEvents());
    ASSERT_TRUE(store.removeAllEvents().empty());
}

TEST_F(eventinmemorystore_tests, write)
{
    EventInMemoryStore store;

    Event evt("test", "https://test.com", 0);
    store.writeEvent(evt);

    std::thread t1([&store]() {
        ASSERT_EQ(1, store.getNumWrittenEvents());
    });

    ASSERT_EQ(1, store.getNumWrittenEvents());
    t1.join();

    ASSERT_EQ(1, store.removeAllEvents().size());
    ASSERT_EQ(0, store.removeAllEvents().size());
}

