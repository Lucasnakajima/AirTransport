//
// Created by Utilizador on 27-Dec-22.
//

#include "Menu.h"

Menu::Menu() {
run();
}

void Menu::run() {
    while(true){
        cout << "MENU\n" << "1- Distance between two places \n" << "2- Exit\n" << "Choose an option: ";
        int n;
        cin >> n;
        switch(n){
            case 1:
                cout <<"\n" << database.path("MAO", "LIS") <<"\n";
                break;
            case 2:
                exit(0);
            default:
                exit(0);
        }

    }
}
