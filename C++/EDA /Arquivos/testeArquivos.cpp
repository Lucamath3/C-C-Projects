#include <iostream>
#include <fstream>

using namespace std;

int main(){

    // ofstream é o tempalte da classe basic_fstream.
    // definição do objeto saidaArquivo como saida do fluxo 
    // e criação do arquivo "arquivo_teste.txt"
    ofstream saidaArquivo("arquivo_teste.txt", ios::out); 

    // verificação para evitar erros de abertura
    if (!saidaArquivo){
        cerr << "Erro! O arquivo não pode ser criado" << endl;
        exit(1);
    }

    cout << "Entre com os dados na sguinte ordem:  nome, idade, profissão: " << endl 
         << "O final de linha é '?'." << endl;

    int idade;
    char profissao[30];
    char nome[30];

    while(cin >> nome >> idade >> profissao){
        saidaArquivo << nome << ' ' << idade << ' ' << profissao << endl; 
    }

    return 0;
}