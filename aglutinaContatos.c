#include <stdio.h>
#include <string.h>
#define N 50
typedef struct
{
    char nome[500];
    char telefone1[500];
    char telefone2[500];
    char telefone3[500];
    char email[500];
    char instagram[500];
    int acessos;
} contatinho;
contatinho agenda[N];

void aglutinar_contatinho(int i1, int i2)
{
    printf("Agluinando contato %s com %s...\n\n", agenda[i1].nome, agenda[i2].nome);
    if (agenda[i1].telefone1[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0')
        {
        strcpy(agenda[i1].telefone1, agenda[i2].telefone3);
        }
    }

    if (agenda[i1].telefone2[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone1) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone2) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0' && strcmp(agenda[i1].telefone1, agenda[i2].telefone3) != 0)
        {
        strcpy(agenda[i1].telefone2, agenda[i2].telefone3);
        }
    }

    if (agenda[i1].telefone3[0] == '\0')
    {
        if (agenda[i2].telefone1[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone1) != 0 && strcmp(agenda[i1].telefone1, agenda[i2].telefone1) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone1);
        }
        else if (agenda[i2].telefone2[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone2) != 0&& strcmp(agenda[i1].telefone1, agenda[i2].telefone2) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone2);
        }
        else if (agenda[i2].telefone3[0] != '\0' && strcmp(agenda[i1].telefone2, agenda[i2].telefone3) != 0&& strcmp(agenda[i1].telefone1, agenda[i2].telefone3) != 0)
        {
        strcpy(agenda[i1].telefone3, agenda[i2].telefone3);
        }
    }
    if (agenda[i1].email[0] == '\0')
    {
        strcpy(agenda[i1].email, agenda[i2].email);
    }

    if (agenda[i1].instagram[0] == '\0')
    {
        strcpy(agenda[i1].instagram, agenda[i2].instagram);
    }
    agenda[i1].acessos += agenda[i2].acessos;
    //excluir_um_contato(i2);
    printf("==========Concluido com sucesso==========\n\n");
    printf("Aqui estao as informacoes atualizadas:\nNome:%s\nTelefone 1:%s\nTelefone 2:%s\nTelefone 3:%s\nE-mail:%s\nInstagram:%s\nAcessos:%d\n\n", agenda[i1].nome, agenda[i1].telefone1, agenda[i1].telefone2, agenda[i1].telefone3, agenda[i1].email, agenda[i1].instagram, agenda[i1].acessos);
}

void mostraContatosRepetidos(char nome[]){
    // essa funcao deve ser implementada por outro grupo
    buscaContatosRepetidos(nome);
    
    int i2 = -1;
    int i1 = -1;
    
    printf("Os dois indices são: ");
    scanf("%d %d", &i1, &i2);
    
    aglutinar_contatinho(i1, i2);
    
}

int main(){
    aglutinar_contatinho(1, 2);
    return 0;
}