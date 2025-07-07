/* FUNÇÃO 3 */
/* LUCAS DOTTO DE OLIVEIRA e GUILHERME DE SOUZA BARAUNA */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

#define vetor contatinhos
#define tam num_contatinhos

// Função acesso retorna o indice do nome procurado e atualiza o numero de acessos do contato. Se o nome não for encontrado a função retorna -1.
int buscar_contato(char busca[]){
    int n = strlen(busca);
    int j = 0;
    for(; j < tam; j++){
        for(int i = 0; i<n; i++){
            if(vetor[j].nome[i] != busca[i]){
                
                break;
            }
            if(i == n-1 ){
                
                vetor[j].num_acessos++;
                return j;
            }
        }

    }
    return -1;
}

// função posição retorna o número de contatos com o nome buscado pelo usuário. 
int numero_de_contatos_iguais(int indice){
    char busca[TAMANHO_STRING];
    strcpy(busca, contatinhos[indice].nome);

    int n = strlen(busca);
    int cont  = 0;
    for(int j = 0; j < tam; j++){
        for(int i = 0; i<n; i++){
            if(vetor[j].nome[i] != busca[i]){
                
                break;
            }
            if(i == n-1 ){
                cont ++;
            }
        }

    }   
    return cont;

}

