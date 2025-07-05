/* FUNÇÃO 9 */
/* NICOLAS GOMES e BERNARDO MAGNO */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// Estrutura de dados para um contato.
typedef struct {
    char nome[100];
    char telefone1[15];
    char telefone2[15];
    char telefone3[15];
    char email[100];
    char instagram[100];
    int numero_acessos;
} Contato; 

// Variáveis globais para a agenda de contatos 
#define MAX_CONTATOS 100
Contato agenda[MAX_CONTATOS];
int total_contatos = 0;


// função para listar os 5 contatos mais acessados em ordem decrescente.
Contato* listarCincoMaisAcessados(int* num_retornados) {
    *num_retornados = 0;
    // Retorna nulo se a agenda estiver vazia.
    if (total_contatos == 0) {
        return NULL;
    }

    // Determine quantos contatos vamos retornar máximo de 5 ou o total disponíveL
    int num_para_retornar = (total_contatos >= 5) ? 5 : total_contatos;
    *num_retornados = num_para_retornar;

     // Cria uma cópia da agenda para ser ordenada, preservando a original.
    Contato* agenda_temporaria = (Contato*)malloc(total_contatos * sizeof(Contato));
    if (agenda_temporaria == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para a agenda temporaria.\n");
        return NULL;
    }

    memcpy(agenda_temporaria, agenda, total_contatos * sizeof(Contato));

    // Ordena a cópia da agenda pelo 'numero_acessos' em ordem decrescente (Bubble Sort).
    for (int i = 0; i < total_contatos - 1; i++) {
        for (int j = 0; j < total_contatos - i - 1; j++) {
            if (agenda_temporaria[j].numero_acessos < agenda_temporaria[j+1].numero_acessos) {
                Contato aux = agenda_temporaria[j];
                agenda_temporaria[j] = agenda_temporaria[j+1];
                agenda_temporaria[j+1] = aux;
            }
        }
    }

     // Aloca o vetor final para conter apenas os contatos mais acessados.
    Contato* cinco_mais_acessados_final = (Contato*)malloc(num_para_retornar * sizeof(Contato));
    if (cinco_mais_acessados_final == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para os 5 contatos mais acessados.\n");
        free(agenda_temporaria);
        return NULL;
    }

     // Copia os primeiros contatos da agenda ordenada para o vetor de resultado.
    for (int i = 0; i < num_para_retornar; i++) {
        cinco_mais_acessados_final[i] = agenda_temporaria[i];
    }

    // Libera a memória da cópia e retorna o resultado final.
    free(agenda_temporaria);
    return cinco_mais_acessados_final;
}

// Função auxiliar para criar um novo contato de forma simplificada para teste
void criarContatoTeste(const char* nome, const char* tel1, const char* email, int acessos) {
    if (total_contatos < MAX_CONTATOS) {
        strcpy(agenda[total_contatos].nome, nome);
        strcpy(agenda[total_contatos].telefone1, tel1);
        strcpy(agenda[total_contatos].telefone2, ""); 
        strcpy(agenda[total_contatos].telefone3, ""); 
        strcpy(agenda[total_contatos].email, email);
        strcpy(agenda[total_contatos].instagram, ""); 
        agenda[total_contatos].numero_acessos = acessos;
        total_contatos++;
    } else {
        printf("Agenda cheia! Nao foi possivel adicionar '%s'.\n", nome);
    }
}

// Função main para demonstrar e testar a funcionalidade.
int main() {
    // Carga de dados de exemplo.
    criarContatoTeste("Carlos Lima", "97654-3210", "carlos@email.com", 20);
    criarContatoTeste("Ana Silva", "98765-4321", "ana@email.com", 15);
    criarContatoTeste("Diana Souza", "91234-5678", "diana@email.com", 12);
    criarContatoTeste("Fernanda Oliveira", "95678-1234", "fer@email.com", 10);
    criarContatoTeste("Bruno Costa", "99887-7665", "bruno@email.com", 8);
    criarContatoTeste("Gustavo Pereira", "90909-0909", "guga@email.com", 7);
    criarContatoTeste("Eduardo Santos", "93456-7890", "eduardo@email.com", 3);
    criarContatoTeste("Helena Almeida", "91011-1213", "helena@email.com", 2);
    criarContatoTeste("Igor Rodrigues", "91415-1617", "igor@email.com", 1);

    //printf("Total de contatos na agenda: %d\n", total_contatos);

    Contato* mais_acessados = NULL;
    int num_contatos_retornados = 0;

    mais_acessados = listarCincoMaisAcessados(&num_contatos_retornados);

    // Exibição dos resultados.
    if (mais_acessados != NULL) {
        printf("\n--- %d Contatos Mais Acessados ---\n", num_contatos_retornados);
        for (int i = 0; i < num_contatos_retornados; i++) {
            printf("\nContato #%d\n", i + 1);
            printf("  Nome: %s\n", mais_acessados[i].nome);
            printf("  Telefone 1: %s\n", mais_acessados[i].telefone1);
            printf("  Telefone 2: %s\n", mais_acessados[i].telefone2);
            printf("  Telefone 3: %s\n", mais_acessados[i].telefone3);
            printf("  Email: %s\n", mais_acessados[i].email);
            printf("  Instagram: %s\n", mais_acessados[i].instagram);
            printf("  Acessos: %d\n", mais_acessados[i].numero_acessos);
        }
        // Libera a memória alocada pela função.
        free(mais_acessados);
    } else {
        printf("Nao foi possivel listar os contatos mais acessados ou nao ha contatos na agenda.\n");
    }

    return 0;
}
