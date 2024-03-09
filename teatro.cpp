#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;
const int PRECO_FILEIRAS_1_A_5 = 50;
const int PRECO_FILEIRAS_6_A_10 = 30;
const int PRECO_FILEIRAS_11_A_15 = 15;

char teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA];

void inicializarTeatro() {
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            teatro[i][j] = '.';
        }
    }
}

void exibirMapaOcupacao() {
    cout << "Mapa de Ocupação do Teatro:\n";
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << teatro[i][j] << " ";
        }
        cout << endl;
    }
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Digite a fileira (1-" << NUM_FILEIRAS << "): ";
    cin >> fileira;
    cout << "Digite a poltrona (1-" << POLTRONAS_POR_FILEIRA << "): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Fileira ou poltrona inválida.\n";
        return;
    }

    --fileira;
    --poltrona;

    if (teatro[fileira][poltrona] == '#') {
        cout << "Este lugar já está ocupado.\n";
        return;
    }

    teatro[fileira][poltrona] = '#';
    cout << "Reserva efetuada com sucesso!\n";
}

void exibirFaturamento() {
    int lugaresOcupados = 0;
    double valorTotal = 0.0;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        int precoFileira;
        if (i < 5) {
            precoFileira = PRECO_FILEIRAS_1_A_5;
        } else if (i < 10) {
            precoFileira = PRECO_FILEIRAS_6_A_10;
        } else {
            precoFileira = PRECO_FILEIRAS_11_A_15;
        }

        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (teatro[i][j] == '#') {
                ++lugaresOcupados;
                valorTotal += precoFileira;
            }
        }
    }

    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << valorTotal << endl;
}

int main() {
    inicializarTeatro();

    int opcao;
    do {
        cout << "\nOpções:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupação\n";
        cout << "3. Faturamento\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Finalizando...\n";
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                exibirMapaOcupacao();
                break;
            case 3:
                exibirFaturamento();
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}