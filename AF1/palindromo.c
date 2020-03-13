#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

//Verificar ficheiro de palavras
Palindromos * verificaListaPalavras(char * ficheiro){
    FILE * fp = fopen(ficheiro, "r");
    if(!fp){
        printf("Erro: Não foi possivel abrir ficheiro %s", ficheiro);
        exit(EXIT_FAILURE);
    }
    Palindromos * lista=NULL;
    while(!feof(fp)){
        char * palavra = calloc(10 ,sizeof(char));
        if(!palavra){
            printf("Erro: Não foi possivel alocar memória para palavra");
            exit(EXIT_FAILURE);
        }
        palavra = lerPalavra(fp, palavra);
        if((strlen(palavra)>=3 && strlen(palavra)<=10) && palavraPalindromo(palavra) ){
            lista = inserirNaLista(lista,palavra);
        } else{
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
        removerSimbolos(palavra);
        for(int i =0; palavra[i]!='\0';i++)
            palavra[i]=tolower(palavra[i]);
    }
    return palavra;
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
        int tamanho = strlen(palavra);
        for(int i=0,e=tamanho-1; i<tamanho/2;i++,e--){
            if(palavra[i]!=palavra[e])
                return 0;
        }
        return 1;
    }
    return 0;
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
    Palindromos *aux = lista;
    printf("Existem %d palavras que são palindromos no ficheiro.",contarPalavras(lista) );
    printf("\nA lista de palavras encontradas é:\n");
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

//Remover Simbolos da Palavra
void removerSimbolos(char * palavra){
    int i =0,  e = 0;
    char *aux = calloc(11,sizeof(char));
    if(!aux){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    while(palavra[i]!='\0'){
        if(isalpha(palavra[i])){
            aux[e] = palavra[i];
            e++;
        }
        i++;
    }
    if(strncmp(aux,palavra,10)!=0)
        snprintf(palavra,sizeof(aux),"%s",aux);
    free(aux);
}