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
Palindromos * inserirNaLista(Palindromos * lista, wchar_t* palavra){
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
    wchar_t * expressao = NULL;
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
wchar_t * lerExpressao(FILE * ficheiro){
    wchar_t * expressao = calloc(MAX,sizeof(wchar_t));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    fwscanf(ficheiro, L"%l[^.].", expressao);
    return expressao;
}

//Ler uma palavra do ficheiro
wchar_t* lerPalavra(FILE * ficheiro){
    wchar_t* expressao = calloc(MAX,sizeof(wchar_t));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    fwscanf(ficheiro, L"%ls", expressao);
    return expressao;
}

//Avaliar Expressão
//Retorna 0 se não for
//Retorna 1 se for
int verificaExpressao(wchar_t* expressao){
    wchar_t* aux = simplificar(expressao);
    if(wcscmp(aux,L"") !=0 && ePalindromo(aux)){
        free(aux);
        aux = NULL;
        return 1;
    }
    free(expressao);
    expressao=NULL;
    free(aux);
    aux = NULL;
    return 0;
    
}

//Avaliar Palavra
//Retorna 0 se não for
//Retorna 1 se for
int verificaPalavra(wchar_t* expressao){
    wchar_t* aux = simplificar(expressao);
    int tamanho = wcslen(aux);
    if((tamanho>=3 && tamanho<=10) && ePalindromo(aux)){
        free(aux);
        aux=NULL;
        return 1;
    }
    free(expressao);
    expressao=NULL;
    free(aux);
    aux = NULL;
    return 0;
}

//Avalia se Palavra ou Expressao é Palindromo
//Retorna 0 se não for
//Retorna 1 se for
int ePalindromo(wchar_t* expressao){
    if(expressao){
        int tamanho = wcslen(expressao);
        for(int i=0,e=tamanho-1; i<tamanho/2;i++,e--){
            if(expressao[i]!=expressao[e])
                return 0;
        }
        return 1;
    }
    return 0;
}

//Simplificar Carateres da Expressao
wchar_t* simplificar(wchar_t* expressao){
    wchar_t* aux = calloc(wcslen(expressao)+1,sizeof(wchar_t));
    if(!aux){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    swprintf(aux,wcslen(expressao)+1,L"%ls", expressao);
    removerCarateresEspeciais(0,0,aux);
    return aux;
}

//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, wchar_t* expressao){
    wchar_t aux = converterCarater(expressao[i]);
    if(isalpha(aux)){
        expressao[pos]=aux;
        removerCarateresEspeciais(pos+1,i+1,expressao);
    }else if(aux=='\0'){
        expressao[pos]=aux;
    }else
        removerCarateresEspeciais(pos,i+1,expressao);
}

//Converter Carateres
wchar_t converterCarater(wchar_t carater){
    carater = towlower(carater);
    switch (carater){
        case L'á':
        case L'à':
        case L'ã':
        case L'â':
            return L'a';
        case L'é':
        case L'è':
        case L'ẽ':
        case L'ê':
            return L'e';
        case L'í':
        case L'ì':
        case L'ĩ':
        case L'î':
            return L'i';
        case L'ó':
        case L'ò':
        case L'õ':
        case L'ô':
            return L'o';
        case L'ú':
        case L'ù':
        case L'ũ':
        case L'û':
            return L'u';
        case L'ñ':
            return L'n';
        case L'ç':
            return L'c';
        default:
            return carater;
    }
}

//Imprimir Lista
void imprimirLista(Palindromos * lista){
    int tamanho = contarElementos(lista);
    wprintf(L"Existem %d elementos que são palindromos no ficheiro.\n", tamanho);
    if(tamanho){
        wprintf(L"A lista de elementos encontradas é:\n");
        imprimir(lista);
    }
}

//Imprimir Elemento
void imprimir(Palindromos * lista){
    if(lista){
        imprimir(lista->proximo);
        wprintf(L"\t%S \n", lista->palavra);
    }
}

void removerEspaco(wchar_t* expressao){
    int pos =0;
    while(expressao[pos]==' ' || expressao[pos] == '\n'){
        pos++;
    }
    if(pos!=0){
        int aux = pos;
        int tamanho = wcslen(expressao);
        wchar_t* temp= calloc(tamanho,sizeof(wchar_t));
        while(pos<tamanho){
            temp[pos-aux]=expressao[pos];
            pos++;
        }
        swprintf(expressao, tamanho,L"%ls", temp);
        free(temp);
        temp=NULL;
    }
}