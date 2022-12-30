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
                vector<string> airlines;
                //airlines.push_back("TAP");
                airlines.push_back("TAM");
                vector<vector<vector<string>>> path = database.path("MAO", "LIS", airlines);
                //vector<vector<vector<string>>> path = database.cityPath("Paris", "Manaus");
                //vector<vector<vector<string>>> path = database.coordsPath(49.012779, 2.55, 40.639751, -73.778925);
                cout << "Voce possui " << path.size() << " rotas: \n";
                for(int k = 0; k<path.size(); k++) {
                    cout << "Rota " << k+1 << ": \n";
                    for (int i = 0; i < path[k].size()-1; i++) {
                        cout << "De " << path[k][i][0] << " para " << path[k][i+1][0] << ". Podendo ir de:\n";
                        for (int j = 1; j < path[k][i].size(); j++) {
                            cout << path[k][i][j] << "\n";
                        }
                        cout << "\n";
                    }
                    cout << "\n\n\n";
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
