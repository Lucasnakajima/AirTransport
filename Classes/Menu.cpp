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
            case 1 :{
                vector<vector<string>> path = database.path("MAO", "LIS");
                for (int i = path.size() - 1; i > 0; i--) {
                    cout << "De " << path[i][0] << " para " << path[i - 1][0] << ". Podendo ir de:\n";
                    for(int j=1; j<path[i-1].size(); j++){
                        cout << path[i-1][j] << "\n";
                    }
                    cout << "\n";
                }
                break;
            }
            case 2:
                exit(0);
            default:
                exit(0);
        }

    }
}
