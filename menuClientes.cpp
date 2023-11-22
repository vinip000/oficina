#include <iostream>
#include <fstream>
#include <cstring>
#include "sistema.hpp"


void menuClientes(){
    int opcao = 1;
    while (opcao!=0){
        cout << "|Menu Clientes|" << endl;
        cout << "1. Listar clientes" << endl;
        cout << "2. Cadastrar clientes" << endl;
        cout << "3. Sair"<< endl;
        cout << "0. Encerrar o programa" << endl;
        cin >> opcao; 
        switch (opcao){
            case 1: 
            void imprimirDadosCliente(Cliente cliente);
            break;
            case 2: 
            int sim = false ;
            void cadastrarCliente(Cliente cliente);
            cout << "Deseja cadastrar o historico do cliente? Digite 1 " << endl;
            
            
            break; 
        }
    }
}