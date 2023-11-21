#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstring>

#include "sistema.hpp"

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

void cadastrarCliente (Cliente cliente){
    ofstream sistema = abrirSistemaEscrita(cliente);
    try{
        ofstream sistema = abrirSistemaEscrita(cliente);
        
        sistema << "|DADOS DO CLIENTE|" <<endl;
        sistema << cliente.nome << endl;
        sistema << cliente.id << endl;
        sistema << cliente.carro<< endl; 
        
        sistema.close(); 
    }catch (const runtime_error& e) {
        cout << e.what() << endl;
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