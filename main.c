#include <stdio.h>

int main() {
    char P1[11][11];
    int i, j;
    
    for(i = 0; i < 11; i++) {
        for(j = 0; j < 11; j++) {
            if(j == 0 || i == 0){
                if(j == 0){
                    P1[i][j] = i;
                } else {
                    P1[i][j] = j;
                }
            }else{
                P1[i][j] = '-';
            }
        }
    }

    int navio[4];
    navio[0] = 1, navio [1] = 2, navio[2] = 3, navio[3] = 4;

    while(navio[0] != 0 || navio[1] != 0 || navio[2] != 0 || navio[3] != 0){
        printf("\nSeu tabuleiro:\n");
        for(i = 0; i < 11; i++) {
            for(j = 0; j < 11; j++) {
                if(j == 0 || i == 0){
                    printf("%d ", P1[i][j]);
                } else{
                    printf("%c ", P1[i][j]);
                }
                
            }
            printf("\n");
        } 
        
    }

    return 0;
}