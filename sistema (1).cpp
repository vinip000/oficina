#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstring>

#include "sistema.hpp"
#include "menuClientes.hpp"
#include "menuMecanicos.hpp"
#include "menuAtendimentos.hpp"

using namespace std;
using namespace filesystem;

ofstream abrirSistemaEscrita(Cliente cliente) {
    string nome = cliente.nome;
    int id = cliente.id;
    string nomeArquivo = nome + "_" + to_string(id) + ".txt";

    ofstream sistema(nomeArquivo);
    
    if (!sistema.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo " + nomeArquivo);
    }
    
    return sistema;
}

ofstream abrirSistemaEscrita(Cliente cliente, bool ios) {
    string nome = cliente.nome;
    int id = cliente.id;
    string nomeArquivo = nome + "_" + to_string(id) + ".txt";

    ofstream sistema(nomeArquivo, ios::app);
    
    if (!sistema.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo " + nomeArquivo);
    }
    
    return sistema;
}

ifstream abrirSistemaLeitura(Cliente cliente) {
    string nome = cliente.nome;
    int id = cliente.id;
    string nomeArquivo = nome + "_" + to_string(id) + ".txt";
    
    ifstream sistema(nomeArquivo);
    
    if (!sistema.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo " + nomeArquivo);
    }
    
    return sistema;
}

ifstream abrirSistemaLeitura(string caminho) {
    ifstream sistema(caminho);
    
    if (!sistema.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo " + caminho);
    }
    
    return sistema;
}

void imprimirDadosCliente (Cliente cliente){
    cout << "Nome do cliente: " << cliente.nome << endl;
    cout << "Id do cliente: " << cliente.id <<endl;
    cout << "Carro do cliente: " << cliente.carro<<endl; 
}

void cadastrarCliente(Cliente cliente) {
    try {
        // Receber informações do cliente do usuário
        Cliente novoCliente;
        cout << "Digite o nome do cliente: ";
        getline(cin, novoCliente.nome); // Usando getline para lidar com espaços no nome
        cout << "Digite o ID do cliente: ";
        cin >> novoCliente.id;
        cin.ignore(); // Limpar o caractere de nova linha deixado pelo cin
        cout << "Digite o carro do cliente: ";
        getline(cin, novoCliente.carro);

        // Abrir arquivo e escrever os dados
        ofstream sistema = abrirSistemaEscrita(novoCliente);

        sistema << "|DADOS DO CLIENTE|" << endl;
        sistema << "Nome: " << novoCliente.nome << endl;
        sistema << "ID: " << novoCliente.id << endl;
        sistema << "Carro: " << novoCliente.carro << endl;

        sistema.close();
        cout << "Cliente cadastrado com sucesso." << endl;
    } catch (const runtime_error& e) {
        cerr << "Erro ao cadastrar cliente: " << e.what() << endl;
    }
}



void cadastrarHistorico (Cliente cliente, Historico_Carro historico){
    try{
        ofstream sistema = abrirSistemaEscrita (cliente,true);
        sistema << "|Historico de Problemas do Carro|" << endl;
        
        for (int i=0; i<historico.problemas.size(); i++){
            sistema << historico.problemas[i] << endl;
        }
        sistema << "|O que foi feito: |" << endl;
        
        for (int i=0; i<historico.solucoes.size(); i++){
            sistema << historico.solucoes[i] << endl;
        }
        
        sistema.close();

    }catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void cadastrarAtendimento (Cliente cliente, Atendimento atendimento){
    try {
       ofstream sistema = abrirSistemaEscrita(cliente,true); 
       
       sistema << "|ATENDIMENTO|" <<endl; 
       sistema << "Data do Atendimento: "<< atendimento.data << endl;
       sistema << "Mecanico responsavel pelo atendimento: "<< atendimento.mecanico << endl; 
       sistema << "Descricao do Problema: "<< atendimento.queixa << endl;
       sistema << "Orcamento: "<< atendimento.orcamento << endl;
       
       sistema.close();
       
    }catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void getProblemas(Cliente cliente){
    try{
        ifstream sistema = abrirSistemaLeitura(cliente);
        string linha;
        bool lendoHistorico = false;
        vector<string> historicoProblemas;
        while (getline(sistema, linha)){
            if (linha == "|Historico de Problemas do Carro|"){
                lendoHistorico = true; 
            }else if (linha == "|O que foi feito: |" ){
                break;
            }
        }
        sistema.close();
         for (string problemas: historicoProblemas) {
            cout << problemas << endl;
        }
    }catch(const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void getSolucoes(Cliente cliente){
    try{
        ifstream sistema = abrirSistemaLeitura(cliente);
        string linha;
        bool lendoHistorico = false;
        vector <string> historicoSolucoes;
        while (getline(sistema, linha)){
            if (linha == "|O que foi feito: |"){
                lendoHistorico = true;
            }else if (linha == "|ATENDIMENTO|"){
                break;
            }
        }
        sistema.close();
         for (string solucoes: historicoSolucoes) {
            cout << solucoes << endl;
        }
    }catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void getAtendimentos (Cliente cliente){
    try{
        ifstream sistema = abrirSistemaLeitura(cliente);
        string linha;
        bool lendoHistorico = false;
        vector <string> historicoAtendimentos;
        while (getline (sistema, linha)){
            if (linha == "|ATENDIMENTO|"){
                lendoHistorico = true;
            } else if (linha == ""){
                break;
            }
            if (lendoHistorico){
                historicoAtendimentos.push_back(linha);
            }
        }
        sistema.close();
        for (string atendimento: historicoAtendimentos){
            cout << atendimento << endl;
        }
    }catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void setProblemas(Cliente cliente, string problemas) {
    ifstream sistema = abrirSistemaLeitura(cliente);
    
    string arq_temp = "temp.txt";
    ofstream sistema_temp(arq_temp);
    
    if (!sistema_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arq_temp << endl;
        return;
    }
    
    string linha;
    while (getline(sistema, linha)) {
        if (linha == "|Historico de Problemas do Carro|") {
            sistema_temp << problemas << endl;
            sistema_temp <<"|Historico de Problemas do Carro|" << endl;
        } else {
            sistema_temp << linha << endl;
        }
    }
    
    sistema_temp.close();
   sistema.close();
    
    remove((cliente.nome + "_" + to_string(cliente.id) + ".txt").c_str());
    rename(arq_temp.c_str(), (cliente.nome + "_" + to_string(cliente.id) + ".txt").c_str());
    
    cout << "Adição de doença concluída com sucesso!" << endl;
}










