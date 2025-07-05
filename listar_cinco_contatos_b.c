/* FUNÇÃO 9 */
/* LEONARDO OLIVEIRA e GABRIEL MAIA */

#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

// Estrutura do contato
typedef struct {
    char nome[100];
    char telefone1[20];
    char telefone2[20];
    char telefone3[20];
    char email[100];
    char instagram[100];
    int acessos;
} Contato;

// Vetor global de contatos
Contato contatos[MAX_CONTATOS];
int total_contatos = 0;

// Função que lista os 5 contatos mais acessados 
void listar_contatos_mais_acessados(Contato top5[5]) {
    Contato temp[MAX_CONTATOS];

    // Copia os contatos existentes para um vetor temporário
    for (int i = 0; i < total_contatos; i++) {
        temp[i] = contatos[i];
    }

    // Ordena em ordem decrescente de acessos (bubble sort simples)
    for (int i = 0; i < total_contatos - 1; i++) {
        for (int j = 0; j < total_contatos - i - 1; j++) {
            if (temp[j].acessos < temp[j + 1].acessos) {
                Contato aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }

    // Copia os 5 primeiros contatos ordenados para o vetor de saída
    for (int i = 0; i < 5 && i < total_contatos; i++) {
        top5[i] = temp[i];
    }
}

// Função auxiliar para adicionar contatos para teste
void adicionar_contato(char nome[], int acessos) {
    if (total_contatos < MAX_CONTATOS) {
        strcpy(contatos[total_contatos].nome, nome);
        contatos[total_contatos].acessos = acessos;
        total_contatos++;
    }
}

int main() {
    // Adiciona alguns contatos fictícios
    adicionar_contato("Alice", 10);
    adicionar_contato("Bob", 25);
    adicionar_contato("Carlos", 15);
    adicionar_contato("Diana", 5);
    adicionar_contato("Eduarda", 30);
    adicionar_contato("Felipe", 20);
    adicionar_contato("Gabi", 12);

    // Vetor para receber os top 5
    Contato top5[5];

    listar_contatos_mais_acessados(top5);

    printf("Top 5 contatos mais acessados:\n");
    for (int i = 0; i < 5 && i < total_contatos; i++) {
        printf("%dº - %s (acessos: %d)\n", i+1, top5[i].nome, top5[i].acessos);
    }

    return 0;
}
