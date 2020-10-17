#include "Threadable.h"

Threadable::Threadable(){
    _interval = 0;
    _lapsed = 0;
    _status = ThreadableStatus::STOP;
}

Threadable::~Threadable(){
}

void Threadable::SetInterval(unsigned long interval){
    _interval = interval;
}

void Threadable::Start(){
    _status = ThreadableStatus::START;
    _lapsed = 0;
}

void Threadable::Pause(){
    _status = ThreadableStatus::PAUSE;
}

void Threadable::Resume(){
    _status = ThreadableStatus::START;
}

void Threadable::Stop(){
    _status = ThreadableStatus::STOP;
    _lapsed = 0;
}

void Threadable::Loop(){
    if( _status == ThreadableStatus::START ){
        unsigned long current = millis();
        if ( current - _lapsed >= _interval){
            _lapsed = current;
            Tick();
        }
    }
}

void Threadable::Tick(){

}