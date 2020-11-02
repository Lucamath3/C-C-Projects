#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed; 

#include <iomanip> // manipuladores de fluxo parametrizados
using std::setprecision; //configura a precisão da saída numérica
using std::setw; //configura a largura de campo

#include "GradeBook.h" //definição da classe GradeBook

//o construtor inicializa nomeCurso e o array de notas
GradeBook::GradeBook(string nome, const int notasArray[][testes]){
    setNomeCurso(nome);
    // copia notas de gradeArray para membro de dados grades
    for (int aluno = 0; aluno < alunos; aluno++)
        for (int test = 0; test < testes; test++)
            notas[aluno][test] = notasArray[aluno][test];
} //fim do construtor GradeBook

//função para configurar o nome do curso
void GradeBook::setNomeCurso(string nome){
    nomeCurso = nome; //armazena o nome do curso
} //fim da função setNomeCurso

string GradeBook::getNomeCurso(){
    return nomeCurso;
} //fim da função getNomeCurso

//exibe uma mensagem de boas-vidas para o usuário de GradeBook
void GradeBook::displayMessage(){
    // essa instrução chama getNomeCurso para obter o
    // nome do curso que esse GradeBook representa
    cout << "Bem vindo ao livro de notas para\n " << getNomeCurso() << "!"
         << endl;
} //fim da função displayMessage

//realiza várias operações nos dados
void GradeBook::processaNotas(){
    //gera saida de array de notas
    saidaNotas();

    // chama funções de getMaximo e getMinimo
    cout << "A menor nota é " << getMenor() << "\nA maior nota é " << getMaior()
         << endl;

    // chama saidaGraficoBarra para imprimir o gráfico de distribuição de notas
    saidaGraficoBarra();
} // fim da função processaNotas

//localiza nota mínima
int GradeBook::getMenor(){
    int menorNota = 100; // supõe que a menor nota é 100

    //faz um loop pelo vetor de notas
    for (int aluno = 0; aluno < alunos; aluno++){
        //faz um loop pelas colunas da linha atual
        for (int test = 0; test < testes; test++){
            if(notas[aluno][test] < menorNota)
                menorNota = notas[aluno][test]; //nova nota mais baixa
        }//fim do for interno
    } //fim do for externo
    return menorNota;
}

//localiza nota máxima
int GradeBook::getMaior(){
    int maiorNota = 0; // supõe que a maior nota é 0

    //faz um loop pelo vetor de notas
    for (int aluno = 0; aluno < alunos; aluno++){
        //faz o loop pelas colunas da linha atual
        for (int test = 0; test < testes; test++){
            if(notas[aluno][test] > maiorNota)
                maiorNota = notas[aluno][test];
        } //fim do for interno
    } //fim do for externo
    return maiorNota;
} //fim da função getMaior


double GradeBook::getMedia(const int setNotas[], const int notas){
    int total = 0;

    //soma notas no vetor
    for (int nota = 0; nota < notas; nota++)
        total += setNotas[nota];
    
    return static_cast<double>(total)/notas;
}

void GradeBook::saidaGraficoBarra(){
    cout << "\nDistribuição das Notas: " << endl;

    const int contadorFrequencia = 11;
    int frequencia[contadorFrequencia] = {0};

    //para cada nota, incrementa a frequência apropriada
    for (int aluno = 0; aluno < alunos; aluno ++)
        for (int test = 0; test < testes; test++)
            ++frequencia[notas[aluno][test]/10];

    // para cada frequência de nota, imprime uma barra no gráfico
    for (int contador = 0; contador <contadorFrequencia; contador++){
        // gera saída do rótulo da barra ("0-9:",...,"100:")
        if (contador == 0)
            cout << "  0-9: ";
        else if (contador == 10)
            cout << "  100: ";
        else 
            cout << contador * 10 << "-" << (contador*10) +9 << ": ";
        
        //imprime a barra de asteriscos
        for (int estrelas = 0; estrelas < frequencia[contador]; estrelas++)
            cout << "*";
        
        cout << endl;
    }
}

void GradeBook::saidaNotas(){
    cout << "\nAs notas são: \n\n";
    cout << "            "; //alinha títulos de coluna

    //cria um título de coluna para cada um dos testes
    for (int test = 0; test < testes; test++)
        cout << "Teste " << test+1 << "  ";
    
    cout << "Média" << endl; // título da coluna de média do aluno
    
    //gera a saida da nota de cada aluno
    for (int aluno = 0; aluno < alunos; aluno++){
        cout << "Aluno " << setw(2) << aluno+1;
        // gera saída de notas do aluno
        for (int test = 0; test < testes; test++)
            cout << setw(9) << notas[aluno][test];

        // chama a função-membro getMedia para caluclar a média do aluno;
        // passa linhad e notas e o valor dos testes como argumentos
        double media = getMedia(notas[aluno], testes);
        cout << setw(9) << setprecision(2) << fixed << media << endl;
    } // fim do for externo
} // fim da função saidaNotas


