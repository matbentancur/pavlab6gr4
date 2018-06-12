#include "ConversacionFactory.h"

ConversacionFactory* ConversacionFactory::instancia = NULL;

ConversacionFactory::ConversacionFactory(){}

ConversacionFactory* ConversacionFactory::getInstancia(){
    if (instancia == NULL)
        instancia = new ConversacionFactory();
    return instancia;
}

IConversacionController* ConversacionFactory::getIConversacionController(){
    IConversacionController* c = new ConversacionController();
    return c;
}

ConversacionFactory::~ConversacionFactory(){}
