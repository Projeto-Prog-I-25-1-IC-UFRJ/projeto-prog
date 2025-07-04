/*(6) Aglutinar dois contatos.
● Essa função está sendo criada para ser usada caso o usuário perceba que, por engano, salvou duas
vezes o mesmo contatinho na agenda. Ela deve receber dois índices, correspondentes às posições no
vetor dos contatinhos que serão aglutinados. As informações serão agregada em um único contatinho,
correspondente ao primeiro índice fornecido, da seguinte forma:
● Todas as informações do contatinho armazenado na posição indice1 são mantidas;
● Para cada informação armazenada no contatinho armazenado na posição indice2, verifique se
esta informação já aparece no contatinho do índice 1, caso não apareça, inclua essa informação
no contatinho índice 1.
● Depois, apague o contatinho do índice 2 (pode chamar a função para excluir contato, feita por
outro grupo.
● A partir da interface da função para buscar contatos, crie uma interface que mostre na tela todos os
contatos repetidos (com um mesmo nome fornecido), com um número para cada um. O usuário poderá
então escolher os dois números dos contatos que deseja aglutinar.*/

#include <string.h>
#include <stdio.h>

#define MAX 100

typedef struct {
    char nome[1024];
    char t1[1024];
    char t2[1024];
    char t3[1024];
    char email[1024];
    char insta[1024];
    int acessos;
} contato;

int excluir_contato(contato lista[], int tam, int indice); // função de excluir contatos de outro grupo

// Função aglutinar contatos

int aglutinar_contato(contato contatos[],int cc, int i1, int i2) {
    // checar se os telefones do contato 2 são todos diferentes dos do contato 1
    if (strcmp(contatos[i2].t1, contatos[i1].t1) != 0 &&
        strcmp(contatos[i2].t1, contatos[i1].t2) != 0 &&
        strcmp(contatos[i2].t1, contatos[i1].t3) != 0) {
        if (contatos[i1].t1[0] == '\0') strcpy(contatos[i1].t1, contatos[i2].t1);
// checar se espaço pros telefones está vazio no contato 1 - se tiver, deve ser preenchido com as informações do contato 2, se não estiver, deve ser matido
        else if (contatos[i1].t2[0] == '\0') strcpy(contatos[i1].t2, contatos[i2].t1);
        else if (contatos[i1].t3[0] == '\0') strcpy(contatos[i1].t3, contatos[i2].t1);
    }

    if (strcmp(contatos[i2].t2, contatos[i1].t1) != 0 &&
        strcmp(contatos[i2].t2, contatos[i1].t2) != 0 &&
        strcmp(contatos[i2].t2, contatos[i1].t3) != 0) {
        if (contatos[i1].t1[0] == '\0') strcpy(contatos[i1].t1, contatos[i2].t2);
        else if (contatos[i1].t2[0] == '\0') strcpy(contatos[i1].t2, contatos[i2].t2);
        else if (contatos[i1].t3[0] == '\0') strcpy(contatos[i1].t3, contatos[i2].t2);
    }

    if (strcmp(contatos[i2].t3, contatos[i1].t1) != 0 &&
        strcmp(contatos[i2].t3, contatos[i1].t2) != 0 &&
        strcmp(contatos[i2].t3, contatos[i1].t3) != 0) {
        if (contatos[i1].t1[0] == '\0') strcpy(contatos[i1].t1, contatos[i2].t3);
        else if (contatos[i1].t2[0] == '\0') strcpy(contatos[i1].t2, contatos[i2].t3);
        else if (contatos[i1].t3[0] == '\0') strcpy(contatos[i1].t3, contatos[i2].t3);
    }

    // se email do contato 1 estiver vazio, deve ser preenchido com o do contato 2
    if (contatos[i1].email[0] == '\0') {
        strcpy(contatos[i1].email, contatos[i2].email);
    }

    // se instagram do contato 1 estiver vazio, deve ser preenchido com o do contato 2
    if (contatos[i1].insta[0] == '\0') {
        strcpy(contatos[i1].insta, contatos[i2].insta);
    }

    // exclui contato 2
    excluir_contato(contatos, cc, i2);
}

// função de buscar contatos retorna quantos contatos têm o mesmo nome

int busca_contato(contato lista[],int aa, char nome[], int indices[]){
    
    int cont = 0;
    for (int i = 0; i < aa; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            indices[cont++] = i;
        }
    }
    return cont;
}

// interface para buscar e aglutinar contatos com o mesmo nome
int contatos_repetidos(contato lista[], int ba){

    char nm[1024];
    printf("Digite o nome pra procurar contatos repetidos: ");
    scanf(" %[^\n]", nm);

    int numc[MAX];   
    int a = busca_contato(lista, ba, nm, numc);
    
    if (a<=1){
        printf("Não há contatos repetidos com esse nome.\n");
        return ba;
    }
    printf("Contatos encontrados:\n");
    for(int i = 0; i<a; i++){
        printf("(%d) %s | %s | %s | %s | %s | %s\n",
        numc[i],
        lista[numc[i]].nome,
        lista[numc[i]].t1,
        lista[numc[i]].t2,
        lista[numc[i]].t3,
        lista[numc[i]].email,
        lista[numc[i]].insta);
    }

    int i1, i2;
    printf("Digite os índices dos dois contatos que deseja aglutinar: ");
    scanf("%d %d", &i1, &i2);
    
    if (i1<0 || i1>=ba || i2<0 || i2>=ba|| i1==i2){
        printf("Indices não existem.\n");
        return ba;
    }
    ba = aglutinar_contato(lista, ba, i1, i2);

    printf("Contatos aglutinados.\n");

    return ba;
}
int main() {
    contato lista[MAX] = {};

    int tam = 5;

    // loop de teste para fazer várias aglutinações 
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        tam = contatos_repetidos(lista, tam); // chama a interface para aglutinar
        printf("\nDeseja aglutinar mais contatos? (s/n): ");
        scanf(" %c", &continuar);
    }

    // Mostrar lista final
    printf("\nLista final de contatos:\n");
    for (int i = 0; i < tam; i++) {
        printf("[%d] %s | %s, %s, %s | %s | %s\n",
               i,
               lista[i].nome,
               lista[i].t1,
               lista[i].t2,
               lista[i].t3,
               lista[i].email,
               lista[i].insta);
    }

    return 0;
}