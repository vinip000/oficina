#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <iostream>

using namespace std;

void contarNumeroLinhas(const string nomeArquivo);
void contarNumeroPalavras(const string nomeArquivo);
void copiarArquivo(const string arquivoOrigem, const string arquivoDestino);
void contarPalavra(const string nomeArquivo, const string palavra);
void calcularMedia(const string nomeArquivo);

#endif