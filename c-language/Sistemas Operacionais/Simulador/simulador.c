/*************************************************************************
    Trabalho II de SO - SIMULADOR DE ARQUITETURA

    Desenvolvido por Douglas Correia Salazar
    RGM: 
***************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

struct s_regs{
	
	int32_t r[16];
	uint32_t ir;
	uint32_t pc;
	uint32_t base;
	uint32_t limit;
	uint8_t mode;
};
/*Função de inicialização de variavels*/
void inicial(uint8_t MEMORY[1048576],struct s_regs *Regs){
unsigned i;	
    bzero(&*Regs,sizeof(*Regs));/*Funçao zerar todos o bits*/
    for(i=0;i<1048576;i++){
		MEMORY[i]=0;
    }
	for(i=0;i<16;i++){			
		(*Regs).r[i]=0;
    }

	(*Regs).ir=0;
	(*Regs).pc=0;
	(*Regs).limit = 1048575;
	(*Regs).base=0;
	(*Regs).mode=0;
}

/**********************************************Função de corte e operações padrao Mips***********************************************************/
void ADD (struct s_regs *Regs){/*ADD SOMA DOIS REGISTRADORES add $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;/*$s corte */
	aux=(*Regs).ir;
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*$t corte */
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*$d corte */
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r3=aux;

	(*Regs).r[r3] = (*Regs).r[r1] + (*Regs).r[r2]; /*$d = $s + $t*/
}

void ADDI (struct s_regs *Regs){/*Soma registrador a valor inteiro addi $t, $s, imm*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	(*Regs).r[r2] = (*Regs).r[r1] + aux;/*$t = $s + imm*/
}

void SUB (struct s_regs *Regs){/*Subtração de dois registradores sub $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*corte $d*/
	aux = aux & 0x0000f800; 
	aux = aux >> 11;
	r3=aux;

	(*Regs).r[r3] = (*Regs).r[r1] - (*Regs).r[r2];/*$d = $s ­ $t*/
}

void MULT (struct s_regs *Regs){/*Multiplicacao entre dois registradores mult $s, $t*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*corte $s*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	(*Regs).r[10] = (*Regs).r[r1] * (*Regs).r[r2];/*$LO = $s * $t*/
}

void DIV (struct s_regs *Regs){/*Divisao entre dois registradores div $s, $t*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;
    /*$LO = $s / $t; $HI = $s % $t*/
	(*Regs).r[10] = (*Regs).r[r1] / (*Regs).r[r2];
	(*Regs).r[11] = (*Regs).r[r1] % (*Regs).r[r2];
}

void AND (struct s_regs *Regs){/*and $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte $d*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r3=aux;
    
	(*Regs).r[r3] = (*Regs).r[r1] & (*Regs).r[r2];/*$d = $s & $t;*/
}

void ANDI (struct s_regs *Regs){/*andi $t, $s, imm*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;	
    (*Regs).r[r2] = (*Regs).r[r1] & aux;/*$t = $s & imm;*/
}

void ORI (struct s_regs *Regs){/*ori $t, $s, imm*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux; 
	(*Regs).r[r2] = (*Regs).r[r1] | aux;/*$t = $s | imm;*/
}

void OR (struct s_regs *Regs){/*or $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte $d*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r3=aux;

	(*Regs).r[r1] = (*Regs).r[r2] | (*Regs).r[r3];/*$d = $s | $t;*/
}

void SLT (struct s_regs *Regs){/*slt $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
    	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte $d*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r3=aux;

	if((*Regs).r[r1]<(*Regs).r[r2]){/*if $s < $t $d = 1;*/
		(*Regs).r[r3]=1;
	}else{/*else $d = 0*/
		(*Regs).r[r3]=0;
	}
}

void SLTI (struct s_regs *Regs){/*slti $t, $s, imm*/
int32_t aux;
int r1=0,r2=0;

	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	if((*Regs).r[r1]<aux){/*if $s < imm $t = 1;*/
        (*Regs).pc+=4;
		(*Regs).r[r2]=1;
	}else{/*else $t = 0*/
        (*Regs).pc+=4;
		(*Regs).r[r2]=0;
	}
}


void XOR (struct s_regs *Regs){/*xor $d, $s, $t*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte $d*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r3=aux;

	(*Regs).r[r3] = (*Regs).r[r1] ^ (*Regs).r[r2];/*$d = $s ^ $t*/
}


void SLL (struct s_regs *Regs){/*sll $d, $t, h*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r2=aux;

	aux=(*Regs).ir;/*Corte h*/
	aux = aux & 0x000007c0;
	aux = aux >> 6;
	r3=aux;

	(*Regs).r[r2] = (*Regs).r[r1] << (*Regs).r[r3];/*$d = $t << h*/
}

void SRL (struct s_regs *Regs){/*srl $d, $t, h*/
int32_t aux;
int r1=0,r2=0,r3=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $d*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r2=aux;

	aux=(*Regs).ir;/*Corte h*/
	aux = aux & 0x000007c0;
	aux = aux >> 6;
	r3=aux;

	(*Regs).r[r2] = (*Regs).r[r1] >> (*Regs).r[r3];/*$d = $t >> h;*/
}

