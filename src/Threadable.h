#ifndef _THREADABLE_HPP_
#define _THREADABLE_HPP_

#include <Arduino.h>

enum class ThreadableStatus{
    START,
    PAUSE,
    STOP
};

class Threadable {
    protected:
        unsigned long _interval;
        unsigned long _lapsed;
        ThreadableStatus _status;
        virtual void Tick();

    public:
        Threadable();
        ~Threadable();

        virtual void SetInterval(unsigned long interval);
        virtual void Start();
        virtual void Pause();
        virtual void Resume();
        virtual void Stop();
        virtual void Loop();
};

#endif