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