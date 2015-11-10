#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define l 10
#define c 3

void imprime(char mat[][c]){//funcao com o desenho, ainda vou pensar com como vou fazer as linhas
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			//numerando as linhas
			if(i==0 && j==0){
				printf(" | ");
			}
			else if(i==1 && j==0){
				printf("B| ");
			}
			else if(i==2 && j==0){
				printf("C| ");
			}
			else if(i==3 && j==0){
				printf("D| ");
			}
			else if(i==6 && j==0){
				printf("E| ");
			}
			else if(i==7 && j==0){
				printf("F| ");
			}
			else if(i==8 && j==0){
				printf("G| ");
			}
			
			//numerando colunas
			if(i==0 && j==0){
				printf("1     2  3    4    5  6     7\nA| ");
			}
			
			
			//espaçamento
			if(i == 0 || i == 8){
				printf("%d             ", mat[i][j]);//primeira e ultima linha
			}
			
			if(i == 1 || i == 7){
				printf("      %d ", mat[i][j]);//segunda e penultima
			}
			
			if(i == 2 || i == 6){
				if(j == 0){
					printf("         %d    ", mat[i][j]);//terceira e antepenultima
				}else{
					printf("%d    ", mat[i][j]);//quarta
				}
			}
			if(i == 3 || i == 4){
				//espaçamento da linha que tem 6 colunas
				if(j == 0 && i == 3){
					printf("%d     ", mat[i][j]);
				}
				else if(j == 1 && i == 3){
					printf("%d  ", mat[i][j]);
				}
				else if(j == 2 && i == 3){
					printf("%d         ", mat[i][j]);
				}
				else if(j == 0 && i == 4){
					printf("%d  ", mat[i][j]);
				}
				else if(j == 1 && i == 4){
					printf("%d     ", mat[i][j]);
				}
				else if(j == 2 && i == 4){
					printf("%d", mat[i][j]);
				}
			}		
		}
		if(i != 3 && i != 4){
			//aqui faço uma linha na direta pra ficar bonitinho, mas provisorio
			if(i<8){
				printf("\n |\n");
			}
			else if(i>0){
				printf("\n");
			}
		}
	}
}

//função que atribui a pos de X; retorna qtd++, verifica a validade da jogada
int attrMat(int linha,char coluna, int qtd, char mat[][c]){
	printf("linha: %d / coluna: %d\n", linha, coluna);
	return qtd++;
}



int main(){
	char mat[l][c];
	char nome1[10]="Lucas", nome2[10]="Lusca";
	char coordenada[2], linha;
	int qtdInit=0, coluna, cont=0;
	bool fim=false;
	
	for(int i=0; i<l; i++){//laço pra atribuir 0 na matriz
		for(int j=0; j<c; j++){
			mat[i][j]=0;
		}
	}
	
	imprime(mat);//chama funcao que vai imprimir desenho
	
	//le nome dos jogadores
	/*printf("Infrome o nome do player X: ");
	gets(nome1);
	printf("Infrome o nome do player O: ");
	gets(nome2);*/
	
	while(qtdInit<=9){//laço para jogo até usar todas peças
		cont++;
		if(cont%2!=0){//player x, quando for impar
			do{//laço pra verificar validade de jogada do X
				printf("%s, Informe uma posicao para X: ", nome1);
				volta://aqui volta do goto quando jogada é invalida; desnessesauro
				gets(coordenada);
				
				coluna = (coordenada[1]-48);//converto em um numero de 1 a 7
				linha = coordenada[0];
					
				if(linha - 32 >= 65){
					linha = linha-32;//se for minuscula transformo em maiscula
				}
				linha -= 64;//transformo a letra em um numero equivalente a=1, b=2...

				if((linha>=1) && (linha<=7) && (coluna>=1) && (coluna<=7)){
					//chamo a funcao que verifica e atribui no lugar indicado, qtdInit é o num de peças que foram jogadas
					qtdInit = attrMat(linha, coluna, qtdInit, mat);
				}else{
					printf("Tente novamente, exemplo A1\n");
					goto volta;// goto volta na linha indicada pela var volta
				}	
			}while((coordenada[0]<65) && (coordenada[0]>71));		
		}
		//essa parte de baixo fica pra próxima que e o O, player2
	/*	else if(cont%2==0){//playerY, quando for par
			do{//laço pra verificar validade de jogada do O
				printf("%s, Informe uma posicao para O: ", nome2);
				gets(coordenada);
				if((pos[0]<65) || (posX[0]>71) && (posX[1]<49) || (posX[1])>55){
					printf("Tente novamente, exemplo A1\n");
				}else{
					qtdInit = attrMat(coordenada, qtdInit, mat);
				}	
			}while((posX[0]<65) && (posX[0]>71));
		}*/
		
	}
	
	
	
	
	
	system("pause");
}
