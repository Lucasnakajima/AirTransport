#include <unistd.h>
#include "Menu.h"

Menu::Menu() {
run();
}

void Menu::run() {
    while(true){
        cout << string(50,'\n');
        cout << "||==============================================================================================================||\n"
                "||                                                                                                              ||\n"
                "||   $$$$$$\\  $$\\        $$$$$$$$\\                                                                    $$\\       ||\n"
                "||  $$  __$$\\ \\__|       \\__$$  __|                                                                   $$ |      ||\n"
                "||  $$ /  $$ |$$\\  $$$$$$\\  $$ | $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\ $$$$$$\\     ||\n"
                "||  $$$$$$$$ |$$ |$$  __$$\\ $$ |$$  __$$\\ \\____$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\\\_$$  _|    ||\n"
                "||  $$  __$$ |$$ |$$ |  \\__|$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |\\$$$$$$\\  $$ /  $$ |$$ /  $$ |$$ |  \\__| $$ |      ||\n"
                "||  $$ |  $$ |$$ |$$ |      $$ |$$ |     $$  __$$ |$$ |  $$ | \\____$$\\ $$ |  $$ |$$ |  $$ |$$ |       $$ |$$\\   ||\n"
                "||  $$ |  $$ |$$ |$$ |      $$ |$$ |     \\$$$$$$$ |$$ |  $$ |$$$$$$$  |$$$$$$$  |\\$$$$$$  |$$ |       \\$$$$  |  ||\n"
                "||  \\__|  \\__|\\__|\\__|      \\__|\\__|      \\_______|\\__|  \\__|\\_______/ $$  ____/  \\______/ \\__|        \\____/   ||\n"
                "||                                                                     $$ |                                     ||\n"
                "||                                                                     $$ |                                     ||\n"
                "||                                                                     \\__|                                     ||\n"
                "||                                                                                                              ||\n"
                "||==============================================================================================================||\n"
                "||                   MELHOR ROTA                       |                    AEROPORTOS                          ||\n"
                "||==============================================================================================================||\n"
                "||  Por coordenada(aeroportos a menos de 50km)    [11] |  Voos a partir de um aeroporto                   [21]  ||\n"
                "||  Por aeroportos especificos                    [12] |  Companhias areas em um aeroporto                [22]  ||\n"
                "||  Por cidade (todos os aeroportos na cidade     [13] |  Destinos a partir de um aeroporto               [23]  ||\n"
                "||                                                     |  Quantos aeroportos atingiveis usando            [24]  ||\n"
                "||                                                     |  um maximo Y de voos                                   ||\n"
                "||==============================================================================================================||\n"
                "||                                                   EXIT [0]                                                   ||\n"
                "||==============================================================================================================||\n"
                "Choose an option: ";
        int choice;
        string airport;
        vector<string> airlines;
        cin >> choice;
        vector<int> values = {0,11,12,13,21,22,23,24};
        if(!inputTest(choice,values)) continue;
        switch(choice){
            case 11:{
                double latsrc, longsrc, latdest, longdest;
                cout << "Digite a latitude do local de partida:";
                cin >> latsrc;
                cout << "Digite a longitude do local de partida:";
                cin >> longsrc;
                cout << "Digite a latitude do destino:";
                cin >> latdest;
                cout << "Digite a longitude do destino:";
                cin >> longdest;
                airlines = airlineSubmenu();
                pathByCoordinates(latsrc,longsrc,latdest, longdest, airlines);
                system("pause");
                break;}
            case 12:{
                string srcAirport, destAirport;
                cout << "Digite o aeroporto de partida:";
                cin >> srcAirport;
                cout << "Digite o aeroporto de chegada:";
                cin >> destAirport;
                airlines = airlineSubmenu();
                pathByAirport(srcAirport, destAirport, airlines);
                system("pause");
                break;}
            case 13:{
                string srcCity, srcCountry, destCity, destCountry;
                cout << "Digite a cidade do local de partida:";
                cin >> srcCity;
                cout << "Digite o pais do local de partida:";
                cin >> srcCountry;
                cout << "Digite a cidade do destino:";
                cin >> destCity;
                cout << "Digite o pais do destino:";
                cin >> destCountry;
                airlines = airlineSubmenu();
                pathByCity(srcCity,srcCountry,destCity, destCountry, airlines);
                system("pause");
                break;}
                case 21:
                    cout << "Digite o aeroporto que deseja pesquisar:";
                    cin >> airport;
                    flightsByAirport(airport);
                    system("pause");
                    break;
                    case 22:
                        cout << "Digite o aeroporto que deseja pesquisar:";
                        cin >> airport;
                        airlinesByAirport(airport);
                        system("pause");
                        break;
            case 23:
                cout << "Digite o aeroporto que deseja pesquisar:";
                cin >> airport;
                cityByAirport(airport);
                system("pause");
                break;

            case 24:
                int y;
                cout << "Digite o aeroporto que deseja pesquisar:";
                cin >> airport;
                cout << "Digite o valor de y:";
                cin >> y;
                airportMaxYByAirport(airport, y);
                system("pause");
                break;

                case 0:
                exit(0);
            default:
                cout << "Valor invalido!! Tente denovo!";
                system("pause");
        }

    }
}

