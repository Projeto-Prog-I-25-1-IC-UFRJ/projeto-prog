/* FUNÇÃO 2 */
/* ELIANE PEREIRA DOS SANTOS e BEATRIZ PEREIRA DE JESUS SANTOS */

#include <stdio.h>
#include <string.h>

#include <prog/tipos.h>

#define tContato Contato
#define vetor contatinhos

int atualizar_contato(int indice, int codigo, char inf_n[]) {

	switch(codigo){
    case 1:
		strcpy(vetor[indice].nome, inf_n);
		break;

    case 2:
		strcpy(vetor[indice].telefone1, inf_n);
		break;
		
    case 3:
		strcpy(vetor[indice].telefone2, inf_n);
		break;

    case 4:
		strcpy(vetor[indice].telefone3, inf_n);
		break;

    case 5:
		strcpy(vetor[indice].email, inf_n);
        break;
        
    case 6:
        strcpy(vetor[indice].instagram, inf_n);
        break;
        
    default:
        return -1;
        
	}
    return 1;

}

