#include<stdio.h>
#include<string.h>
typedef struct Tcadastro{
    char nome[50];
    char telefone1[12];
    char telefone2[12];
    char telefone3[12];
    char email[70];
    char insta[50];
    int acessos;
}cadastro;
cadastro contatos[50];



int AtualizaCttGlobal(int indice, int codInf, char novaInf[]){
    switch (codInf)
    {
    case 1:
        strcpy(contatos[indice].nome,novaInf);
        return indice;
    case 2:
        strcpy(contatos[indice].telefone1,novaInf);
        return indice;
    case 3:
        strcpy(contatos[indice].telefone2,novaInf);
        return indice;
    case 4:
        strcpy(contatos[indice].telefone3,novaInf);
        return indice;
    case 5:
        strcpy(contatos[indice].email,novaInf);
        return indice;
    case 6:
        strcpy(contatos[indice].insta,novaInf);
        return indice;
    }
    return -1;
}


int main(){


}
