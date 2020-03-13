#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palindromo.h"

//Criar Lista vazia
Palindromos * criarLista(){
    Palindromos * lista = malloc(sizeof(Palindromos));
    if(!lista){
        printf("Erro: Não foi possivel criar lista");
        exit(EXIT_FAILURE);
    }
    lista->palavra = NULL;
    lista->proximo = NULL;
    return lista;
}

//Verificar ficheiro de palavras
Palindromos * verificaListaPalavras(char * ficheiro){
    
    FILE * fp = fopen(ficheiro, "r");
    if(!fp){
        printf("Erro: Não foi possivel abrir ficheiro %s", ficheiro);
        exit(EXIT_FAILURE);
    }
    Palindromos * lista=NULL;
    while(!feof(fp)){
        char * palavra = malloc(10 * sizeof(char));
        if(!palavra){
            printf("Erro: Não foi possivel alocar memória para palavra");
            exit(EXIT_FAILURE);
        }
        palavra = lerPalavra(fp, palavra);
        int res =1;
        res = palavraPalindromo(palavra);
        if(res){
            lista = inserirNaLista(lista,palavra);
        }else{
            free(palavra);
            palavra=NULL;
        }
    }
    fclose(fp);
    return lista;
}

//Ler  do ficheiro
char * lerPalavra(FILE * ficheiro, char* palavra){
    if(ficheiro && palavra){
        fscanf(ficheiro,"%s", palavra);
        palavraEmMinuscula(palavra);
    }
    return palavra;
}

//Palavra em Minuscula
void palavraEmMinuscula(char * palavra){
    if(palavra){
        for(int i =0; palavra[i]!='\0';i++)
            if(palavra[i]>='A' && palavra[i]<='Z')
                palavra[i]=palavra[i]+32;
    }
}

//Inserir na Lista
Palindromos * inserirNaLista(Palindromos * lista, char * palavra){
    Palindromos * novo = criarLista();
    novo->palavra = palavra;
    novo->proximo = lista;
    return novo;
}

//Verifica se palavra é palindromo
const int palavraPalindromo(char*palavra){
    if(palavra){
        char * inversa = inverterPalavra(palavra);
        int res=strncmp(palavra,inversa,10);
        free(inversa);
        if(!res)
            return 1;
    }
    return 0;
}

//Inverter Palavra
char * inverterPalavra(char * palavra){
    char * aux = NULL;
    aux=malloc(sizeof(char) * 10);
    if(!aux){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
        for(int i=0, e=(strlen(palavra)-1);i<(strlen(palavra));i++,e--)
            aux[i]=palavra[e];
    
    return aux;
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

//Contar Palavras
int contarPalavras(Palindromos * lista){
    int contador = 0;
    Palindromos * aux = lista;
    while(aux!=NULL){
        contador++;
        aux=aux->proximo;
    }
    return contador;
}

//Imprimir Lista
void imprimirLista(Palindromos * lista){
    printf("Existem %d palavras que são palindromos no ficheiro.",contarPalavras(lista) );
    printf("\nA lista de palavras encontradas é:\n");
    Palindromos *aux = lista;
    while(aux!=NULL){
        printf("\t%s\n", aux->palavra);
        aux=aux->proximo;
    }
}

int main(){
    Palindromos * lista = verificaListaPalavras("lista.txt");
    imprimirLista(lista);
    apagarLista(lista);
    return 0;
}