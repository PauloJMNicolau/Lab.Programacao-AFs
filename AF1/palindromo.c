#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "palindromo.h"

//Criar Lista vazia
Palindromos * criarLista(){
    Palindromos * lista = calloc(1,sizeof(Palindromos));
    if(!lista){
        printf("Erro: Não foi possivel criar lista");
        exit(EXIT_FAILURE);
    }
    lista->palavra = NULL;
    lista->proximo = NULL;
    return lista;
    
}

//Apagar Lista
void apagarLista(Palindromos * lista){
    if(lista->proximo!=NULL)
        apagarLista(lista->proximo);
    free(lista->palavra);
    lista->palavra = NULL;
    free(lista);
    lista=NULL;
}

//Inserir na Lista
Palindromos * inserirNaLista(Palindromos * lista, char * palavra){
    Palindromos * novo = criarLista();
    novo->palavra = palavra;
    novo->proximo = lista;
    return novo;
}

//Contar Palavras
int contarElementos(Palindromos * lista){
    int contador = 0;
    Palindromos * aux = lista;
    while(aux!=NULL){
        contador++;
        aux=aux->proximo;
    }
    return contador;
}

Palindromos * lerFicheiro(char * ficheiro, int modo){
    FILE * fp = fopen(ficheiro, "r");
    if(!fp){
        printf("Erro: Não foi possivel abrir ficheiro %s", ficheiro);
        exit(EXIT_FAILURE);
    }
    Palindromos * lista=NULL;
    char * expressao = NULL;
    while(!feof(fp)){
        if(modo){
           expressao = lerExpressao(fp);
           
        }
        else
            expressao = lerPalavra(fp);
    }
    
    fclose(fp);
    return lista;
}

//Ler uma Frase do ficheiro
char * lerExpressao(FILE * ficheiro){
    char * expressao = calloc(MAX,sizeof(char));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    
    fscanf(ficheiro, "%[^.]", expressao);
    return expressao;
}

//Ler uma palavra do ficheiro
char * lerPalavra(FILE * ficheiro){
    char * expressao = calloc(MAX,sizeof(char));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    fscanf(ficheiro, "%s", expressao);
    return expressao;
}

//Avaliar Expressão
Palindromos * verificaExpressao(Palindromos * lista, char * expressao){
    
}

//Avaliar Palavra
Palindromos * verificaPalavra(Palindromos * lista, char * expressao){
    
}












