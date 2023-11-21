#include <iostream>
#include <fstream>
#include <cstring>
#include "arquivos.hpp"

void contarNumeroLinhas(const string nomeArquivo) {
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    int contador = 0;
    string linha;
    
    while (getline(arquivo, linha)) {
        contador++;
    }
    
    cout << "O arquivo " << nomeArquivo << " possui " << contador << " linhas " << endl;
    arquivo.close();
}

void contarNumeroPalavras(const string nomeArquivo) {
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    int contador = 0;
    string linha;
    
    while (getline(arquivo, linha)) {
        char* palavra = strtok(&linha[0], " ");
        
        while (palavra != nullptr) {
            palavra = strtok(nullptr, " ");
            contador++;
        }
    }
    
    cout << "O arquivo " << nomeArquivo << " possui " << contador << " palavras " << endl;
    arquivo.close();
}

void copiarArquivo(const string arquivoOrigem, const string arquivoDestino) {
    ifstream origem;
    origem.open(arquivoOrigem);
    
    if (!origem.is_open()) {
        cout << "Erro ao abrir o arquivo origem!" << endl;
        return;
    }
    
    ofstream destino;
    destino.open(arquivoDestino, ios::app);
    
    if (!destino.is_open()) {
        cout << "Erro ao abrir o arquivo destino!" << endl;
        return;
    }
    
    string linha;
    
    while(getline(origem, linha)) {
        destino << linha << endl;
    }
    
    origem.close();
    destino.close();
}

void contarPalavra(const string nomeArquivo, const string target) {
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    int contador = 0;
    string linha;
    
    while (getline(arquivo, linha)) {
        char* palavra = strtok(&linha[0], " ");
        
        while (palavra != nullptr) {
            if (target == palavra) {
                contador++;
            }
            
            palavra = strtok(nullptr, " ");
        }
    }
    
    cout << "A palavra " << target << " aparece " << contador << " vezes " << endl;
    arquivo.close();
}

void calcularMedia(const string nomeArquivo) {
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    
    float media = 0;
    int contador = 0;
    string linha;
    
    while(getline(arquivo, linha)) {
        char* palavra = strtok(&linha[0], "|");
        
        while (palavra != nullptr) {
            try {
                float nota = stoi(palavra);
                
                media += nota;
                
                contador++;
            } catch(const invalid_argument& e) {
                cout << "A string " << palavra << " não pode ser convertida para um inteiro!" << endl;
            }
            
            palavra = strtok(nullptr, "|");
        }
    }
    
    media /= contador; // media = media / contador
    cout << "A média é " << media << endl;
    arquivo.close();
}