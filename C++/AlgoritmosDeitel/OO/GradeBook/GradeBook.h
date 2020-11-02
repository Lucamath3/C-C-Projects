// Definição da classe GradeBook que usa um array para armazenar notas de teste.
// As funções-membro são definidas em GradeBook.cpp

#include <string> // o programa uutiliza a calsse string da C++ Standar Library
using std::string;

// Definição da classe GradeBook
class GradeBook{
    public:

        // constantes
        const static int alunos = 10; //número de alunos
        const static int testes = 3; // número de testes

        // construtor inicializa o nome do curso e o array de notas
        GradeBook (string, const int[][testes]); 

        void setNomeCurso(string); // função para configurar o nome do curso
        string getNomeCurso(); // função para recuperar o nome do curso
        void displayMessage(); // exibe uma mensagem de boas-vindas
        void processaNotas(); //realiza várias operações nos dados
        int getMenor(); //localiza a nota mínima para o teste
        int getMaior(); //localiza a nota máxima para o teste
        double getMedia(const int[], const int); //determina a nota média para o teste
        void saidaGraficoBarra(); //gera saída para o gráfico de barras de distribuição de notas
        void saidaNotas(); //gera a saída do conteúdo do array de notas
    
    private:
        string nomeCurso; // nome do curso para esse livro de notas
        int notas[alunos][testes]; //array de notas de aluno
}; // fim da classe GradeBook

