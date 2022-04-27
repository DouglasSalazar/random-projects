/*****************************************************************************************************************
	TRABALHO 1: MONTADOR ( ENTREGA EM 30/03/2015)
	Desenvolvido por Douglas Correia Salazar
	RMG: 27300
		
	chamada do programa e dado por ./nome nome.mips 
	apartir dessa chamada de um arquivo .mips e gerando um arquivo nome.bin
	Baseando na arquitetura MIPS

******************************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int ver_regist(char linha[100],int cont, int menu,char registradores[3][10], int ad){
int i=0,p=0,aux=0,aux1=0,j=0;
char regist[16][4];

/**************************************REGISTRADORES PARA COMPARAÇÃO*****************************************************************/
    strcpy(regist[0],"r0");
    strcpy(regist[1],"r1");
    strcpy(regist[2],"r2");
    strcpy(regist[3],"r3");
    strcpy(regist[4],"r4");
    strcpy(regist[5],"r5");
    strcpy(regist[6],"r6");
    strcpy(regist[7],"r7");
    strcpy(regist[8],"r8");
    strcpy(regist[9],"r9");
    strcpy(regist[10],"r10");
    strcpy(regist[11],"r11");
    strcpy(regist[12],"r12");
    strcpy(regist[13],"r13");
    strcpy(regist[14],"r14");
    strcpy(regist[15],"r15");
/***************************************************************************************************************/
    p=0;
    switch(menu){
/**************************************CASE 1 PARAMETRO*************************************************************************/
        case 1:
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=',' && linha[cont]!='\0' && linha[cont]!= 47){ /*Copia de registrador da linha completa*/
                if(linha[cont]!=' ' && linha[cont]!= '\r'){
                    registradores[0][i]=linha[cont];
                    i++;
                }
                cont++;
            }
            registradores[0][i]='\0';
            if(linha[cont] == '\n' || linha [cont]== '\0' || (linha[cont]== 47 && linha[cont+1]== 47 && linha[cont+2]!= 47)){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[0],regist[i])==0){/*verificação se registrador existe retorna 1 se nao 0*/
                        return 1;
                        p++;
                    }
                }
                if(p==0 && ad==1){/*em caso de p==0 sinal que nao e um registrador mas pode ser um numero*/
                    aux=strlen(registradores[0]);
                    if(registradores[0][0]== 45){/*validação se e oou nao negativo*/
                        i=1;
                        aux1++;
                    }else{
                        i=0;
                    }
                    for(i=i;i<aux;i++){
                        if(registradores[0][i] < 48 || registradores[0][i] > 57){/*comparação se e um numero*/
                            return 0;
                        }else{
                            aux1++;
                        }
                    }
                    if(aux1==aux){
                        return 1;
                    }
                }
                if (p==0){
                    return 0;
                }
            }else{
                return 0;
            }
        break;
