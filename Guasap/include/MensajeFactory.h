#ifndef MENSAJEFACTORY_H_INCLUDED
#define MENSAJEFACTORY_H_INCLUDED

#include <iostream>
#include "IMensajeController.h"
#include "MensajeController.h"

class MensajeFactory{

    private:
        static MensajeFactory* instancia;
        MensajeFactory();

    public:
        static MensajeFactory* getInstancia();
        IMensajeController* getIMensajeController();
        ~MensajeFactory();
};

#endif // MENSAJEFACTORY_H_INCLUDED
