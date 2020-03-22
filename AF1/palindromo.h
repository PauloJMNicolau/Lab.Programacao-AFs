#define MAX 100

typedef struct palindromo{
    wchar_t* palavra;
    struct palindromo * proximo;
}Palindromos;


//Criar Lista vazia
Palindromos * criarLista();
//Apagar Lista
void apagarLista(Palindromos * lista);
//Ler uma Frase do ficheiro
wchar_t * lerExpressao(FILE * ficheiro);
//Ler uma palavra do ficheiro
wchar_t * lerPalavra(FILE * ficheiro);
//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, wchar_t * expressao);
//Simplificar Carateres da Expressao
wchar_t * simplificar(wchar_t * expressao);
//Avalia se Palavra ou Expressao é Palindromo
//Retorna 0 se não for
//Retorna 1 se for
int ePalindromo(wchar_t * expressao);
//Avaliar Palavra
//Retorna 0 se não for
//Retorna 1 se for
int verificaPalavra(wchar_t * expressao);
//Avaliar Expressão
//Retorna 0 se não for
//Retorna 1 se for
int verificaExpressao(wchar_t * expressao);
//Contar Elementos da Lista
int contarElementos(Palindromos * lista);
//Ler Ficheiro de Texto
Palindromos * lerFicheiro(char * ficheiro, int modo);
//Converter Carateres
wchar_t converterCarater(wchar_t carater);
//Imprimir Lista
void imprimirLista(Palindromos * lista);
//Imprimir Elemento
void imprimir(Palindromos * lista);
//Remover Espaços em branco no inicio das frases
void removerEspaco(wchar_t* expressao);


//Verificar Palindromos no meio de frases
void procuraNaExpressao(wchar_t * expressao, Palindromos * lista);