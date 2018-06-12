#ifndef USUARIOFACTORY_H
#define USUARIOFACTORY_H

#include <iostream>
#include "UsuarioController.h"
#include "IUsuarioController.h"

class UsuarioFactory
{
    private:
        static UsuarioFactory* instancia;
        UsuarioFactory();

    public:
        static UsuarioFactory* getInstancia();
        IUsuarioController* getIUsuarioController();
        ~UsuarioFactory();
};

#endif // USUARIOFACTORY_H
