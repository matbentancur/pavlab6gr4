#include "UsuarioFactory.h"

UsuarioFactory* UsuarioFactory::instancia = NULL;

UsuarioFactory::UsuarioFactory(){}

UsuarioFactory* UsuarioFactory::getInstancia(){
    if (instancia == NULL)
        instancia = new UsuarioFactory();
    return instancia;
}

IUsuarioController* UsuarioFactory::getIUsuarioController(){
    IUsuarioController* c = new UsuarioController();
    return c;
}

UsuarioFactory::~UsuarioFactory(){}
