#include <iostream>
#include "arquivos.hpp"
#include "sistema.hpp"
#include <string>

using namespace std;

void abrir_menu(){
    int op = 1;
    while (op != 0){
    cout << "|OFICINA DO CARLAO|" << endl;
    cout << "1. Menu dos Clientes"<< endl;
    cout << "2. Menu dos Mecanicos"<< endl;
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
       
            cout<< "programa encerrado" << endl; 
            return;
        
        break;
    } 
    
    }
    
}

int main()
{
    abrir_menu();
    cout<<"Hello World";

    return 0;
}
