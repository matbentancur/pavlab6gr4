#ifndef CONVERSACIONFACTORY_H
#define CONVERSACIONFACTORY_H

#include <iostream>
#include "ConversacionController.h"
#include "IConversacionController.h"

class ConversacionFactory {
    private:
        static ConversacionFactory* instancia;
        ConversacionFactory();

    public:
        static ConversacionFactory* getInstancia();
        IConversacionController* getIConversacionController();
        ~ConversacionFactory();
};

#endif // CONVERSACIONFACTORY_H
