#include <stdio.h> 
#include <string.h>
// Define a estrutura Contato para armazenar as informações de cada contato.
struct Contato {
    char nome[50];
    char telefone1[20];
    char telefone2[20];
    char telefone3[20];
    char email[50];
    char instagram[50];
    int numeroAcessos;
};

#define MAX_CONTATOS 255 
struct Contato agenda[MAX_CONTATOS];
int totalContatos = 0; 


// Função para adicionar o dígito 9 a números de telefone que não o tenham
int adicionarNove(int quantidadeDigitos) {
    int telefonesModificados = 0; // Contador para o número de telefones que foram modificados.
    struct Contato aux[MAX_CONTATOS]; // vetor auxiliar para armazenar temporariamente dados dos contatos.

    // Vetores para marcar quais dos números de telefone contato são telefones fixos.
    int tel_fixos1[MAX_CONTATOS];
    int tel_fixos2[MAX_CONTATOS];
    int tel_fixos3[MAX_CONTATOS];

    // Inicializa os marcadores de telefone fixo com 0.
    for(int i = 0; i < MAX_CONTATOS; i++) {
        tel_fixos1[i] = 0;
    }
    // Percorre todos os contatos para verificar se o telefone1 é um telefone fixo.
    for(int i = 0; i < totalContatos; i++) {
        if(agenda[i].telefone1[0] >= '6') // Assumimos que números de celular começam com '6' ou um dígito maior.
            continue; // Pula se o número parecer ser de celular.
        else {
            strcpy(aux[i].telefone1, agenda[i].telefone1); // Copia o número fixo para o vetor auxiliar.
            tel_fixos1[i] = i; // Marca o  telefone como fixo.
        }
    }
    // Repete a verificação para o telefone2.
    for(int i = 0; i < MAX_CONTATOS; i++) {
        tel_fixos2[i] = 0;
    }
    for(int i = 0; i < totalContatos; i++) {
        if(agenda[i].telefone2[0] >= '6')
            continue;
        else {
            strcpy(aux[i].telefone2, agenda[i].telefone2);
            tel_fixos2[i] = i;
        }
    }
    // Repete a verificação para o telefone3.
    for(int i = 0; i < MAX_CONTATOS; i++) {
        tel_fixos3[i] = 0;
    }
    for(int i = 0; i < totalContatos; i++) {
        if(agenda[i].telefone3[0] >= '6')
            continue;
        else {
            strcpy(aux[i].telefone3, agenda[i].telefone3);
            tel_fixos3[i] = i;
        }
    }

    // Percorre todos os contatos para adicionar 9 aos números de telefone, se necessário.
    for (int i = 0; i < totalContatos; i++) {
        // Verifica se telefone1 existe e se seu comprimento é menor que a quantidade de dígitos padrão de um número de celular.
        if (strlen(agenda[i].telefone1) > 0 && strlen(agenda[i].telefone1) < quantidadeDigitos) {
            char numeroAtualizado[20]; // Buffer para o número atualizado.
            strcpy(numeroAtualizado, "9"); // Começa o novo número com 9.
            strcat(numeroAtualizado, agenda[i].telefone1); // Concatena o número original.
            strcpy(agenda[i].telefone1, numeroAtualizado); // Atualiza o telefone do contato.
            telefonesModificados++; // Incrementa o contador de telefones modificados.
        }
        // Repete a lógica para telefone2.
        if (strlen(agenda[i].telefone2) > 0 && strlen(agenda[i].telefone2) < quantidadeDigitos) {
            char numeroAtualizado[20];
            strcpy(numeroAtualizado, "9");
            strcat(numeroAtualizado, agenda[i].telefone2);
            strcpy(agenda[i].telefone2, numeroAtualizado);
            telefonesModificados++;
        }
        // Repete a lógica para telefone3.
        if (strlen(agenda[i].telefone3) > 0 && strlen(agenda[i].telefone3) < quantidadeDigitos) {
            char numeroAtualizado[20];
            strcpy(numeroAtualizado, "9");
            strcat(numeroAtualizado, agenda[i].telefone3);
            strcpy(agenda[i].telefone3, numeroAtualizado);
            telefonesModificados++;
        }
    }
    // Volta os números de telefone fixo originais a partir do vetor auxiliar.
    for(int i = 0; i < totalContatos; i++) {
        if(tel_fixos1[i] != 0) // Se o primeiro telefone deste contato foi marcado como fixo.
            strcpy(agenda[i].telefone1, aux[i].telefone1); // Volta o da cópia auxiliar.
    }
    // Repete a lógica para o segundo telefone.
    for(int i = 0; i < totalContatos; i++) {
        if(tel_fixos2[i] != 0)
            strcpy(agenda[i].telefone2, aux[i].telefone2);
    }
    // Repete a lógica para o terceiro telefone.
    for(int i = 0; i < totalContatos; i++) {
        if(tel_fixos3[i] != 0)
            strcpy(agenda[i].telefone3, aux[i].telefovetor
    }

    return telefonesModificados; // Retorna o número total de telefones modificados.
}
