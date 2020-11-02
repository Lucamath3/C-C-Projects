#include <string>
#include <iostream>

using namespace std;

// Função auxiliar para embaralhar o valor das letras originais na posição da tabela ASCII

char converter(char ch, int chave){
    if (!isalpha(ch)) return ch;
    char offset = isupper(ch) ? 'A' : 'a';  // Parâmetro que permite diferenciar letras maiúsculas de 
                                            // minúsculas e, assim, possíveis erros na consulta da tabela;
                                            // A distância entre o 'a' e 'A' é o mesmo para qualquer outra letra.
    return (char)((((ch + chave) - offset) % 26) + offset);
}

// Algoritmo de criptografica - Cifra de César
string criptografar( string entrada, int chave ){ 
    string saida = "";
    size_t len = entrada.size();
    for( size_t i = 0; i < len; i++ )
        saida += converter( entrada[i], chave ); //Converte e concatena letra por letra
    return saida;
}

// Algoritmo de decriptografia
string decriptografar( string entrada, int chave ){
    return criptografar( entrada, 26 - chave );
}

int main(void){
    int chave = 7; // Chave Simétrica

    string txt = "Lucas Matheus, bombeiro militar e engenheiro de computação!"; // Mensagem em texto puro
    cout << "Texto Original: " << txt << endl;

    string cripto = criptografar( txt, chave );
    cout << "Texto Cifrado: " << cripto << endl;

    string decripto = decriptografar( cripto, chave );
    cout << "Texto Decifrado: " << decripto << endl;

    return 0;
}
