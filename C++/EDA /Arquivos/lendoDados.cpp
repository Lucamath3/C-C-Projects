/*
    Um objeto ifstream abre um arquivo para entrada. O construtor de ifstream pode receber o nome do arquivo e o modo de abertura
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void outputLine(int, const string, double); // prototipo

int main(){
    //construtor ifstream abre o arquivo
    ifstream inClienteFile("clients.dat", ios::in);

    // fecha o programa se ifstream não pode abrir o arquivo
    if(!inClienteFile){
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    int account;
    char name[30];
    double balance;

    cout << left << setw(10) << "Account" << setw(13)
         << "Name" << setw(20) << "Balance" << endl << fixed << showpoint;
    
    //exibe cada registro no arquivo
    while (inClienteFile >> account >> name >> balance)
        outputLine(account, name, balance);
    
    return 0;
}

// exibe um registro do arquivo
void outputLine(int account, const string name, double balance){
    cout << left << setw(10) << account << setw(13)
         << name << setw(7) << setprecision(2) << right << balance << endl;
}





