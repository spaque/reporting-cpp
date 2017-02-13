#pragma once

#include <gmock/gmock.h>

#include <ieventfilter.h>
#include <ieventobserver.h>
#include <ieventsource.h>
#include <ieventstore.h>
#include <ieventsubject.h>
#include <ieventtarget.h>

class MockEventFilter : public reporting::IEventFilter
{
    public:
        virtual ~MockEventFilter() {}

        MOCK_METHOD1(filter, bool(const reporting::Event&));
};

class MockEventObserver : public reporting::IEventObserver
{
    public:
        virtual ~MockEventObserver() {}

        MOCK_METHOD1(onEvent, void(const reporting::Event&));
};

class MockEventSource : public reporting::IEventSource
{
    public:
        virtual ~MockEventSource() {}

        MOCK_METHOD1(readEvent, bool(reporting::Event&));
        MOCK_METHOD1(ack, void(bool));
};

class MockEventStore : public reporting::IEventStore
{
    public:
        virtual ~MockEventStore() {}

        MOCK_METHOD1(write, bool(const reporting::Event&));
        MOCK_METHOD0(removeAllEvents, std::vector<reporting::Event>());
        MOCK_METHOD0(getNumWrittenEvents, size_t());
};

class MockEventSubject : public reporting::IEventSubject
{
    public:
        virtual ~MockEventSubject() {}

        MOCK_METHOD1(registerObserver, void(const reporting::IEventObserverPtr&));
        MOCK_METHOD1(notify, void(const reporting::Event&));
};

class MockEventTarget : public reporting::IEventTarget
{
    public:
        virtual ~MockEventTarget() {}

        MOCK_METHOD1(write, bool(const reporting::Event&));
        MOCK_METHOD0(getNumWrittenEvents, size_t());
};


