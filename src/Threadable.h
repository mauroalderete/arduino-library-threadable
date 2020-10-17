#ifndef _THREADABLE_HPP_
#define _THREADABLE_HPP_

#include <Arduino.h>

/**
* @breif Estados posibles de una instancia Threadable
* */
enum class ThreadableStatus{
    START,
    PAUSE,
    STOP
};

/**
* @brief Permite controlar la ejecuión de una clase derivada en su propio hilo
* */
class Threadable {
    protected:
        /**
        * @brief Almacena el intervalo en milisegundos antes de ejecutar Tick()
        * */
        unsigned long _interval;
        /**
        * @brief Cuenta el tiempo transcurrido desde la ultima ejecución de Tick()
        * */
        unsigned long _lapsed;
        /**
        * @brief Permite controlar el estado.
        * */
        ThreadableStatus _status;
        /**
        * @brief Metodo anulable que invoca el core de la instancia derivada.
        * */
        virtual void Tick();

    public:
        /**
        * @brief Inicializa contadores y variables de estado
        * */
        Threadable();
        ~Threadable();

        /**
        * @brief Permite configurar el intervalo entre ejecuciones de Tick()
        * */
        virtual void SetInterval(unsigned long interval);

        /**
        * @brief Inicia el conteo de intervalos
        * */
        virtual void Start();

        /**
        * @brief Congela el estado de los intervalos
        * */
        virtual void Pause();

        /**
        * @brief Continua la cuenta de intervalos desde la ultima iteracion
        * */
        virtual void Resume();

        /**
        * @brief Detiene e inicializa la cuenta de intervalos
        * */
        virtual void Stop();

        /**
        * @brief Comprueba la cuenta de intervalos, si se agota el tiempo invoca a Tick()
        * */
        virtual void Loop();
};

#endif