#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

// O construtor de Time inicializa cada membro de dados como zero.
// Assegura que todos os objetos Time iniciem em um estado consistente.

Time::Time(int hr, int min, int sec){
    setTime(hr,min,sec); // valida e configura time
} // fim do construtor de Time

// configura novo valor de Time utilizando a hora universal; assegura que 
// os dados permaneçam consistentes configurando valores inválidos como zero
void Time::setTime(int h, int m, int s){
    setHora(h); // valida horas
    setMinuto(m); // valida minuto
    setSegundo(s); // valida minuto
} // fim da função setTime

//configura valor de Hora
void Time::setHora(int h){
    hora = (h >= 0 && h < 24) ? h: 0; // valida hora
}

//configura valor de Minuto
void Time::setMinuto(int m){
    minuto = (m >= 0 && m < 60) ? m : 0; // valida minuto
} // fom da função setMinute 

// configura valor de Segundo
void Time::setSegundo(int s){
    segundo = (s >= 0 && s < 60) ? s : 0; // valida segundo
} // fim da função setSegundo

// retorna valor de hora
int Time::getHora() {
    return hora;
}

// retorna valor de Minuto
int Time::getMinuto() {
    return minuto;
}

// retorna valor de segundo
int Time::getSegundo() {
    return segundo;
}



// imprime a hora no formato de data/hora universal (HH:MM:SS)
void Time::imprimeUniversal(){
    cout << setfill ('0') << setw(2) << hora << ":"
         << setw(2) << minuto << ":" << setw(2) << segundo;
} // fim da função printUniversal

// imprime a hora no formato-padrão de data/hora (HH:MM:SS AM ou PM)
void Time::imprimePadrao(){
    cout << ( (hora == 0 || hora == 12) ? 12 : hora % 12) << ":"
         << setfill ('0') << setw(2) << minuto << ":" << setw (2)
         << segundo << (hora < 12 ? " AM" : " PM");
} // fim da função imprimePadrao
