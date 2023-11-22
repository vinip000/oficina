#include <iostream>
#include "arquivos.hpp"
#include "sistema.hpp"
#include <string>

using namespace std;

void menuClientes() {
    int opcao = 1;
    while (opcao != 0) {
        cout << "|Menu Clientes|" << endl;
        cout << "1. Listar clientes" << endl;
        cout << "2. Cadastrar clientes" << endl;
        cout << "3. Sair" << endl;
        cout << "0. Encerrar o programa" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
            imprimirDadosCliente();
                break;
            case 2:
                cadastarCliente();
                break;
            case 3:
                break;
        }
    }
}

void menuMecanicos() {
    int opcao = 1;

    while (opcao != 0) {
        cout << "|Menu Mecanicos|" << endl;
        cout << "1. Listar mecanicos" << endl;
        cout << "2. Cadastrar mecanicos" << endl;
        cout << "3. Sair" << endl;
        cout << "0. Encerrar o programa" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                // Chame a função para cadastrar mecanicos aqui
                break;
            case 3:
                break;
        }
    }
}

void menuAtendimentos() {
    int opcao = 1;

    while (opcao != 0) {
        cout << "|Menu de Atendimentos|" << endl;
        cout << "1. Listar atendimentos" << endl;
        cout << "2. Cadastrar atendimento" << endl;
        cout << "3. Sair" << endl;
        cout << "0. Encerrar o programa" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Chame a função para listar atendimentos aqui
                break;
            case 2:
                // Chame a função para cadastrar atendimento aqui
                break;
        }
    }
}

void abrir_menu() {
    int op = 1;
    while (op != 0) {
        cout << "|OFICINA DO CARLAO|" << endl;
        cout << "1. Menu dos Clientes" << endl;
        cout << "2. Menu dos Mecanicos" << endl;
        cout << "3. Menu dos Atendimentos" << endl;
        cout << "0. Encerrar o programa" << endl;
        cin >> op;
        switch (op) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuMecanicos();
                break;
            case 3:
                menuAtendimentos();
                break;
            case 0:
                cout << "Programa encerrado" << endl;
                return;
        }
    }
}

int main() {
    abrir_menu();
    cout << "Hello World" << endl;
    return 0;
}
