// Programa para testar a classe Time.
// Este arquivo deve ser compilado com Time.cpp
#include <iostream>
#include "Time.h" // inclui a definição da classe Time  a partir de Time.h

using namespace std;

int main(){
    Time t1; // todos os argumentos convertidos para sua configuração-padrão
    Time t2(2); // hora especificada; minuto e segundo convertidos para o padrão
    Time t3(21,34); // hora e minutos especificados; segundo no padrão
    Time t4(12,25,42); // hora, minuto e segundo especificados
    Time t5(27,74,30); // valores inválidos especificados

    cout << "Construtor com:\n\nt1: todos os valores padrões\n ";
    t1.imprimeUniversal(); // 00:00:00
    cout << "\n";

    cout << "\n\nt2: hora especificada; minuto e segundo padrão\n ";
    t2.imprimeUniversal(); //02:00:00
    cout << "\n ";
    t2.imprimePadrao(); //02:00:00 AM

    cout << "\n\nt3: hora e minuto especificado; segundo padrão\n ";
    t3.imprimeUniversal(); // 21:34:00
    cout << "\n";
    t3.imprimePadrao(); // 09:34:00 PM

    cout << "\n\nt4: hora,minuto e segundo especificados\n ";
    t4.imprimeUniversal(); // 12:25:42
    cout << "\n";
    t4.imprimePadrao(); // 12:25:42 PM

    cout << "\n\nt5: Hora e Minutos inválidos\n ";
    t5.imprimeUniversal(); // 00:00:30
    cout << "\n";
    t5.imprimePadrao(); // 12:00:30 AM
    cout << endl;

    return 0;
} // fim de main