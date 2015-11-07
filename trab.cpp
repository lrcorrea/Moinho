#include <stdio.h>
#include <stdlib.h>

#define l 10
#define c 3
void imprime(int mat[][c]){
	
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
			
			
		
			if(i == 0 || i == 8){
				printf("%d             ", mat[i][j]);//12 spaces > na linha 1 e 7
			}
			
			if(i == 1 || i == 7){
				printf("      %d ", mat[i][j]);//6 spaces < na linha 1 e 6
			}
			
			if(i == 2 || i == 6){
				if(j == 0){
					printf("         %d    ", mat[i][j]);//8 spaces < na linha 2 e 5
				}else{
					printf("%d    ", mat[i][j]);//3 spaces >
				}
			}
			if(i == 3 || i == 4){
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
			if(i<8){
				printf("\n |\n");
			}
			else if(i>0){
				printf("\n");
			}
		}
		
	}
	
	
	
}

int main(){
	int mat[l][c];
	
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			mat[i][j]=0;
		}
	}
	imprime(mat);
	
	system("pause");
}
