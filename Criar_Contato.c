#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 1000  // Tamanho máximo da agenda
#define MAX_STRING 100     // Tamanho máximo das strings (nome, telefone, etc.)

// Estrutura que representa um contato na agenda
typedef struct {
    char nome[MAX_STRING];
    char telefone1[MAX_STRING];
    char telefone2[MAX_STRING];
    char telefone3[MAX_STRING];
    char email[MAX_STRING];
    char instagram[MAX_STRING];
    int acessos;  // Contador de acessos ao contato
} Contato;

// Vetor global que representa a agenda
Contato agenda[MAX_CONTATOS];
int totalContatos = 0;  // Quantidade atual de contatos cadastrados

// Função 1: cria um novo contato na agenda
// Somente o nome é obrigatório (e constante)
// Os demais campos podem ser strings vazias
int criarContato(const char* nome, char telefone1[], char telefone2[], char telefone3[], char email[], char instagram[]) {
    // Verifica se o nome foi fornecido
    if (nome == NULL || strlen(nome) == 0) {
        printf("Erro: o nome é obrigatório.\n");
        return -1;
    }

    // Verifica se ainda há espaço na agenda
    if (totalContatos >= MAX_CONTATOS) {
        printf("Erro: limite de contatos atingido.\n");
        return -1;
    }

    // Copia as informações para a próxima posição disponível no vetor
    strcpy(agenda[totalContatos].nome, nome);
    strcpy(agenda[totalContatos].telefone1, telefone1);
    strcpy(agenda[totalContatos].telefone2, telefone2);
    strcpy(agenda[totalContatos].telefone3, telefone3);
    strcpy(agenda[totalContatos].email, email);
    strcpy(agenda[totalContatos].instagram, instagram);
    agenda[totalContatos].acessos = 0;  // Inicializa com zero acessos

    totalContatos++;  // Atualiza o número total de contatos
    return 1;  // Retorna sucesso
}

// Função auxiliar: remove o caractere '\n' do final das strings lidas com fgets
void removerQuebraLinha(char* str) {
    str[strcspn(str, "\n")] = '\0';
}


