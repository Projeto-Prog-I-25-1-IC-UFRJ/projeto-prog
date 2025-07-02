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

// struct de contatos como exemplo

typedef struct {
    char nome [1024];
    char t1 [1024];
    char t2 [1024];
    char t3 [1024];
    char email [1024];
    char insta [1024];
    int acessos;
} contato;

void aglutinar_contato(contato contatos[], int i1, int i2){
    // strcmp()
    if (contatos[i2].t1 != contatos[i1].t1 && contatos[i2].t1 != contatos[i1].t2 && contatos[i2].t1 != contatos[i1].t3){
        if(contatos[i1].t1[0] == '\0'){
            strcpy(contatos[i1].t1, contatos[i2].t1);
        }
        if(contatos[i1].t2[0] == '\0'){
            strcpy(contatos[i1].t2, contatos[i2].t1);
        }
        if(contatos[i1].t3[0] == '\0'){
            strcpy(contatos[i1].t3, contatos[i2].t1);
        }}
    if (contatos[i2].t2 != contatos[i1].t1 && contatos[i2].t2 != contatos[i1].t2 && contatos[i2].t2 != contatos[i1].t3){
        if(contatos[i1].t1[0] == '\0'){
            strcpy(contatos[i1].t1, contatos[i2].t2);
        }
        if(contatos[i1].t2[0] == '\0'){
            strcpy(contatos[i1].t2, contatos[i2].t2);
        }
        if(contatos[i1].t3[0] == '\0'){
            strcpy(contatos[i1].t3, contatos[i2].t2);
        }}
    if (contatos[i2].t3 != contatos[i1].t1 && contatos[i2].t3 != contatos[i1].t2 && contatos[i2].t3 != contatos[i1].t3){
        if(contatos[i1].t1[0] == '\0'){
            strcpy(contatos[i1].t1, contatos[i2].t3);
        }
        if(contatos[i1].t2[0] == '\0'){
            strcpy(contatos[i1].t2, contatos[i2].t3);
        }
        if(contatos[i1].t3[0] == '\0'){
            strcpy(contatos[i1].t3, contatos[i2].t3);
        }}
    
    if(contatos[i1].email[0] == '\0'){
        strcpy(contatos[i1].email, contatos[i2].email);
   }
    if(contatos[i1].insta[0] == '\0'){
        strcpy(contatos[i1].insta, contatos[i2].insta);
    }

   excluir_contato(i2);

   // temos que fazer a interface que com a busca de noms iguais, o usuario escolhe quais aglutinar!!

}

// buscacontatos retorna vetor que tem contatos iguais ao nome do indeice passado
contato[] busca_contato(contato lista[], char nome[]);
int tam_contatos(contato lista[]);
int idx_contato(contato lista[], contato c);

void tela(contato lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        contato ctts[] = busca_contato(lista, lista[i].nome);
        if (tam_contatos(ctts) > 1){
            for (int j = 0 ; j < tam_contatos(ctts); j++){
                printf("%d", idx_contato(lista, ctts[i]));
                printf ("%s", ctts[i].nome)
            }
        }
    }

    print digite os indices que quer aglutinar_contato
    scanf // scaneia indices 
    aglutinar_contato()
}