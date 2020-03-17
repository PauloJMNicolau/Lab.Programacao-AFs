#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
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

//Imprimir Lista
void imprimirLista(Palindromos * lista){
    Palindromos *aux = lista;
    printf("Existem %d palavras que são palindromos no ficheiro.",contarElementos(lista) );
    printf("\nA lista de palavras encontradas é:\n");
    while(aux!=NULL){
        printf("\t%ls\n", aux->palavra);
        aux=aux->proximo;
    }
}

//Inserir na Lista
Palindromos * inserirNaLista(Palindromos * lista, wchar_t * palavra){
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
    wchar_t * expressao = NULL;
    while(!feof(fp)){
        if(modo){
           expressao = lerExpressao(fp);
           wprintf(L"%ls", expressao);
        }
        else
            expressao = lerPalavra(fp);
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
    fwscanf(ficheiro,"%[^.]", expressao);
    return expressao;
}

//Ler uma palavra do ficheiro
wchar_t * lerPalavra(FILE * ficheiro){
     wchar_t * expressao = calloc(MAX,sizeof(wchar_t));
    if(!expressao){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    fwscanf(ficheiro,L"%ls", expressao);
    return expressao;
}














//Simplificar Carateres da Expressao
wchar_t * simplificar(wchar_t * expressao){
    wchar_t * aux = calloc(wcslen(expressao),sizeof(wchar_t));
    if(!aux){
        printf("Erro: Não foi possivel alocar memória para palavra");
        exit(EXIT_FAILURE);
    }
    wcsncpy()
    snprintf(aux,sizeof(expressao),"%s", expressao);
    //int i = 0;
    removerCarateresEspeciais(0,0,aux);
    return aux;
}

//Remover Carateres especiais
void removerCarateresEspeciais(int pos, int i, wchar_t * expressao){
    wchar_t aux = converterCarater(expressao[i]);
    printf("\n%c", aux);
    if(iswalpha(aux)){
        expressao[pos]=aux;
        removerCarateresEspeciais(pos+1,i+1,expressao);
    }else if(aux=='\0'){
        expressao[pos]=aux;
    }else
        removerCarateresEspeciais(pos,i+1,expressao);
}

//Converter Carateres
wchar_t converterCarater(wchar_t carater){
    if(wcsncmp(carater,1,'á')|| wcsncmp(carater,1,'à') || wcsncmp(carater,1,'ã')|| wcsncmp(carater,1,'â') ||
        wcsncmp(carater,1,'Á') || wcsncmp(carater,1,'À')|| wcsncmp(carater,1,'Ã')||wcsncmp(carater,1,'Â'))
    //if(carater == 131 || carater ==132 || carater ==133 || carater ==134 || carater==160 || carater==198)
        return 'a';
    //else if(carater ==136 || carater ==137 ||carater ==138)
    else if(wcsncmp(carater,1,'é')|| wcsncmp(carater,1,'è') || wcsncmp(carater,1,'ẽ')|| wcsncmp(carater,1,'ê') ||
        wcsncmp(carater,1,'É') || wcsncmp(carater,1,'È')|| wcsncmp(carater,1,'Ẽ')||wcsncmp(carater,1,'Ê'))
        return 'e';
    else if(wcsncmp(carater,1,"í")|| wcsncmp(carater,1,"ì") || wcsncmp(carater,1,"ĩ")|| wcsncmp(carater,1,"î") ||
        wcsncmp(carater,1,"Í") || wcsncmp(carater,1,"Ì")|| wcsncmp(carater,1,"Ĩ")||wcsncmp(carater,1,"Î"))
    //else if(carater ==139 ||carater ==140 ||carater ==141 ||carater ==161 ||carater ==213)
        return 'i';
    else if(wcsncmp(carater,1,"ó")|| wcsncmp(carater,1,"ò") || wcsncmp(carater,1,"õ")|| wcsncmp(carater,1,"ô") ||
        wcsncmp(carater,1,"Ó") || wcsncmp(carater,1,"Ò")|| wcsncmp(carater,1,"Õ")||wcsncmp(carater,1,"Ô"))
    //else if(carater ==147 || carater ==148 || carater ==149 ||carater ==162)
        return 'o';
    //else if(carater ==150 ||carater ==151 ||carater ==163)
    else if(wcsncmp(carater,1,"ú")|| wcsncmp(carater,1,"ù") || wcsncmp(carater,1,"ũ")|| wcsncmp(carater,1,"û") ||
        wcsncmp(carater,1,"Ú") || wcsncmp(carater,1,"Ù")|| wcsncmp(carater,1,"Ũ")||wcsncmp(carater,1,"Û"))
        return 'u';
    //else if (carater == 135)
    if(wcsncmp(carater,1,"ç")|| wcsncmp(carater,1,"Ç"))
        return 'c';
    /*else if (carater==164)
        return 'n';*/
    else    
        return carater;
}