//
// Created by Utilizador on 27-Dec-22.
//

#ifndef AIRTRANSPORT_MENU_H
#define AIRTRANSPORT_MENU_H
#include "Database.h"
#include <stdlib.h>
///Classe para o Menu.
///
///Um menu apenas apresenta as opcoes.
class Menu {
private:
    Database database;
public:
    Menu();
    void run();
};


#endif //AIRTRANSPORT_MENU_H
