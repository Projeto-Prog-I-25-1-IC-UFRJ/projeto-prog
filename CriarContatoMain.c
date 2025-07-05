#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 1000  // Tamanho máximo da agenda
#define MAX_STRING 100     // Tamanho máximo das strings (nome, telefone, etc.)

// Função principal: interface que coleta os dados do usuário e cria o contato
int main() {
    // Variáveis para armazenar as informações do contato
    char nome[MAX_STRING];
    char telefone1[MAX_STRING];
    char telefone2[MAX_STRING];
    char telefone3[MAX_STRING];
    char email[MAX_STRING];
    char instagram[MAX_STRING];

    printf("=== Criar novo contato ===\n");

    // Coleta de dados com fgets (evita problemas com espaços)
    printf("Nome (obrigatório): ");
    fgets(nome, MAX_STRING, stdin);
    removerQuebraLinha(nome);

    printf("Telefone 1: ");
    fgets(telefone1, MAX_STRING, stdin);
    removerQuebraLinha(telefone1);

    printf("Telefone 2: ");
    fgets(telefone2, MAX_STRING, stdin);
    removerQuebraLinha(telefone2);

    printf("Telefone 3: ");
    fgets(telefone3, MAX_STRING, stdin);
    removerQuebraLinha(telefone3);

    printf("Email: ");
    fgets(email, MAX_STRING, stdin);
    removerQuebraLinha(email);

    printf("Instagram: ");
    fgets(instagram, MAX_STRING, stdin);
    removerQuebraLinha(instagram);

    // Chamada da função que cria o contato
    int resultado = criarContato(nome, telefone1, telefone2, telefone3, email, instagram);

    // Mensagem de retorno
    if (resultado == 1) {
        printf("\nContato criado com sucesso!\n");
    } else {
        printf("\nFalha ao criar contato.\n");
    }

    return 0;
}