typedef struct palindromo{
    char * palavra;
    struct palindromo * proximo;
}Palindromos;

//Criar Lista vazia
Palindromos * criarLista();
//Verificar ficheiro de palavras
Palindromos * verificaListaPalavras(char * ficheiro);
//Ler  do ficheiro
char * lerPalavra(FILE * ficheiro, char* palavra);
//Verifica se palavra é palindromo
const int palavraPalindromo(char*palavra);
//Inserir na Lista
Palindromos * inserirNaLista(Palindromos * lista, char * palavra);
//Apagar Lista
void apagarLista(Palindromos * lista);
//Contar Palavras
int contarPalavras(Palindromos * lista);
//Imprimir Lista
void imprimirLista(Palindromos * lista);
//Remover Simbolos da Palavra
void removerSimbolos(char * palavra);