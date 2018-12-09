/*
 * Trabalho de GRAFOS
 * Disciplina: Algoritimo e Estrutura de Dados 2 - INF/UFG
 * Matricula: 201709624
 * Professor: Fabrizzio
 * 
 * Aluno: Alan Viana do Nascimento
 * */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct nodo{
	struct nodo *noPai; 
	int i; //informa o numero do passo que foi dado
	bool ida; //informa se as quantides de jesuitas e canibais está na ida ou na volta do barco
	int canibais;
	int jesuitas;
	struct nodo *vetor[20];
}no;
int qtdPassos=0; //informa a quantidade de passos que o programa deve dar

no*raiz;
FILE *resultado; //Como o terminal não mostra todas as linhas o mesmo será impresso em um arquivo com todas as possibilidades dentro das regras do jogo

void imprime(no*p){
	int i = p->i;
	int c = p->canibais;
	int j = p->jesuitas;
	resultado=fopen("resultado.txt","ab");
	if(p->ida == true){
		for(int k=0;k<i;k++){
			fprintf(resultado,"     |");
			printf("     |");
		}
		fprintf(resultado,"-->PASSO %d - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
		printf("-->PASSO %d - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
	}else{
		for(int k=0;k<i;k++){
			fprintf(resultado,"     |");
			printf("     |");
		}
		fprintf(resultado,"-->PASSO %d - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
		printf("<--PASSO %d - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
	}
	fclose(resultado);
}

void criaRaiz(){
	raiz = (no*) malloc(sizeof(no));
	raiz->noPai=NULL;
	raiz->ida=false;
	raiz->canibais=3;
	raiz->jesuitas=3;
	raiz->i=1;
}

no*new(){
	no* p = (no*) malloc(sizeof(no));
	return p;
}

void imprimeGrafo(no*p){
	imprime(p);
	if(p->jesuitas == 0 && p->canibais == 0){
				resultado=fopen("resultado.txt","ab");
				fprintf(resultado,"ACHOOOOOOOOOOOOOOOOOOOUUUU\n");
				fclose(resultado);
	}
	for(int i=0;i<20;i++){
		if(p->vetor[i]!= NULL){
			imprimeGrafo(p->vetor[i]);
		}
	}
}

void imprimePassos(no*p){
	int i = p->i;
	int c = p->canibais;
	int j = p->jesuitas;
	if(p->ida == true){
		printf("-->PASSO %d\t - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
	}else{
		printf("<--PASSO %d\t - (%d,%d)_____(%d,%d)\n",i,c,j,3-c,3-j);
	}
	if(p->noPai!=NULL) imprimePassos(p->noPai);
}

void buscaResultado(no*p){
	if(p->jesuitas == 0 && p->canibais == 0){
				printf("ACHOOOOOOOOOOOOOOOOOOOUUUU\n");	
				printf("-------------------(c,j)_____(c,j)\n");
				imprimePassos(p);
	}
	for(int i=0;i<20;i++){
		if(p->vetor[i]!= NULL){
			buscaResultado(p->vetor[i]);
		}
	}
}

bool leiDoBarco(no*p,int i,int j){
	//No barco só pode ir no máximo 2
	if(i<0) return false;
	if(j<0) return false;
	int atual = p->canibais + p->jesuitas;
	int agora = i+j;
	if((atual-agora)>=3 || agora==atual) return false;
	else
	return true;
}
bool leiDoBarcoVolta(no*p,int i,int j){
	//No barco só pode voltar no máximo 2
	if(i<0) return false;
	if(j<0) return false;
	int atual = p->canibais + p->jesuitas;
	int agora = i+j;
	if((agora-atual)>=3 || agora==atual) return false;
	else
	return true;
}

bool regrasJogo(no*p,int i,int j){
	if(i>j && j!=0) return false; //não pode ter mais canibais do que jesuitas
	int can = 3-i; //canibais que estão do outro lado
	int jes = 3-j; //jesuitas que estão do autro lado
	if(can>jes && jes != 0) return false; //não pode ter mais canibais do que jesuitas
	if(p->canibais == i && p->jesuitas == j) return false; //evitar loop de idas e voltas
	return true;
}

void inicia(no*pai){
//O programa cria as possibilidades de idas e voltas do barco dentro das regras do jogo
int can = pai->canibais;
int jes = pai->jesuitas;
int v=0;
if(pai->ida ==false){ 
	for(int i=can-2;i<=can;i++){
		for(int j=jes-2;j<=jes;j++){
			if(leiDoBarco(pai,i,j)==true){
				if(regrasJogo(pai,i,j)==true){
					no*p=new();
					p->noPai = pai;
					p->ida = true;
					p->canibais = i;
					p->jesuitas = j;
					p->i=pai->i+1;
					pai->vetor[v]=p;		
					v++;
				}
			}
		}
	}
}else{	
	for(int i=can;i<=3;i++){
		for(int j=jes;j<=3;j++){
			if(leiDoBarcoVolta(pai,i,j)==true){
				if(regrasJogo(pai,i,j)==true){
					no*p=new();
					p->noPai = pai;
					p->ida = false;
					p->canibais = i;
					p->jesuitas = j;
					p->i=pai->i+1;
					pai->vetor[v]=p;		
					v++;
				}
			}
		}
	}
}
}

void letsgo(no*p){
	int cont=p->i;
	inicia(p);
	cont++;
	if(cont!=qtdPassos){ //O programa fará 12 leques de possibilidades
			for(int i=0;i<20;i++){
				if(p->vetor[i]!=NULL) letsgo(p->vetor[i]);
			}
	}	
}

int main(){
	criaRaiz();
	qtdPassos=12; //o programa deve dar extamente 12 passos para encontrar a solução
	letsgo(raiz);
	
	//imprimeGrafo(raiz); //Essa função imprime no terminal de no arquivo
	buscaResultado(raiz);
	

	
}
