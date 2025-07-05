/* FUNÇÃO 1 */
/* LUYDGI BARBOSA e PEDRO BINOTO */

#include <stdio.h>
#include <string.h>

typedef struct {char Nome[50], telefone1[12], telefone2[12], telefone3[12], Email[50], Instagram[50];} Contato;

Contato contatos[100];

void criarcontato (char nome[], char tel1[], char tel2[], char tel3[], char email[], char insta[]);

int main()
{
    char nome[50], tel1[12], tel2[12], tel3[12], email[50], insta[50];
    char op[14];
    while(1)
    {
        printf("Diga o que fazer:\nCriar contato\nSair e Salvar\n");
        scanf("%13[^\n]", op);
        getchar();

        if(strcmp(op, "Criar contato") == 0 || strcmp(op, "Criar Contato") == 0)
        {
            printf("Digite o nome do contato: ");
            scanf("%s", nome);
            printf("Digite o telefone 1: ");
            scanf("%s", tel1);
            for(int i = 0; i < 11; i++)
            {
                if(tel1[i] < '0' || tel1[i] > '9')
                {
                    printf("Número inválido!\n");
                    return -1;
                }
            }
            printf("Digite o telefone 2: ");
            scanf("%s", tel2);
            for(int i = 0; i < 11; i++)
            {
                if(tel2[i] < '0' || tel2[i] > '9')
                {
                    printf("Número inválido!");
                    return -1;
                }
            }
            printf("Digite o telefone 3: ");
            scanf("%s", tel3);
            for(int i = 0; i < 11; i++)
            {
                if(tel3[i] < '0' || tel3[i] > '9')
                {
                    printf("Número inválido!");
                    return -1;
                }
            }
            printf("Digite o email: ");
            scanf("%s", email);
            for(int i = 0; i < 50; i++)
            {
                if(email[i] == '@')
                    break;
                else
                {
                    printf("Email inválido!\n");
                    return -1;
                }
            }
            printf("Digite o intagram: ");
            scanf("%s", insta);

            criarcontato(nome, tel1, tel2, tel3, email, insta);
        }
        else
        {
            printf("Até mais!\n");
            return 0;
        }
    }
    
}

void criarcontato (char nome[], char tel1[], char tel2[], char tel3[], char email[], char insta[])
{
    static int pos = 0;
    if(pos == 100)
    {
        printf("Número máximo de contatos atingido!\n");
        return;
    }
    strcpy(contatos[pos].Nome, nome);
    strcpy(contatos[pos].telefone1, tel1);
    strcpy(contatos[pos].telefone2, tel2);
    strcpy(contatos[pos].telefone3, tel3);
    strcpy(contatos[pos].Email, email);
    strcpy(contatos[pos].Instagram, insta);
    pos++;
    printf("Contato salvo com sucesso\n");
}
