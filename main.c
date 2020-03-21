#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include "AF1/palindromo.h"


int main(){
    setlocale(LC_ALL,"pt_PT.UTF-8");
    setlocale(LC_CTYPE, " ");
    int modo = -1;
    char * ficheiro=calloc(MAX,sizeof(char));
    if(!ficheiro){
        wprintf(L"\nErro: Não é possível executar o programa!\n");
        exit(EXIT_FAILURE);
    }
    Palindromos * lista= lista;
    //Solicitar ficheiro ao utilizador
    wprintf(L"O programa detecta palindromos em um ficheiro!\nDe que ficheiro pretende ler?\nFicheiro: ");
    scanf("%s", ficheiro);

    //Solicitar modo de pesquisa
    do{
        wprintf(L"Qual o modo de pesquisa que pretende fazer?\n\t0 - Palavras\n\t1-Frases\nModo: ");
        scanf("%d", &modo);
    }while(modo<0 || modo >=2);

    lista = lerFicheiro(ficheiro,modo);
    //Apagar consola
    system("clear");

    //Imprimir lista encontrada
    imprimirLista(lista);

    //Libertar memoria
    apagarLista(lista);
    free(ficheiro);
    ficheiro=NULL;
    return 0;
}