/*********************************************CASE 2 PARAMETROS******************************************************************/
        case 2:
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=','&& linha[cont]!='\0' && linha[cont]!= 47){/* copia do primeiro parametro da varival linha*/
                registradores[0][i]=linha[cont];
                cont++;
                i++;
            }
            registradores[0][i]='\0';
            if(linha [cont]== ','){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[0],regist[i])==0){/*verificação se e ou nao um registrador*/
                        p++;
                    }
                }
            }else{
                return 0;
            }
            i=0;
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=','&& linha[cont]!='\0' && linha[cont]!= 47){/*copia do segundo parametro*/
                if(linha[cont]!=' ' && linha[cont]!= '\r'){
                    registradores[1][i]=linha[cont];
                    i++;
                }
                cont++;
            }
            registradores[1][i]='\0';
            if(linha [cont]== '\n' || linha [cont]== '\0' || (linha[cont]== 47 && linha[cont+1]== 47 && linha[cont+2]!= 47)){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[1],regist[i])==0){/*verificação se e ou nao um registrador*/
                        p++;
                    }
                }
                if(p==1 && ad==1){
                    aux=strlen(registradores[1]);
                    if(registradores[1][0]== 45){/* se nao e um registrador pode ser um numero (verificação se e negativo)*/
                        i=1;
                        aux1++;
                    }else{
                        i=0;
                    }
                    for(i=i;i<aux;i++){
                        if(registradores[1][i] < 48 || registradores[1][i] > 57){/*verificação se e um numero*/
                            aux1=-30;
                        }else{
                            aux1++;
                        }
                    }
                    if(aux1==aux){
                        p++;
                    }
                    if(aux1<0){/*em caso de nao se um numero pode conter parenteses*/
                        for(i=0;i<aux;i++){
                            if(registradores[1][i] == '('){/*copia tudo que tem antes do parentese*/
                                j=i;
                            }
                        }
                        if(j!=0){
                            aux1=j;
                            j++;
                            i=0;
                            while(registradores[1][j] != ')' && j<aux){/*copia do registrador que esta no meio do parenteses*/
                                registradores[2][i]=registradores[1][j];
                                i++;
                                j++;
                            }
                            registradores[1][aux1]='\0';
                            registradores[2][i]='\0';
			    aux=strlen(registradores[1]);
			    aux1=0;
			    if(registradores[1][0]== 45){/*se nao for pode ser um numero (validação de negativo)*/
				i=1;
				aux1++;
			    }else{
				i=0;
			    }
			    for(i=i;i<aux;i++){
				if(registradores[1][i] < 48 || registradores[1][i] > 57){/*validação se e uum numero*/
				    return 0;
				}else{
				    aux1++;
				}
			    }
			    if(aux1==aux){
				p++;
			    }
			    for(i=0;i<16;i++){
				    if(strcmp(registradores[0],regist[i])==0){/*validação se e ou nao registrador*/
					p++;
				    }
			    }
                        }
			if(p==3){
                   		 return 1;
                	}else{
                    		return 0;
                	}
                    }
                }
                if(p==2){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        break;
/****************************************CASE 3 PARAMETROS***********************************************************************/
        case 3:
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=',' && linha[cont]!='\0' && linha[cont]!= 47){/* copia do primeiro parametro*/
                registradores[0][i]=linha[cont];
                cont++;
                i++;
            }
            registradores[0][i]='\0';
            if(linha [cont]== ','){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[0],regist[i])==0){/*validação se e ou nao registrador*/
                        p++;
                    }
                }
            }else{
                return 0;
            }
            i=0;
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=',' && linha[cont]!='\0' && linha[cont]!= 47){/*copia segundo parametro*/
                registradores[1][i]=linha[cont];
                cont++;
                i++;
            }
            registradores[1][i]='\0';
            if(linha [cont]== ','){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[1],regist[i])==0){/*validação se e ou nao registrador*/
                        p++;
                    }
                }
            }else{
                return 0;
            }
            i=0;
            cont++;
            while(linha[cont]!='\n' && linha[cont]!=',' && linha[cont]!='\0' && linha[cont]!= 47){/*copia do terceiro parametro*/
                if(linha[cont]!=' ' && linha[cont]!= '\r'){
                    registradores[2][i]=linha[cont];
                    i++;
                }
                cont++;
            }
            registradores[2][i]='\0';
            if(linha [cont]== '\n' || linha [cont]== '\0' || (linha[cont]== 47 && linha[cont+1]== 47 && linha[cont+2]!= 47)){
                for(i=0;i<16;i++){
                    if(strcmp(registradores[2],regist[i])==0){/*verificação se e ou um registrador*/
                        p++;
                    }
                }
                if(p==2 && ad==1){
                    aux=strlen(registradores[2]);
                    if(registradores[2][0]== 45){/*se nao for pode ser um numero (validação de negativo)*/
                        i=1;
                        aux1++;
                    }else{
                        i=0;
                    }
                    for(i=i;i<aux;i++){
                        if(registradores[2][i] < 48 || registradores[2][i] > 57){/*validação se e uum numero*/
                            return 0;
                        }else{
                            aux1++;
                        }
                    }
                    if(aux1==aux){
                        p++;
                    }
                }
                if(p==3){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        break;
    }
    return 0;
}

void erro(char linha[100], int j,char nome_bin[30]){
char erro[50];

    printf("Erro!!\nLinha: [%d]\n%s\n",j,linha);/*em caso de algum erro mostra a linha e sai do programa*/
    strcpy(erro,"rm ");    
    strcat(erro,nome_bin);
    system(erro);
    exit(0);
}

