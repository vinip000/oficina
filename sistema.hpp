#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include <vector>

using namespace std;

struct Mecanico{
  string nome;
  int usuario;
  int id;
  Mecanico(string _nome, int _usuario, int _id){
      nome=_nome;
      usuario = _usuario;
      id = _id;
  }
};


struct Cliente{

    string nome;
    int id;
    string carro;
    Cliente (string _nome, int _id, string _carro){ 

        nome = _nome;
        id = _id;
        carro = _carro;
    }
};

struct Historico_Carro {
  
   vector <string> problemas;
   vector <string> solucoes;
   
   Historico_Carro (vector <string> _problemas, vector <string> _solucoes){
        problemas = _problemas;
        solucoes = _solucoes; 
   }
};

struct Atendimento {
    string data;
    string mecanico;
    string queixa;
    string orcamento; 
    
Atendimento(string _data, string _mecanico, string _queixa, string _orcamento){
    data = _data;
    mecanico = _mecanico;
    queixa = _queixa;
    orcamento = _orcamento;
    }
};

void imprimirDadosCliente(Cliente cliente);
void cadastrarCliente(Cliente cliente);
void cadastrarHistorico(Cliente cliente, Historico_Carro historico);
void cadastrarAtendimento(Cliente cliente, Atendimento atendimento);

void getProblemas(Cliente cliente);
void getSolucoes(Cliente cliente);
void getAtendimentos(Cliente cliente);

#endif