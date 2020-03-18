#define MAX 50

typedef struct palindromo{
    char * palavra;
    struct palindromo * proximo;
}Palindromos;


//Criar Lista vazia
Palindromos * criarLista();
//Apagar Lista
void apagarLista(Palindromos * lista);
//Ler uma Frase do ficheiro
char * lerExpressao(FILE * ficheiro);
//Ler uma palavra do ficheiro
char * lerPalavra(FILE * ficheiro);
//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, char * expressao);
//Simplificar Carateres da Expressao
char * simplificar(char * expressao);
//Avalia se Palavra ou Expressao é Palindromo
//Retorna 0 se não for
//Retorna 1 se for
int ePalindromo(char * expressao);
//Avaliar Palavra
//Retorna 0 se não for
//Retorna 1 se for
int verificaPalavra(char * expressao);
//Avaliar Expressão
//Retorna 0 se não for
//Retorna 1 se for
int verificaExpressao(char * expressao);
//Contar Elementos da Lista
int contarElementos(Palindromos * lista);
//Ler Ficheiro de Texto
Palindromos * lerFicheiro(char * ficheiro, int modo);
//Converter Carateres
char converterCarater(char carater);
//Imprimir Lista
void imprimirLista(Palindromos * lista);
//Imprimir Elemento
void imprimir(Palindromos * lista);

void removerEspaco(char * expressao);