vector<string> Menu:: airlineSubmenu(){
    vector<string> airlines;
    char n;
    while(true) {
        cout << "Deseja utilizar companhias aereas especificas na sua rota?Y/N\n";
        cin >> n;
        if (n == 'y' or n == 'Y') {
            int quant;
            string comp;
            cout << "Digite quantas companias estao em sua rota: ";
            cin >> quant;
            for (int i = 1; i <= quant; i++) {
                cout << "Companhia " << i << "/" << quant << ":";
                cin >> comp;
                airlines.push_back(comp);
            }
            return airlines;
        }
        else if (n == 'n' or n == 'N') return airlines;
        else{
            cout << "Escolha invalida! Tente novamente!";
            sleep (1);
        }
    }
}

void Menu:: pathByCoordinates(double srcLati, double srcLongi, double destLati, double destLongi, vector<string> airlines){
    vector<vector<vector<string>>> path = database.coordsPath(srcLati, srcLongi, destLati, destLongi, airlines);
    cout << "================================\n||     Voce possui " << path.size() << " rotas    ||\n================================\n\n";

    for(int k = 0; k<path.size(); k++) {
        cout << "=======Rota " << k+1 << "=======\n";
        for (int i = 0; i < path[k].size()-1; i++) {
            cout << "De " << path[k][i][0] << " para " << path[k][i+1][0] << ". Podendo ir com as seguintes companias aereas:\n";
            for (int j = 1; j < path[k][i].size(); j++) {
                cout << " --> " << path[k][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void Menu:: pathByAirport(string srcAirport, string destAirport, vector<string> airlines){
    vector<vector<vector<string>>> path = database.path(srcAirport, destAirport, airlines);
    cout << "================================\n"
            "||     Voce possui " << path.size() << " rotas    ||\n"
                                                    "================================\n\n";

    for(int k = 0; k<path.size(); k++) {
        cout << "=======Rota " << k+1 << "=======\n";
        for (int i = 0; i < path[k].size()-1; i++) {
            cout << "De " << path[k][i][0] << " para " << path[k][i+1][0] << ". Podendo ir com as seguintes companias aereas:\n";
            for (int j = 1; j < path[k][i].size(); j++) {
                cout << " --> " << path[k][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void Menu:: pathByCity(string srcCity, string srcCountry, string destCity, string destCountry, vector<string> airlines){
    vector<vector<vector<string>>> path = database.cityPath(srcCity, srcCountry, destCity, destCountry, airlines);
    cout << "================================\n"
            "||     Voce possui " << path.size() << " rotas    ||\n"
                                                    "================================\n\n";

    for(int k = 0; k<path.size(); k++) {
        cout << "=======Rota " << k+1 << "=======\n";
        for (int i = 0; i < path[k].size()-1; i++) {
            cout << "De " << path[k][i][0] << " para " << path[k][i+1][0] << ". Podendo ir com as seguintes companias aereas:\n";
            for (int j = 1; j < path[k][i].size(); j++) {
                cout << " --> " << path[k][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void Menu:: flightsByAirport(string airport){
    unordered_set<string> dest = database.airportList(airport,1);
    cout << "Existem " << dest.size() << " voos a partir deste aerorporto\n";
    char n;
    while(true) {
        cout << "Deseja lista-los?Y/N\n";
        cin >> n;
        if (n == 'y' or n == 'Y') {
            for(auto i: dest){
                cout << airport << "-->" << i << "\n";
            }
            return;
        }
        else if (n == 'n' or n == 'N') return;
        else{
            cout << "Escolha invalida! Tente novamente!";
            sleep (1);
        }
    }
}

void Menu:: airlinesByAirport(string airport){
    unordered_set<string> dest = database.airportList(airport,2);
    cout << "Existem " << dest.size() << " linhas aereas que tem voos nesse aerorporto\n";
    char n;
    while(true) {
        cout << "Deseja lista-las?Y/N\n";
        cin >> n;
        if (n == 'y' or n == 'Y') {
            for(auto i: dest){
                cout << i << "\n";
            }
            return;
        }
        else if (n == 'n' or n == 'N') return;
        else{
            cout << "Escolha invalida! Tente novamente!";
            sleep (1);
        }
    }
}

void Menu:: cityByAirport(string airport){
    unordered_set<string> dest = database.airportList(airport,3);
    cout << "Existem " << dest.size() << " cidades atingiveis a partir deste aerorporto\n";
    char n;
    while(true) {
        cout << "Deseja lista-las?Y/N\n";
        cin >> n;
        if (n == 'y' or n == 'Y') {
            for(auto i: dest){
                cout << i << "\n";
            }
            return;
        }
        else if (n == 'n' or n == 'N') return;
        else{
            cout << "Escolha invalida! Tente novamente!";
            sleep (1);
        }
    }
}

void Menu:: airportMaxYByAirport(string airport, int y){
    unordered_set<string> dest = database.airportMaxY(airport,y);
    cout << "Existem " << dest.size() << " aeroportos atingiveis a "<< y << " voos de distancia\n";
    char n;
    while(true) {
        cout << "Deseja lista-los?Y/N\n";
        cin >> n;
        if (n == 'y' or n == 'Y') {
            for(auto i: dest){
                cout << airport << "-->" << i << "\n";
            }
            return;
        }
        else if (n == 'n' or n == 'N') return;
        else{
            cout << "Escolha invalida! Tente novamente!";
            sleep (1);
        }
    }
}

bool Menu:: inputTest(char choice ,vector<int> values) {
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input! Try again!" << endl;
        sleep(1);
        return false;
    }
    //binary_search(values.begin(),values.end(),choice);
    if (!binary_search(values.begin(),values.end(),choice)) {
        cout << "Invalid choice! Try again!" << endl;
        sleep(1);
        return false;
    }
    return true;
}