void J (struct s_regs *Regs){/*j target*/
int32_t aux;

	aux=(*Regs).ir;
	aux = aux & 0x03ffffff;
	(*Regs).pc=((*Regs).pc & 0xf0000000) | (aux << 2);/*PC = nPC; nPC = (PC & 0xf0000000) | (target << 2);*/
}

void BEQ (struct s_regs *Regs){/*beq $s, $t, offset*/
int32_t aux;
int r1=0,r2=0;


	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;/*if $s == $t advance_pc (offset << 2))*/
	if((*Regs).r[r1] == (*Regs).r[r2]){		
		(*Regs).pc+=(aux <<2);
	}else{
		(*Regs).pc+=4;
	}
}

void BNE (struct s_regs *Regs){/*bne $s, $t, offset*/
int32_t aux;
int r1=0,r2=0;


	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	if((*Regs).r[r1] != (*Regs).r[r2]){		/*if $s != $t advance_pc (offset << 2))*/
		(*Regs).pc+=(aux <<2);
	}else{
		(*Regs).pc+=4;
	}
}

void BGEZ (struct s_regs *Regs){/*bgez $s, offset*/
int32_t aux;
int r1=0;


	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	if((*Regs).r[r1] >= 0){		/*if $s >= 0 advance_pc (offset << 2)); */
		(*Regs).pc+=(aux <<2);
	}else{
		(*Regs).pc+=4;
	}
}

void BGTZ (struct s_regs *Regs){/*bgtz $s, offset*/
int32_t aux;
int r1=0;


	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;	
    if((*Regs).r[r1] > 0){		
		(*Regs).pc+=(aux <<2);/*if $s > 0 advance_pc (offset << 2))*/
	}else{
		(*Regs).pc+=4;
	}
}

void LUI (struct s_regs *Regs){/*lui $t, imm*/
int32_t aux;
int r2=0;


	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x0000f800;
	aux = aux >> 11;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	(*Regs).r[r2]+=(aux <<16);
	(*Regs).pc+=4;
}

void SYSCALL (struct s_regs *Regs){
	(*Regs).pc+=4;
}

void LB (struct s_regs *Regs, uint8_t MEMORY[1048576]){/*lb $t, offset($s)*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte $imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	(*Regs).r[r2] = MEMORY[(*Regs).r[r1] + aux];/*$t = MEM[$s + offset];*/
}

void SB (struct s_regs *Regs, uint8_t MEMORY[1048576]){/*sb $t, offset($s)*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	MEMORY[(*Regs).r[r1] + aux]=((*Regs).r[r2] & 0xff);/*MEM[$s + offset] = (0xff & $t);*/
}

void LW (struct s_regs *Regs, uint8_t MEMORY[1048576]){/*lw $t, offset($s)*/
int32_t aux;
int r1=0,r2=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;
	(*Regs).r[r2] = MEMORY[(*Regs).r[r1] + aux +3] << 24 | MEMORY[((*Regs).r[r1] + aux)+2] << 16 | MEMORY[((*Regs).r[r1] + aux)+1] << 8 | MEMORY[((*Regs).r[r1] + aux)];
        /*$t = MEM[$s + offset];*/
}

void SW (struct s_regs *Regs, uint8_t MEMORY[1048576]){/*sw $t, offset($s)*/
int32_t aux;
int r1=0,r2=0;
uint32_t aux1=0;

	(*Regs).pc+=4;
	aux=(*Regs).ir;/*Corte $s*/
	aux = aux & 0x03e00000;
	aux = aux >> 21;
	r1=aux;
	    
	aux=(*Regs).ir;/*Corte $t*/
	aux = aux & 0x001f0000;
	aux = aux >> 16;
	r2=aux;

	aux=(*Regs).ir;/*Corte imm*/
	aux = aux & 0x0000ffff;
    aux=(int16_t)aux;

    /*MEM[$s + offset] = $t;*/
    aux1=(*Regs).r[r2]; /*corte variavel de 8 em 8 bits para ser coloca na memoria*/
    aux1 = aux1 & 0xff000000;
    aux1=aux1 >>24;
    MEMORY[(*Regs).r[r1] + aux+3]=aux1;/*posicionamento maior valor final*/    
    aux1=(*Regs).r[r2];    
    aux1 = aux1 & 0x00ff0000;    
    aux1=aux1 >>16;
    MEMORY[(*Regs).r[r1] + aux+2]=aux1;
    aux1=(*Regs).r[r2];
    aux1 = aux1 & 0x0000ff00;    
    aux1=aux1 >>8; 
    MEMORY[(*Regs).r[r1] + aux +1]=aux1;
    aux1=(*Regs).r[r2]; 
    aux1 = aux1 & 0x000000ff;    
    MEMORY[(*Regs).r[r1] + aux ]=aux1;
}
/***********************************************************************************************************************************/


