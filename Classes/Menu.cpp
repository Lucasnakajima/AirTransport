//
// Pela minha parte, tu tens que fazer o case 1 do menu::run(),
// o usuário tem que procurar os voo de um local a outro, temos
// 3 maneiras de achar o Local:
//1: Codigo do aeroporto: Método Database::path()
//2: Cidade dos aeroportos: Método Database::cityPath()
//3: Raio das coordenadas: Método Database::coordsPath()
// No método 2, implementar o país para as cidades. (extremamente simples)
// Para TODOS os métodos o usuário pode escolher ou não Airlines específicas
// pelo código das mesmas, através de um vetor de string. Caso ele não queira
//deverá por um vetor VAZIO para o programa funcionar.
// O método Database::path() é usado em todos os métodos, sendo ele o principal
// para achar os melhores caminhos.
//Os loops no CASE1, são para dar print nas rotas + airlines usadas.
// qualquer dúvida mandar no email: ChupaMinhaPiroca.com
//
//vector<string> airlines;
//airlines.push_back("TAP");
//airlines.push_back("TAM");
//vector<vector<vector<string>>> path = database.path("MAO", "LIS", airlines);
//vector<vector<vector<string>>> path = database.cityPath("Paris", "Manaus", airlines);

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
                "||                                                     |  Quantos locais atingiveis usando                [24]  ||\n"
                "||                                                     |  um maximo Y de voos                                   ||\n"
                "||==============================================================================================================||\n"
                "||                                                   EXIT [0]                                                   ||\n"
                "||==============================================================================================================||\n"
                "Choose an option: ";
        int n;
        vector<string> airlines;
        cin >> n;
        switch(n){
            case 11:
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
                break;
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
            case 0:
                exit(0);
            default:
                exit(0);
        }

    }
}

vector<string> Menu:: airlineSubmenu(){
    vector<string> airlines;
    char n;
    cout << "Deseja utilizar companhias aereas especificas na sua rota?Y/N\n";
    cin >> n;
    if (n == 'y' or n=='Y'){
        int quant;
        string comp;
        cout << "Digite quantas companias estao em sua rota: ";
        cin >> quant;
        for (int i=1; i<=quant; i++){
            cout << "Companhia " << i << "/" << quant << ":";
            cin >> comp;
            airlines.push_back(comp);
        }
    }
    return airlines;
}

void Menu:: pathByCoordinates(double srcLati, double srcLongi, double destLati, double destLongi, vector<string> airlines){
    vector<vector<vector<string>>> path = database.coordsPath(srcLati, srcLongi, destLati, destLongi, airlines);
    cout << "================================\n"
    "||     Voce possui " << path.size() << " rotas    ||\n"
                                            "================================\n\n";

    for(int k = 0; k<path.size(); k++) {
        cout << "=======Rota " << k+1 << "=======\n";
        for (int i = 0; i < path[k].size()-1; i++) {
            cout << "De " << path[k][i][0] << " para " << path[k][i+1][0] << ". Podendo ir com as seguintes companias aereas:\n";
            for (int j = 1; j < path[k][i].size(); j++) {
                cout << " --> " << path[k][i][j] << "\n";
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
                cout << " --> " << path[k][i][j] << "\n";
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