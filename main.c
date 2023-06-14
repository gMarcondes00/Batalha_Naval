#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Funções a serem utilizadas
void alocar(char matriz[10][10], int player); //chamada para receber as coordenadas e o navio a ser alocado
int alocarGrandes (char matriz[10][10], int x, int y, int direcao, int tamanho); //alocar um navio em uma coordenada específica
void Iniciar(char matriz1[10][10], char matriz2[10][10]); //Função para iniciar o jogo
int atirar(char matriz[10][10], char base[10][10], int x, int y); // Função para pegar coordenadas e matriz a ser comparada

int main() {
    printf("\n--------- Batalha Naval ---------\n\n");
    int i, j;
    char P1[10][10]; char P2[10][10];

    for(i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            P1[i][j] = 1;
            P2[i][j] = 1;
        }
    }

    int escolha;
    bool ficar = true;
    while(ficar){

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
                alocar(P2, player);
            }
            if(player == 1) {
                alocar(P1, player);
            }
            system("cls");
            printf("****  Tabuleiro do jogador %d alocado! ****\n\n", player);
            break;
        case 2:
            if(P1[0][0] != 1 && P2[0][0] != 1){
                Iniciar(P1, P2);
            } else {
                printf("\n*** Nao foi possivel iniciar o jogo ***\nCada jogador deve ter seu tabuleiro feito!\n");
            }
            
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

// função pegar coordenadas que o usuario quer alocar
// alocar submarinos na matriz
void alocar(char matriz[10][10], int player){
    int n[4];
    n[0] = 1, n[1] = 2, n[2] = 3, n[3] = 4;
    //inicializar a matriz com '-' caso o usuario queira realocar novamente
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matriz[i][j] = '-';
            if(i == 0) {
                matriz[i][j] = '0' + j;
            }
            if(j == 0) {
                matriz[i][j] = '0' + i;
            }  
        }
    }

    int loop = n[0] + n[1] + n[2] + n[3];
    while(loop > 0) {
        printf("\nMatriz do jogador %d\n\n", player);
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
            printf("%c ",matriz[i][j]);
            }
            printf("\n");
        }
        int x, y, navio, direcao, sucesso;
        printf("\nNavios :\n\n0 - Porta-Avioes(%d) = 4 blocos\n1 - Navios-Cargueiros(%d) = 3 blocos\n2 - Contratorpedeiros(%d) = 2 blocos\n3 - Submarinos(%d) = 1 bloco\n", n[0], n[1], n[2], n[3]);
        
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
                    printf("\n\n** Alocado com sucesso **");
                    } else {
                    printf("\n\n** Falha ao alocar **");
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
                    printf("\n\n** Alocado com sucesso **");
                    } else {
                    printf("\n\n** Falha ao alocar **");
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
                        printf("\n\n** Alocado com sucesso **");
                    } else {
                    printf("\n\n** Falha ao alocar **");
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

                    printf("\n\n** Alocado com Sucesso **!");   
                } else {
                    printf("\n\n** Falha ao alocar **!");
                };
                break;
            default:
                break;
        }
    }
}

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

//Iniciar o jogo
void Iniciar(char matriz1[10][10], char matriz2[10][10]){
    system("cls");
    int acertos1 = 0, acertos2 = 0, x, y;

    char base1[10][10], base2[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            base1[i][j] = '-';
            base2[i][j] = '-';
        }
    }
    while((acertos1 < 20) && (acertos2 < 20)){
        int tiro1 = 0, tiro2 = 0;
        printf("A - erros    X - acertos em navios");
        printf("\n\nTabuleiro jogador 1:        Tabuleiro jogador 2:\n");
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                printf("%c ",base1[i][j]);
            }
            printf("        ");
            for(int j = 0; j < 10; j++){
                printf("%c ", base2[i][j]);
            }
            printf("\n");
        }

        printf("\nJogador 1 atira em Jogador 2, atirar em qual linha e coluna? respectivamente\n");
        scanf("%d %d", &x, &y);
        tiro1 = atirar(matriz2, base2, x, y);
        while(tiro1 == 1) {
            acertos1 += tiro1;
            tiro1 = 0;

            printf("\nJogador 1 Acertou! Jogue Novamente!");
            printf("\nJogador 1 atira em Jogador 2, atirar em qual linha e coluna? respectivamente\n");

            scanf("%d %d", &x, &y);
            if(atirar(matriz2, base2, x, y)){
                tiro1++;
            }
        }
        
        printf("Jogador 2 atira em Jogador 1, atirar em qual linha e coluna? respectivamente\n");
        scanf("%d %d", &x, &y);
        tiro2 = atirar(matriz1, base1, x, y);
        while(tiro2 == 1) {
            acertos2 += tiro2;
            tiro2 = 0;
            
            printf("\nJogador 2 Acertou! Jogue Novamente!");
            printf("\nJogador 2 atira em Jogador 1, atirar em qual linha e coluna? respectivamente\n");

            scanf("%d %d", &x, &y);
            if(atirar(matriz1, base1, x, y)){
                tiro2++;
            }
        }

        printf("\n\njogador1: %d acertos \njogador2: %d acertos\n\n", acertos1, acertos2);
    }

    if(acertos2 == 20) {
        printf("\nO jogador 2 Venceu!\n");
    } else {
        printf("\nO jogador 1 Venceu!\n");
    }  
}

//Atirar na matriz selecionada
int atirar(char matriz[10][10], char base[10][10], int x, int y){
    if(matriz[x][y] == '-'){
        base[x][y] = 'A';
        return 0;
    } 
    if(matriz[x][y] == 'S' || matriz[x][y] == 'C' || matriz[x][y] == 'N' || matriz[x][y] == 'P'){
        base[x][y] = 'X';
        matriz[x][y] = '-';
        return 1;
    }
    return 0;
}