void conversor(char registradores[3][10], int menu ,int reg_n[3]){
char aux[10];
int i=0;

        switch (menu){
            case 1:
                if(registradores[0][0]=='r'){/*e um registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[0][i];/*copia somente do numero do registrador*/
                    }while(registradores[0][i]!='\0');
                }else{/* e um numero*/
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[0][i];
                    }while(registradores[0][i]!='\0');/*copia do numero*/
                }
                reg_n[0]=atoi(aux);/*conversao para inteiro*/
            break;
            case 2:
                if(registradores[0][0]=='r'){/*e registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[0][i];
                    }while(registradores[0][i]!='\0');/*copia somente do numero registrador*/
                }else{/*e um numero */
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[0][i];
                    }while(registradores[0][i]!='\0');/*copia do numero*/
                }
                reg_n[0]=atoi(aux);/*conversao para inteiro*/
                if(registradores[1][0]=='r'){/*e um registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[1][i];
                    }while(registradores[1][i]!='\0');/*copia somente do numero*/
                }else{/* e um numero */
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[1][i];
                    }while(registradores[1][i]!='\0');/*copia do numero*/
                }
                reg_n[1]=atoi(aux);/*conversao para int*/
            break;
            case 3:
                if(registradores[0][0]=='r'){/*e um registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[0][i];/*retira somente o numero*/
                    }while(registradores[0][i]!='\0');
                }else{/*e um numero*/
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[0][i];/*copia do numero*/
                    }while(registradores[0][i]!='\0');
                }
                reg_n[0]=atoi(aux);/*converte int*/
                if(registradores[1][0]=='r'){/*e um registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[1][i];
                    }while(registradores[1][i]!='\0');/*retira somente o numero*/
                }else{/*e um numero*/
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[1][i];
                    }while(registradores[1][i]!='\0');/*faz a copia*/
                }
                reg_n[1]=atoi(aux);/*converte int*/
                if(registradores[2][0]=='r'){/*e um registrador*/
                    i=0;
                    do{
                        i++;
                        aux[i-1]=registradores[2][i];
                    }while(registradores[2][i]!='\0');/*retira somente o int*/
                }else{/* e um numero*/
                    i=-1;
                    do{
                        i++;
                        aux[i]=registradores[2][i];/*faz a copia*/
                    }while(registradores[2][i]!='\0');
                }
                reg_n[2]=atoi(aux);/*converte int*/
            break;
        }
}

