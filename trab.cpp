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
				printf("%c             ", mat[i][j]);//primeira e ultima linha
			}
			
			if(i == 1 || i == 7){
				printf("      %c ", mat[i][j]);//segunda e penultima
			}
			
			if(i == 2 || i == 6){
				if(j == 0){
					printf("         %c    ", mat[i][j]);//terceira e antepenultima
				}else{
					printf("%c    ", mat[i][j]);//quarta
				}
			}
			if(i == 3 || i == 4){
				//espaçamento da linha que tem 6 colunas
				if(j == 0 && i == 3){
					printf("%c     ", mat[i][j]);
				}
				else if(j == 1 && i == 3){
					printf("%c  ", mat[i][j]);
				}
				else if(j == 2 && i == 3){
					printf("%c         ", mat[i][j]);
				}
				else if(j == 0 && i == 4){
					printf("%c  ", mat[i][j]);
				}
				else if(j == 1 && i == 4){
					printf("%c     ", mat[i][j]);
				}
				else if(j == 2 && i == 4){
					printf("%c", mat[i][j]);
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

//função que verifica se o espaço é vago
bool attrMat(char mat[][c], int linha, char coluna, int cont, int qtd){
	bool troca=false, muda=false;
	
	if(((linha==1) || (linha==7)) && (coluna==1)){//linha A e G
		coluna=1;
		troca=true;
		if(linha==7){
			linha+=2;
		}
	}else if(((linha==1) || (linha==7)) && (coluna==4)){
		coluna=2;
		troca=true;
		if(linha==7){
			linha+=2;
		}
	}else if(((linha==1) || (linha==7)) && (coluna==7)){
		coluna=3;
		troca=true;
		if(linha==7){
			linha+=2;
		}
	}
	else if(((linha==2) || (linha==6)) && (coluna==2)){//linha B e F
		coluna=1;
		troca=true;
		if(linha==6){
			linha+=2;
		}
	}else if(((linha==2) || (linha==6)) && (coluna==4)){
		coluna=2;
		troca=true;
		if(linha==6){
			linha+=2;
		}
	}else if(((linha==2) || (linha==6)) && (coluna==6)){
		coluna=3;
		troca=true;
		if(linha==6){
			linha+=2;
		}
	}
	else if(((linha==3) || (linha==5)) && (coluna==3)){//linha C e E
		coluna=1;
		troca=true;
		if(linha==5){
			linha+=2;
		}
	}else if(((linha==3) || (linha==5)) && (coluna==4)){
		coluna=2;
		troca=true;
		if(linha==5){
			linha+=2;
		}
	}else if(((linha==3) || (linha==5)) && (coluna==5)){
		coluna=3;
		troca=true;
		if(linha==5){
			linha+=2;
		}
	}
	else if((linha==4) && ((coluna==1) || (coluna==5))){//linha D
		if(coluna>4){
			linha=5;
		}
		coluna=1;
		troca=true;
	}else if((linha==4) && ((coluna==2) || (coluna==6))){
		if(coluna>4){
			linha=5;
		}
		coluna=2;
		troca=true;
	}else if((linha==4) && ((coluna==3) || (coluna==7))){
		if(coluna>4){
			linha=5;
		}
		coluna=3;
		troca=true;
	}else{
		troca=false;
	}
	
	if((mat[linha-1][coluna-1]!='0') || (troca==false)){
		return false;
	}else{
		
		if((cont%2!=0) && (troca==true)){
			mat[linha-1][coluna-1] = 88;//88 X
		}else if((cont%2==0) && (troca==true)){
			mat[linha-1][coluna-1] = 89;//79 Y
		}
		
		if(troca==true){
			imprime(mat);
		}
		return true;
	}
}
 

int main(){
	char mat[l][c];
	char nome1[10]="Lucas", nome2[10]="Lusca";
	char coordenada[2], linha;
	int qtdInit=0, coluna, cont=0, contAux=0;
	bool fim=false, verDisp=false;
	
	for(int i=0; i<l; i++){//laço pra atribuir 0 na matriz
		for(int j=0; j<c; j++){
			mat[i][j]='0';
		}
	}
	
	imprime(mat);//chama funcao que vai imprimir desenho
	

	while(qtdInit<9){//laço para jogo até usar todas peças
		cont++;
		do{//laço pra verificar validade de jogada
			
			//aqui volta do goto quando jogada é invalida; desnessesauro
			volta:
				
			if(cont%2!=0){//player x, quando for impar
				printf("%s, Informe uma posicao para X: ", nome1);
			}else if(cont%2==0){//player Y, quando par
				printf("%s, Informe uma posicao para Y: ", nome2);
			}
			gets(coordenada);
				
			coluna = (coordenada[1]-48);//converto em um numero de 1 a 7
			linha = coordenada[0];
					
			if(linha - 32 >= 65){
				linha = linha-32;//se for minuscula transformo em maiscula
			}
			linha -= 64;//transformo a letra em um numero equivalente a=1, b=2...

			verDisp = attrMat(mat, linha, coluna, cont, qtdInit);
			
			if(((linha>=1) && (linha<=7)) && ((coluna>=1) && (coluna<=7)) && (verDisp==true)){
				//so faz cont quando o player Y for jogar
				if(cont%2==0){
					qtdInit+=1;
				}
			
			}
			else if(verDisp==false){
				printf("Posicao invalida, tente novamente\n");
				goto volta;// goto volta na linha indicada pela var volta
			}
		
			//apenas cuidando do comportamento das var cont que é o player atual e o qtdInit até acabar as 9 peças
			printf("cont: %d / qtdInt: %d\n", cont, qtdInit);
				
		}while((coordenada[0]<65) && (coordenada[0]>71));		
	}
	

	system("pause");
}
