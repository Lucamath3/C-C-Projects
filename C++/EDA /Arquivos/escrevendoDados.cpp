/*                      ESCREVENDO DADOS EM UM ARQUIVO
    O Menor item de dados é o bit. Um byte possui 8 bits. Em geral, um registro (que pode ser representado como uma class em C++)
é composto de vários campos (chamados membros de dados em C++);
    Cada arquivo é visualizado como uma sequência de bytes, que possui no final um marcador de fim de arquivo.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // construtor ofstream abre arquivo
    // ios:: out indica saida de daso em um arquivo
    // ios:: app adiciona dados ao fim de um arquivo sem modificar.
    ofstream outClientFile("clients.dat", ios::out);

    // fecha o programa se não conseguir criar arquivo
    if (!outClientFile){ // operador ! sobrecarregado
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    cout << "Enter the account, name, and balance." << endl
         << "Enter end-of-file to end input.\n?";
    
    int account;
    char name[30];
    double balance;

    //lê a conta, nome e saldo a partir de cin, então coloca no arquivo
    while( cin >> account >> name >> balance){
        outClientFile << account << ' ' << name << ' ' << balance << endl;
        cout << "? ";
    }

    outClientFile.close();
    return 0;
}