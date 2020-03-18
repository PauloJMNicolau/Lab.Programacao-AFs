#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "AF1/palindromo.h"


int main(){
    setlocale(LC_ALL,"Portuguese");
    int modo = -1;
    char * ficheiro=calloc(MAX,sizeof(char));
    if(!ficheiro){
        printf("\nErro: Não é possível executar o programa!\n");
        exit(EXIT_FAILURE);
    }
    Palindromos * lista= lista;
    //Solicitar ficheiro ao utilizador
    printf("O programa detecta palindromos em um ficheiro!\nDe que ficheiro pretende ler?\nFicheiro: ");
    scanf("%s", ficheiro);

    //Solicitar modo de pesquisa
    do{
        printf("Qual o modo de pesquisa que pretende fazer?\n\t0 - Palavras\n\t1-Frases\nModo: ");
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