#pragma once


class ISubscriber {
    public:
        virtual ~ISubscriber(){};
        virtual void receive_event(Event e) = 0;
};
