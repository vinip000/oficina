#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "sistema.hpp"


void imprimirDadosMecanico(Mecanico mecanico){
    cout<< "|Dados do mecanico|" << endl;
    cout << "Nome: " << mecanico.nome << endl;
    cout << "Usuario: " << mecanico.usuario<< endl;
    cout<< "Id: " << mecanico.id << endl;
    
}

/*void cadastrarMecanico (){
    try{
    
    Mecanico novoMecanico;
    
    cout << "Digite o nome do mecanico: " << endl;
    getline (cin, novoMecanico.nome);
    cout << "Digite o usuario do mecanico: " << endl;
    cin >> novoMecanico.usuario << endl;
    cout << "Digite o id do mecanico: " << endl;
    cin >> novoMecanico.id << endl;
    
    ofstream sistema = abrirSistemaEscrita(novoMecanico);
    
    cout << "|Dados do mecanico|" << endl; 
    cout << "Nome: " << novoMecanico.nome;
    cout << "Usuario: " << novoMecanico.usuario << endl;
    cout << "Id: " << novoMecanico.id << endl;
    
    sistema.close();

        cout << "Mecanico cadastrado com sucesso." << endl;
    } catch (const runtime_error& e) {
        cerr << "Erro ao cadastrar mecanico: " << e.what() << endl;
    }
} */

void menuMecanicos(){
    int opcao = 1;
    
    while (opcao!=0){
        cout << "|Menu Mecanicos|" << endl; 
        cout << "1. Listar mecanicos" << endl;
        cout << "2. Cadastrar mecanicos" << endl;
        cout << "3. Sair" << endl; 
        cout << "0. Encerrar o programa" << endl;
        
        switch (opcao){
            case 1: 
            imprimirDadosMecanico();
            break;
            case 2: 
            cadastrarMecanico();
            break;
            case 3:
            break;
        
    }
}
}