void arq (char arq_mps[30]){

FILE *mps;
FILE *Bin;
char linha[100];
char comand[10];
char *result;
int cont=0,j=0,aux=0;
char registradores[3][10];
int reg_n[3];
int ad=0;
char nome_bin[30];

int32_t opc;
int32_t opc3;
uint16_t opc2;

    mps=fopen(arq_mps,"r");/*abertura arquivo mips*/
    j=0;
    while(arq_mps[j]!='.'){
        nome_bin[j]=arq_mps[j];
        j++;
    }
    nome_bin[j]='\0';
    strcat(nome_bin,".bin");/*concatenaçnao de nome mips para bin*/
    Bin=fopen(nome_bin, "wb");
    j=0;
    if (mps != NULL && Bin!= NULL){
        while(!feof(mps)){
            cont=0;
            j++;
            result=fgets(linha,50,mps);/*leitura linha a linha*/
            opc=0;
            if(result){
                while(linha[cont]!= 32 && linha[cont]!= '\n' && linha[cont]!='\r' && cont<10){/*copia do primeiro comando*/
                    comand[cont]=linha[cont];
                    cont++;
                }
                comand[cont]='\0';
/**************************************ADD*************************************************************************/
                if(strcmp(comand,"add")==0){
                    ad=0;
		    aux=ver_regist(linha,cont,3,registradores,ad);/*FUNÇÃO DE VALIDAÇÃO DE PARAMETROS*/
                    if(aux==1){
                        conversor(registradores,3,reg_n);/*CONVERSAO PARA INTEIRO*/
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;/*ADICIONADO OPCODE*/
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 2 << 4;
                            fwrite(&opc,sizeof(opc),1,Bin);/*GRAVAÇÃO OPCODE*/
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************ADDI*************************************************************************/
                }else if(strcmp(comand,"addi")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 2 << 28;
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SUB*************************************************************************/
                }else if(strcmp(comand,"sub")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 34 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************MULT*************************************************************************/
                }else if(strcmp(comand,"mult")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,2,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | reg_n[0] << 21;
                            opc=opc | reg_n[1] << 16;
                            opc=opc | 24 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************DIV*************************************************************************/
                }else if(strcmp(comand,"div")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,2,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | reg_n[0] << 21;
                            opc=opc | reg_n[1] << 16;
                            opc=opc | 26 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************AND*************************************************************************/
                }else if(strcmp(comand,"and")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 36 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************ANDI*************************************************************************/
                }else if(strcmp(comand,"andi")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 3 << 28;
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************OR*************************************************************************/
                }else if(strcmp(comand,"or")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 37 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************ORI*************************************************************************/
                }else if(strcmp(comand,"ori")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 13 << 26;
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************STL*************************************************************************/
                }else if(strcmp(comand,"slt")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 42 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SLTI*************************************************************************/
                }else if(strcmp(comand,"slti")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 10 << 26;
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************XOR*************************************************************************/
                }else if(strcmp(comand,"xor")==0){
		    ad=0;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | reg_n[1] << 21;
                            opc=opc | reg_n[2] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | 38 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SLL*************************************************************************/
                }else if(strcmp(comand,"sll")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
			opc3 = 0;
			opc3 = opc3 | reg_n[2];
			opc3 = opc3 & 0x1f;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | reg_n[1] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | opc3 << 6;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SRL*************************************************************************/
                }else if(strcmp(comand,"srl")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
			opc3 = 0;
			opc3 = opc3 | reg_n[2];
			opc3 = opc3 & 0x1f;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | reg_n[1] << 16;
                            opc=opc | reg_n[0] << 11;
                            opc=opc | opc3 << 6;
                            opc=opc | 2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************J*************************************************************************/
                }else if(strcmp(comand,"j")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,1,registradores,ad);
                    if(aux==1){
                        conversor(registradores,1,reg_n);
                        opc3=0;
                        opc3= opc3 | reg_n[0] << 0;
                        opc3 = opc3 & 0x3ffffff;
			opc=opc | 2 << 26;
                        opc=opc | opc3 << 0;
                        fwrite(&opc,sizeof(opc),1,Bin);
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************BEQ*************************************************************************/
                }else if(strcmp(comand,"beq")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 1 << 28;
                            opc=opc | reg_n[0] << 21;
                            opc=opc | reg_n[1] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************BNE*************************************************************************/
                }else if(strcmp(comand,"bne")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,3,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[2] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[1]>=0 && reg_n[1]<16)){
                            opc=opc | 5 << 26;
                            opc=opc | reg_n[0] << 21;
                            opc=opc | reg_n[1] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************BGEZ*************************************************************************/
                }else if(strcmp(comand,"bgez")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,2,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if(reg_n[0]>=0 && reg_n[0]<16){
                            opc=opc | 1 << 26;
                            opc=opc | reg_n[0] << 21;
                            opc=opc | 1 << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************BGTZ************************************************************************/
                }else if(strcmp(comand,"bgtz")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,2,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if(reg_n[0]>=0 && reg_n[0]<16){
                            opc=opc | 7 << 26;
                            opc=opc | reg_n[0] << 21;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************LB*************************************************************************/
                }else if(strcmp(comand,"lb")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) &&(reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | 8 << 28;
                            opc=opc | reg_n[2] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SB*************************************************************************/
                }else if(strcmp(comand,"sb")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | 10 << 28;
                            opc=opc | reg_n[2] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************LW*************************************************************************/
                }else if(strcmp(comand,"lw")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | 35 << 26;
                            opc=opc | reg_n[2] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SW*************************************************************************/
                }else if(strcmp(comand,"sw")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,3,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if((reg_n[0]>=0 && reg_n[0]<16) && (reg_n[2]>=0 && reg_n[2]<16)){
                            opc=opc | 43 << 26;
                            opc=opc | reg_n[2] << 21;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************LUI*************************************************************************/
                }else if(strcmp(comand,"lui")==0){
		    ad=1;
                    aux=ver_regist(linha,cont,2,registradores,ad);
                    if(aux==1){
                        conversor(registradores,2,reg_n);
                        opc2=0;
                        opc2= opc2 | reg_n[1] << 0;
                        if(reg_n[0]>=0 && reg_n[0]<16){
                            opc=opc | 15 << 26;
                            opc=opc | reg_n[0] << 16;
                            opc=opc | opc2 << 0;
                            fwrite(&opc,sizeof(opc),1,Bin);
                        }else{
                            erro(linha,j,nome_bin);
                        }
                    }else{
                        erro(linha,j,nome_bin);
                    }
/**************************************SYCALL*************************************************************************/
                }else if(strcmp(comand,"syscall")==0){
                    opc = opc | 12 << 0;
                    fwrite(&opc,sizeof(opc),1,Bin);
/**************************************READB*************************************************************************/
                }else if(strcmp(comand,"readb")==0){
		    opc=opc | 60 << 26;
                    fwrite(&opc,sizeof(opc),1,Bin);
/**************************************WRITEB*************************************************************************/
                }else if(strcmp(comand,"writeb")==0){
                    opc=opc | 61 << 26;
                    fwrite(&opc,sizeof(opc),1,Bin);
                }else if((comand[0]=='/' && comand[1]=='/' && comand[2]!='/') || strcmp(comand,"\n")==0 || strcmp(comand,"\r")==0 || strcmp(comand," ")==0 || strcmp(comand,"\0")==0){

                }else{
                    erro(linha,j,nome_bin);
                }
            }
        }
        fclose(mps);
        fclose(Bin);
    }else{
        printf("\nErro ao Abrir o Arquivo\n");
    }
}

int main(int argc, char * argv[]){
char arv[30];
    if(argc>0){
	strcpy(arv, argv[1]);
	arq(arv);
    }else{
	printf("ERRO!!\n");
    }
    return 0;
}
