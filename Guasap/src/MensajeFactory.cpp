#include "MensajeFactory.h"

MensajeFactory* MensajeFactory::instancia = NULL;

MensajeFactory::MensajeFactory(){}

MensajeFactory* MensajeFactory::getInstancia(){
    if(instancia == NULL){
        instancia = new MensajeFactory();
    }
        return instancia;
}

IMensajeController* MensajeFactory::getIMensajeController(){
    IMensajeController* m = new MensajeController();

    return m;
}

MensajeFactory::~MensajeFactory(){}

