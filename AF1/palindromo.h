#define MAX 50

typedef struct palindromo{
    char16_t * palavra;
    struct palindromo * proximo;
}Palindromos;


//Criar Lista vazia
Palindromos * criarLista();
//Apagar Lista
void apagarLista(Palindromos * lista);
//Ler uma Frase do ficheiro
char16_t * lerExpressao(FILE * ficheiro);
//Ler uma palavra do ficheiro
char16_t * lerPalavra(FILE * ficheiro);
//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, char16_t * expressao);
//Simplificar Carateres da Expressao
char16_t * simplificar(char16_t * expressao);
//Avalia se Palavra ou Expressao é Palindromo
//Retorna 0 se não for
//Retorna 1 se for
int ePalindromo(char16_t * expressao);
//Avaliar Palavra
//Retorna 0 se não for
//Retorna 1 se for
int verificaPalavra(char16_t * expressao);
//Avaliar Expressão
//Retorna 0 se não for
//Retorna 1 se for
int verificaExpressao(char16_t * expressao);
//Contar Elementos da Lista
int contarElementos(Palindromos * lista);
//Ler Ficheiro de Texto
Palindromos * lerFicheiro(char16_t * ficheiro, int modo);
//Converter Carateres
char16_t converterCarater(char16_t carater);
//Imprimir Lista
void imprimirLista(Palindromos * lista);
//Imprimir Elemento
void imprimir(Palindromos * lista);

void removerEspaco(char16_t * expressao);