/* FUNÇÃO 1 */
/* JOAO PEDRO COSTA e LEONARDO TERRES */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

#define MAX_STRING TAMANHO_STRING

#define agenda contatinhos
#define totalContatos num_contatinhos

// Função 1: cria um novo contato na agenda
// Somente o nome é obrigatório (e constante)
// Os demais campos podem ser strings vazias
int criar_contato(const char* nome, char telefone1[], char telefone2[], char telefone3[], char email[], char instagram[]) {
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
    agenda[totalContatos].num_acessos = 0;  // Inicializa com zero acessos

    totalContatos++;  // Atualiza o número total de contatos
    return 1;  // Retorna sucesso
}



