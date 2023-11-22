#include <iostream>
#include <fstream>
#include <cstring>
#include "sistema.hpp"

void menuAtendimentos(){
    int opcao = 1;
    
    while (opcao!=0){
        cout << "|Menu de Atendimentos|" << endl;
        cout << "1. Listar atendimentos" << endl;
        cout << "2. Cadastrar atendimento" << endl;
        cout << "3. Sair" << endl;
        cout << "0. Encerrar o programa" << endl;
        cin>> opcao;
        
        switch (opcao){
            case 1: 
                void getAtendimentos (Cliente cliente);
                break;
            case 2: 
                break;
        }
    }
}