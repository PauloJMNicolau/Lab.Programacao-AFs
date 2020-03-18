#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>
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
    if(lista !=NULL){
        if(lista->proximo!=NULL)
            apagarLista(lista->proximo);
        free(lista->palavra);
        lista->palavra = NULL;
    }
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

//Contar Elementos da Lista
int contarElementos(Palindromos * lista){
    int contador = 0;
    Palindromos * aux = lista;
    while(aux!=NULL){
        contador++;
        aux=aux->proximo;
    }
    return contador;
}

//Ler Ficheiro de Texto
Palindromos * lerFicheiro(char * ficheiro, int modo){
    FILE * fp = fopen(ficheiro, "r");
    if(!fp){
        printf("Erro: Não foi possivel abrir ficheiro %s", ficheiro);
        exit(EXIT_FAILURE);
    }
    Palindromos * lista=NULL;
    char16_t * expressao = NULL;
    while(!feof(fp)){
        if(modo){
            expressao = lerExpressao(fp);
            removerEspaco(expressao);
            if(verificaExpressao(expressao))
                lista = inserirNaLista(lista,expressao);
        }
        else{
            expressao = lerPalavra(fp);
            removerEspaco(expressao);
            if(verificaPalavra(expressao))
                lista = inserirNaLista(lista,expressao);
        }
        
        
    }
    fclose(fp);
    return lista;
}

//Ler uma Frase do ficheiro
char16_t * lerExpressao(FILE * ficheiro){
    char16_t * expressao = calloc(MAX,sizeof(char));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }

    //fscanf(ficheiro, "%[^.].", expressao);
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
//Retorna 0 se não for
//Retorna 1 se for
int verificaExpressao(char * expressao){
    char * aux = simplificar(expressao);
    if(strcmp(aux,"") !=0 && ePalindromo(aux)){
        free(aux);
        aux = NULL;
        return 1;
    }
    return 0;
    
}

//Avaliar Palavra
//Retorna 0 se não for
//Retorna 1 se for
int verificaPalavra(char * expressao){
    char * aux = simplificar(expressao);
    int tamanho = strlen(aux);
    if((tamanho>=3 && tamanho<=10) && ePalindromo(aux)){
        free(aux);
        aux=NULL;
        return 1;
    }
    return 0;
}

//Avalia se Palavra ou Expressao é Palindromo
//Retorna 0 se não for
//Retorna 1 se for
int ePalindromo(char * expressao){
    if(expressao){
        int tamanho = strlen(expressao);
        for(int i=0,e=tamanho-1; i<tamanho/2;i++,e--){
            if(expressao[i]!=expressao[e])
                return 0;
        }
        return 1;
    }
    return 0;
}

//Simplificar Carateres da Expressao
char * simplificar(char * expressao){
    char * aux = calloc(strlen(expressao)+1,sizeof(char));
    if(!aux){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    snprintf(aux,strlen(expressao)+1,"%s", expressao);
    removerCarateresEspeciais(0,0,aux);
    return aux;
}

//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, char * expressao){
    char aux = converterCarater(expressao[i]);
    if(isalpha(aux)){
        expressao[pos]=aux;
        removerCarateresEspeciais(pos+1,i+1,expressao);
    }else if(aux=='\0'){
        expressao[pos]=aux;
    }else
        removerCarateresEspeciais(pos,i+1,expressao);
}

//Converter Carateres
char converterCarater(char carater){
    carater = tolower(carater);
    if(carater == -61/*131*/ || carater ==-29/*132*/ || carater ==-95/*133*/ || carater ==134 || carater==160 || carater==198)
        return 'a';
    else if(carater ==136 || carater ==137 ||carater ==138)
        return 'e';
    else if(carater ==139 ||carater ==140 ||carater ==141 ||carater ==161 ||carater ==213)
        return 'i';
    else if(carater ==147 || carater ==148 || carater ==149 ||carater ==162)
        return 'o';
    else if(carater ==150 ||carater ==151 ||carater ==163)
        return 'u';
    else if (carater == 135)
        return 'c';
    else if (carater==164)
        return 'n';
    else    
        return carater;
}

//Imprimir Lista
void imprimirLista(Palindromos * lista){
    int tamanho = contarElementos(lista);
    printf("Existem %d elementos que são palindromos no ficheiro.\n", tamanho);
    if(tamanho){
        printf("A lista de elementos encontradas é:\n");
        imprimir(lista);
    }
}

//Imprimir Elemento
void imprimir(Palindromos * lista){
    if(lista){
        imprimir(lista->proximo);
        printf("\t%s\n", lista->palavra);
    }
}

void removerEspaco(char * expressao){
    int pos =0;
    while(expressao[pos]==' ' || expressao[pos] == '\n'){
        pos++;
    }
    if(pos!=0){
        int aux = pos;
        int tamanho = strlen(expressao);
        char * temp= calloc(tamanho,sizeof(char));
        while(pos<tamanho){
            temp[pos-aux]=expressao[pos];
            pos++;
        }
        snprintf(expressao, tamanho,"%s", temp);
        free(temp);
        temp=NULL;
    }
}