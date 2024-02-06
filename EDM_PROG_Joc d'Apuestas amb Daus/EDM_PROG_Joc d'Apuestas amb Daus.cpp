#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funció per obtenir la suma de dos daus
int tirarDaus() {
    return (rand() % 6) + 1 + (rand() % 6) + 1;
}

// Funció per processar l'aposta i actualitzar el saldo
void processarAposta(double& saldo, double aposta, int sumaDaus) {
    if (sumaDaus == aposta) {
        saldo += 10 * aposta;
        cout << "Has guanyat! S'ha sumat " << 10 * aposta << " $ al teu saldo.\n";
    }
    else if (abs(sumaDaus - aposta) <= 1) {
        saldo += 2 * aposta;
        cout << "Estas a prop! Has guanyat " << 2 * aposta << " $.\n";
    }
    else if (abs(sumaDaus - aposta) <= 2) {
        saldo += aposta;
        cout << "Has guanyat " << aposta << " $.\n";
    }
    else {
        saldo -= aposta;
        cout << "Has perdut " << aposta << " $.\n";
    }
}

int main() {
    // Inicialització de la generació de nombres aleatoris amb la funció time
    srand(static_cast<unsigned int>(time(0)));

    // Inicialització del saldo del jugador
    double saldo = 500.0;
    int opcio;

    // Bucle principal del joc
    while (saldo > 0) {
        // Mostra el saldo actual del jugador
        cout << "\nSaldo actual: " << saldo << " $\n";

        // Mostra les opcions del joc
        cout << "1. Place Bet\n";
        cout << "2. Exit\n";
        cout << "Selecciona una opcio: ";

        // Llegeix la opció del jugador
        cin >> opcio;

        // Comutador per gestionar les opcions del jugador
        switch (opcio) {
        case 1: {
            double aposta;
            // Sol·licita al jugador que introdueixi la quantitat a apostar
            cout << "Introdueix la quantitat que vols apostar: ";
            cin >> aposta;

            // Verificar que l'aposta no superi el saldo
            if (aposta > saldo) {
                cout << "No pots apostar més del que tens. Torna a intentar.\n";
                continue;
            }

            // Simula el llançament dels daus i mostra el resultat
            int sumaDaus = tirarDaus();
            cout << "Resultat dels daus: " << sumaDaus << "\n";

            // Processa l'aposta i actualitza el saldo
            processarAposta(saldo, aposta, sumaDaus);
            break;
        }
        case 2:
            // Mostra el saldo final i finalitza el programa
            cout << "Gracies per jugar. El teu saldo final es de " << saldo << " $.\n";
            return 0;
        default:
            // Mostra un missatge d'error si l'opció no és vàlida
            cout << "Opcio no valida. Torna a intentar.\n";
        }
    }

    // Mostra un missatge si el jugador queda sense diners
    cout << "Has quedat sense diners. Fi del joc.\n";
    return 0;
}
