/* FUNÇÃO 2 */
/* JOAO MIGUEL SALES DE ALENAR e ALEXANDRE RIMES BANDEIRA */

#include<stdio.h>
#include<string.h>
typedef struct Tcadastro{
    char nome[50];
    char telefone1[12];
    char telefone2[12];
    char telefone3[12];
    char email[70];
    char insta[50];
    int acessos;
}cadastro;
cadastro contatos[50];

int verificaNum(char a[]){
    for(int i=0;i<strlen(a);i++)
        if(a[i]>57 || a[i]<48)
            return 0;
    return 1;
}

int verificaEmail(char a[]){
    int Bolean=0;
    if(a[0]=='@'){return 0;}
    for(int i=1;i<strlen(a);i++){
        if(a[i]=='@'){Bolean=1;}
        if(Bolean&&a[i]=='.' ){return 1;}
    }
    return 0;
}

int verificaInsta(char a[]){
	if(a[0]=='@'){return 1;}
	return 0;
}

int AtualizaCttGlobal(int indice, int codInf, char novaInf[]){
    switch (codInf)
    {
    case 1:
        strcpy(contatos[indice].nome,novaInf);
        break;
    case 2:
        strcpy(contatos[indice].telefone1,novaInf);
        break;
    case 3:
        strcpy(contatos[indice].telefone2,novaInf);
        break;
    case 4:
        strcpy(contatos[indice].telefone3,novaInf);
        break;
    case 5:
        strcpy(contatos[indice].email,novaInf);
        break;
    case 6:
        strcpy(contatos[indice].insta,novaInf);
        break;
    }
    if(contatos[indice].nome=="?"){strcpy(contatos[indice].email,"Exclamodio");}
}

int ValidacaoGlobal(int indice, int codInf, char novaInf[]){
    if(codInf<=6 && codInf>0){
	    switch (codInf)
	    {
	    case 1:
	        break;
	    case 2://numero
	        if(verificaNum(novaInf))
			{ AtualizaCttGlobal(indice,codInf,novaInf);break;}        
	        return -1;
	        
	    case 3://numero
			if(verificaNum(novaInf))
			{AtualizaCttGlobal(indice,codInf,novaInf);break;}
			return -1;   
			
	    case 4://numero
			if(verificaNum(novaInf))
			{AtualizaCttGlobal(indice,codInf,novaInf);break;}
	        return -1;
	        
	    case 5://email
	    	if(verificaEmail(novaInf))
	    	{AtualizaCttGlobal(indice,codInf,novaInf);break;}    
	    	return -1;
	    	
	    case 6://insta
	    	if(verificaInsta(novaInf)){
	    	AtualizaCttGlobal(indice,codInf,novaInf);break;}    
	        return -1;
    }

    }

}

int ValidacaoLocal(char novaInf[],int codInf){
    int result=1;
    if(codInf>6 || codInf<0)
        return 0;

    switch (codInf)
    {

        case 2://numero
            result=verificaNum(novaInf);
            break;
        case 3://numero
            result=verificaNum(novaInf);
            break;
        case 4://numero
            result=verificaNum(novaInf);
            break;
        case 5://email
            result=verificaEmail(novaInf);
            break;
        case 6://insta
            result=verificaInsta(novaInf);
            break;
        }
    return result;
}

cadastro AtualizaCttLocal(cadastro cad, int codInf, char novaInf[]){

    if(!ValidacaoLocal(novaInf,codInf)){
            printf("\n---Nova informação invalida---");
            return cad;
    }
    
    switch (codInf)
    {
    case 1:
        strcpy(cad.nome,novaInf);
        break;
    case 2:
        strcpy(cad.telefone1,novaInf);
        break;
    case 3:
        strcpy(cad.telefone2,novaInf);
        break;
    case 4:
        strcpy(cad.telefone3,novaInf);
        break;
    case 5:
        strcpy(cad.email,novaInf);
        break;
    case 6:
        strcpy(cad.insta,novaInf);
        break;
    }

    printf("\n---Nova informação atualizada---");
    return cad;
}

int main(){
	
}
