// Declaração da classe Time.
// Funções-membro são definidas em Time.cpp

// impede múltiplas inclusões de arquivo de cabeçalho

#ifndef TIME_H
#define TIME_H

// definição da classe Time

class Time{
    public:
        Time(int = 0, int = 0, int = 0); //construtor

        // setters
        void setTime(int, int, int); // confiura hora, minuto e segundo
        void setHora(int); // configura hora (depois da validação)
        void setMinuto(int); // configura minuto (depois da validação)
        void setSegundo(int); // configura segundo (depois da validação)

        // getters
        int getHora(); // retorna Hora
        int getMinuto(); // retorna Minuto
        int getSegundo(); // retorna Segundo
        
        void imprimeUniversal(); // imprime a hora no formato de data/hora universal
        void imprimePadrao(); // imprime a hora no formato padrão de data/hora
    private:
        int hora; // 0-23 (formato de relógio de 24 horas)
        int minuto; // 0-59
        int segundo; // 0-59
}; // fim da classe Time

#endif