void simulador(char arv[30]){

FILE *Bin;
FILE *Saida;
uint8_t MEMORY[1048576];/*Memoria*/
uint32_t opc;/*Variavel auxiliares de corte*/
uint32_t aux;/*Variavel auxiliares de corte*/
long int pos_me=0;
struct s_regs Regs;
unsigned j=0;
int i=0;
	
	Bin=fopen(arv,"r");
    Saida=fopen("sim.out", "wb");
	if(Bin!=NULL && Saida != NULL){
		inicial(MEMORY,&Regs);/*Inicialização de Variavel e memoria*/
		while(!feof(Bin)){		
			opc=0;
            i=fread(&opc, sizeof(uint32_t),1,Bin);
            if(i!=0){            
                aux=0;	
                /*divisao de 32bits da variavel para 8 bits da memoria*/		
                aux=opc;				
			    aux = aux & 0xff000000;
			    aux = aux >> 24;
			    MEMORY[pos_me+3] = aux; 
			    	
			    
                aux=opc;				
			    aux = aux & 0x00ff0000;
			    aux = aux >> 16;
			    MEMORY[pos_me+2] = aux; 
			     
			    aux=opc;				
			    aux = aux & 0x0000ff00;
			    aux = aux >> 8;
			    MEMORY[pos_me+1] = aux; 
			    
			    aux=opc;				
			    aux = aux & 0x000000ff;
			    MEMORY[pos_me] = aux; 
			    pos_me+=4;
            }		
        }
		do{	            
            Regs.ir = 0;
            /*Copia da memoria de 8 em 8 ate 32bits*/
			Regs.ir = Regs.ir | MEMORY[Regs.pc+3] << 24;
			Regs.ir = Regs.ir | MEMORY[Regs.pc+2] << 16;
			Regs.ir = Regs.ir | MEMORY[Regs.pc+1] << 8;
			Regs.ir = Regs.ir | MEMORY[Regs.pc] << 0;
			if(Regs.ir != 0){
                aux = 0;
                /*corte Opcode*/
				aux = Regs.ir;
				aux = aux & 0xfc000000;
				aux = aux >> 26;
				if(aux == 0){/*Opcode = 0*/
                    aux=0;
                    /*corte shift Amout*/
					aux=Regs.ir;
					aux= aux & 0x0000003f;
                    /*Chamada função de operações*/
					if (aux == 32){
						ADD(&Regs);
					}else if(aux == 34){
						SUB(&Regs);
					}else if(aux == 24){
						MULT(&Regs);
					}else if(aux == 26){
						DIV(&Regs);
					}else if(aux == 36){
						AND(&Regs);
					}else if(aux == 37){
						OR(&Regs);
					}else if(aux == 42){
						SLT(&Regs);
					}else if(aux == 38){
						XOR(&Regs);
					}else if(aux == 0){
						SLL(&Regs);
					}else if(aux == 2){
						J(&Regs);
					}else if(aux == 12){
						SYSCALL(&Regs);
					}
				}else{/*Opcode != 0*/
                    /*chamada de funções de operações*/
					if(aux == 8){
						ADDI(&Regs);
					}else if(aux == 12){
						ANDI(&Regs);
					}else if(aux == 13){
						ORI(&Regs);
					}else if(aux == 10){
						SLTI(&Regs);
					}else if(aux == 2){
						J(&Regs);
					}else if(aux == 4){
						BEQ(&Regs);
					}else if(aux == 5){
						BNE(&Regs);
					}else if(aux == 1){
						BGEZ(&Regs);
					}else if(aux == 7){
						BGTZ(&Regs);
					}else if(aux == 32){
						LB(&Regs,MEMORY);
					}else if(aux == 40){
						SB(&Regs,MEMORY);
					}else if(aux == 35){
						LW(&Regs,MEMORY);
					}else if(aux == 43){
						SW(&Regs,MEMORY);
					}else if(aux == 15){
						LUI(&Regs);
					}else if(aux == 60){

					}else if(aux == 61){

					}
				}
			}
		}while(Regs.ir != 0);/*condição de parada Regs==0*/
	}
    i=0;
    aux=0;
    /*Soma palavras da memoria de 32bits em 32bits*/
	for(j=0; j<1048576; j+=4){
            opc=0;
            opc= opc | MEMORY[j+3]<<24;
            opc= opc | MEMORY[j+2]<<16;             
            opc= opc | MEMORY[j+1]<<8;
            opc= opc | MEMORY[j]<<0;
            aux= aux + opc;        
    }
    /*Gravação de todas as variaveis de struct regs*/
    fwrite(&Regs,sizeof(Regs),1,Saida);	
    /*Gravação de soma de palavras*/
    fwrite(&aux,sizeof(aux),1,Saida);			
	fclose(Bin);
	fclose(Saida);
}

int main(int argc, char * argv[]){
char arv[30];

    if(argc>0){
	strcpy(arv, argv[1]);
	simulador(arv);
    }else{
	printf("ERRO!!\n");
    }
    return 0;
}

