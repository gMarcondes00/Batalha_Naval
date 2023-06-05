#include <stdio.h>
#include <stdbool.h>

//Alocar grandes navios na matriz
int alocarGrandes (char matriz[10][10], int x, int y, int direcao, int tamanho) {
    char letra;
    switch(tamanho){
        case 2:
            letra = 'C';
            break;
        case 3:
            letra  = 'N';
            break;
        case 4:
            letra = 'P';
            break;
    }


    if(matriz[x][y] == '-'){
        switch (direcao){
            case 0:
                for(int i = 0; i < tamanho; i++) {
                    if(matriz[x][y + i] == '-'){
                        matriz[x][y + i] = letra;
                    }else {
                    for (int j = i - 1; j >= 0; j--) {
                        matriz[x][y + j] = '-';
                    }
                    return 0;
                    }
                }
                break;
            case 1:
                for(int i = 0; i < tamanho; i++) {
                    if(matriz[x][y - i] == '-'){
                        matriz[x][y - i] = letra;
                    }else {
                        for (int j = i - 1; j >= 0; j--) {
                        matriz[x][y - j] = '-';
                    }
                    return 0;
                    }
                }
                break;
            case 2:
                for(int i = 0; i < tamanho; i++) {
                    if(matriz[x - i][y] == '-'){
                        matriz[x - i][y] = letra;
                    }else {
                        for (int j = i - 1; j >= 0; j--) {
                        matriz[x - j][y] = '-';
                    }
                    return 0;
                    }
                }
                break;
            case 3:
                for(int i = 0; i < tamanho; i++) {
                    if(matriz[x + i][y] == '-'){
                        matriz[x + i][y] = letra;
                    }else {
                        for (int j = i - 1; j >= 0; j--) {
                        matriz[x + j][y] = '-';
                    }
                    return 0;
                    }
                }
                break;        
            default:
                break;
        }
        return 1;
    }

    return 0;
}

// função pegar coordenadas que o usuario quer alocar
// alocar submarinos na matriz
void alocar(char matriz[10][10]){
    int n[4];
    n[0] = 1, n[1] = 2, n[2] = 3, n[3] = 4;

    int loop = n[0] + n[1] + n[2] + n[3];
    while(loop > 0) {
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
            printf("%c ",matriz[i][j]);
            }
            printf("\n");
        }
        int x, y, navio, direcao, sucesso;
        printf("Navios :\n\n0 - Porta-Avioes(%d) = 4 blocos\n1 - Navios-Cargueiros(%d) = 3 blocos\n2 - Contratorpedeiros(%d) = 2 blocos\n3 - Submarinos(%d) = 1 bloco\n", n[0], n[1], n[2], n[3]);
        
        printf("selecione um navio: \n");
        scanf("%d", &navio);
        switch (navio){
            //porta-avioes
            case 0:
                printf("qual as coordenadas(linha e coluna, respectivamente) do ponto que gostaria de inserir?\n");
                scanf("%d %d", &x, &y);

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[0] > 0){
                    sucesso = alocarGrandes(matriz, x, y, direcao, 4);
                    if(sucesso == 1) {
                    --n[0];
                    --loop;
                    printf("\n\nAlocado com sucesso\n\n");
                    } else {
                    printf("\n\nFalha ao alocar\n\n");
                }
                } 

                break;
                //navio-cargueiro
            case 1: 
                printf("qual as coordenadas(linha e coluna, respectivamente) do ponto que gostaria de inserir?\n");
                scanf("%d %d", &x, &y);

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[1] > 0){
                    sucesso = alocarGrandes(matriz, x, y, direcao, 3);
                    if(sucesso == 1) {
                    --n[1];
                    --loop;
                    printf("\n\nAlocado com sucesso\n\n");
                    } else {
                    printf("\n\nFalha ao alocar\n\n");
                }
                } 
                break;
                //contratorpedeiro
            case 2: 
                printf("qual as coordenadas(linha e coluna, respectivamente) do ponto que gostaria de inserir?\n");
                scanf("%d %d", &x, &y);

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[2] > 0){
                    sucesso = alocarGrandes(matriz, x, y, direcao, 2);
                    if(sucesso == 1) {
                    --n[2];
                    --loop;
                    printf("\n\nAlocado com sucesso\n\n");
                    } else {
                    printf("\n\nFalha ao alocar\n\n");
                }
                } 
                break;
                //submarino
            case 3: 
                printf("qual as coordenadas(linha e coluna, respectivamente) do ponto que gostaria de inserir?\n");
                scanf("%d %d", &x, &y);
                if(n[3] > 0 && matriz[x][y] == '-'){
                    --n[3];
                    --loop;
                    matriz[x][y] = 'S';   
                };
                break;
            default:
                break;
        }
    }
}

int main() {
    printf("\n--------- Batalha Naval ---------\n\n");
    int i, j;
    char P1[10][10]; char P2[10][10];

    //inicializar a matriz com '-'
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            P1[i][j] = '-';
            P2[i][j] = '-';
        }
    }

    int escolha;
    bool ficar = true;
    while(ficar){
    
    //Mostrar as matrizes dos dois jogadores:
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%c ",P1[i][j]);
        }
        printf("        ");
        for(j = 0; j < 10; j++){
            printf("%c ", P2[i][j]);
        }
        printf("\n");
    }

    printf("\n   Menu do Jogo:\n\n1 - Alocar Navios\n2 - Iniciar o Jogo\n3 - Sair do Jogo\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &escolha);

    int player;
    //Alternar entre escolhas do Menu
    switch(escolha){
        case 1:
            printf("Alocar navio de qual jogador? 1 ou 2: ");
            scanf("%d", &player);
            if(player == 2) {
                alocar(P2);
            }
            if(player == 1) {
                alocar(P1);
            }
            break;
        case 2:
            //Inicar();
            break;
        case 3:
            ficar = false;
            break;
        default:
            printf("Opcao invalida");
            break;
    }}

    return 0;
}