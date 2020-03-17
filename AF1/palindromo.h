#define MAX 50

typedef struct palindromo{
    wchar_t * palavra;
    struct palindromo * proximo;
}Palindromos;



//Contar Palavras
int contarElementos(Palindromos * lista);

//Remover Simbolos da Palavra
void removerSimbolos(char * palavra);

//Converter Carateres
wchar_t converterCarater(wchar_t carater);
//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, wchar_t * expressao);
//Simplificar Carateres da Expressao
wchar_t * simplificar(wchar_t * expressao);
//Ler uma Expressão no ficheiro
wchar_t * lerExpressao(FILE * ficheiro);

Palindromos * lerFicheiro(char * ficheiro, int modo);

//Inserir na Lista
Palindromos * inserirNaLista(Palindromos * lista, wchar_t * palavra);
//Apagar Lista
void apagarLista(Palindromos * lista);
//Imprimir Lista
void imprimirLista(Palindromos * lista);
//Criar Lista vazia
Palindromos * criarLista();

//Ler uma palavra do ficheiro
wchar_t * lerPalavra(FILE * ficheiro);