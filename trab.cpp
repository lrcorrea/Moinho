#include <stdio.h>
#include <stdlib.h>

void mat(int mat[][3]){
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==0){
				printf("%d-----%d-----%d", mat[i][j], mat[i][j]), mat[i][j];
			}
			if(i==1){
				printf("%d-----%d-----%d", mat[i][j], mat[i][j]), mat[i][j];
			}
			if(i==2){
				printf("%d-----%d-----%d", mat[i][j], mat[i][j]), mat[i][j];
			}
		}
	}
}


int main(){
	int mat[3][3]={
				  {"0", "0", "0"},
				  {"0", "0", "0"},
				  {"0", "0", "0"}
				  };
	
	
	
	system("pause");
}
