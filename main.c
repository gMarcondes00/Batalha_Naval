#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Funções a serem utilizadas
void alocar(char matriz[11][11], int player); //chamada para receber as coordenadas e o navio a ser alocado
int alocarGrandes (char matriz[11][11], int x, int y, int direcao, int tamanho); //alocar um navio em uma coordenada específica
void Iniciar(char matriz1[11][11], char matriz2[11][11]); //Função para iniciar o jogo
int tentar(char matriz[11][11], char base[11][11], int player); // Função para pegar as coordenadas do tiro
int atirar(char matriz[11][11], char base[11][11], int x, int y); // Função comparar coordenadas e matriz a ser comparada

int main() {
    printf("\n--------- Batalha Naval ---------\n\n");
    int i, j;
    char P1[11][11]; char P2[11][11];

    for(i = 0; i < 11; i++){
        for (j = 0; j < 11; j++){
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
void alocar(char matriz[11][11], int player){
    int n[4];
    
    n[0] = 1, n[1] = 2, n[2] = 3, n[3] =  4;
    //inicializar a matriz com '-' caso o usuario queira realocar novamente
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            matriz[i][j] = '-';
            if(i == 0) {
                matriz[i][j] = '0' + j;
            }
            if(j == 0 && i > 0) {
                matriz[i][j] = 'A' + i - 1;
            }
            matriz[0][0] = 0; 
        }
    }

    int loop = n[0] + n[1] + n[2] + n[3];
    while(loop > 0) {
        printf("\nMatriz do jogador %d\n\n", player);
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (matriz[i][j] == ':') {
                    printf("%d", 10); 
                } else {
                    printf("%c ", matriz[i][j]); 
                }
            }
                printf("\n");
        }
        int x, y, navio, direcao, sucesso;
        char xChar;
        printf("\nNavios :\n\n0 - Porta-Avioes(%d) = 4 blocos\n1 - Navios-Cargueiros(%d) = 3 blocos\n2 - Contratorpedeiros(%d) = 2 blocos\n3 - Submarinos(%d) = 1 bloco\n", n[0], n[1], n[2], n[3]);
        
        printf("selecione um navio: \n");
        scanf("%d", &navio);
        switch (navio){
            //porta-avioes
            case 0:
                printf("qual as coordenadas do ponto que gostaria de inserir?\n");
                printf("Coluna(numero): ");
                scanf("%d", &y);
                printf("Linha(letra MAIUSCULA): ");
                scanf("%s", &xChar);

                x = xChar - 'A' + 1;

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[0] > 0 && (x > 0 && x < 11)){
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
                printf("qual as coordenadas do ponto que gostaria de inserir?\n");
                printf("Coluna(numero): ");
                scanf("%d", &y);
                printf("Linha(letra MAIUSCULA): ");
                scanf("%s", &xChar);

                x = xChar - 'A' + 1;

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[1] > 0 && (x > 0 && x < 11)){
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
                printf("qual as coordenadas do ponto que gostaria de inserir?\n");
                printf("Coluna(numero): ");
                scanf("%d", &y);
                printf("Linha(letra MAIUSCULA): ");
                scanf("%s", &xChar);

                x = xChar - 'A' + 1;

                printf("Em qual rotacao? Direita(0), Esquerda(1), Cima(2), Baixo(3)\n");
                scanf("%d", &direcao);

                if(n[2] > 0 && (x > 0 && x < 11)){
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
                printf("qual as coordenadas do ponto que gostaria de inserir?\n");
                printf("Coluna(numero): ");
                scanf("%d", &y);
                printf("Linha(letra MAIUSCULA): ");
                scanf("%s", &xChar);

                x = xChar - 'A' + 1;
                if(n[3] > 0 && matriz[x][y] == '-' && (x > 0 && x < 11)){
                    --n[3];
                    --loop;
                    matriz[x][y] = 'S';

                    printf("\n\n** Alocado com Sucesso **!");   
                } else {
                    printf("\n\n** Falha ao alocar **!");
                };
                break;
            default:
                printf("Navio invalido");
                break;
        }
    }
}

//Alocar grandes navios na matriz
int alocarGrandes (char matriz[11][11], int x, int y, int direcao, int tamanho) {
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
void Iniciar(char matriz1[11][11], char matriz2[11][11]){
    system("cls");
    int acertos1 = 0, acertos2 = 0;

    char base1[11][11], base2[11][11];
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            base1[i][j] = '-';
            base2[i][j] = '-';
            if(i == 0) {
                base1[i][j] = '0' + j;
                base2[i][j] = '0' + j;
            }
            if(j == 0 && i > 0) {
                base1[i][j] = 'A' + i - 1;
                base2[i][j] = 'A' + i - 1;
            } 
            base1[0][0] = 0;
            base2[0][0] = 0;
        }
    }
    while((acertos1 <= 20) && (acertos2 <= 20)){
        int tiro1 = 0, tiro2 = 0;
        printf("Z - erros    X - acertos em navios");
        printf("\n\nTabuleiro jogador 1:        Tabuleiro jogador 2:\n");
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                if (base1[i][j] == ':') {
                    printf("%d ", 10); 
                } else {
                    printf("%c ",base1[i][j]);
                }
            }
            printf("        ");
            for(int j = 0; j < 11; j++){
                if (base2[i][j] == ':') {
                    printf(" %d", 10); 
                } else {
                    printf(" %c",base2[i][j]);
                }
            }
            printf("\n");
        }

        tiro1 = tentar(matriz2, base2, 1);
        while(tiro1 == 1) {
            acertos1 += tiro1;
            tiro1 = 0;
            if(tentar(matriz2, base2, 1)){
                tiro1++;
            }
        }
        
        tiro2 = tentar(matriz1, base1, 2);
        while(tiro2 == 1) {
            acertos2 += tiro2;
            tiro2 = 0;
            
            if(tentar(matriz1, base1, 2)){
                tiro2++;
            }
        }

        printf("\n\njogador1: %d acertos \njogador2: %d acertos\n\n", acertos1, acertos2);
        if(acertos1 == 20 || acertos2 == 20){
            break;
        }
    }

    if(acertos2 == 20) {
        printf("\nO jogador 2 Venceu!\n");
    } else {
        printf("\nO jogador 1 Venceu!\n");
    }  
}

int tentar(char matriz[11][11], char base[11][11], int player){
    int y, x; 
    char xChar[2];

    printf("\nVez do jogador %d atirar\n", player);
    printf("Coluna(numero): ");
    scanf("%d", &y);
    printf("Linha(letra MAIUSCULA): ");
    scanf("%s", xChar);

    x = xChar[0] - 'A' + 1;

    if(atirar(matriz, base, x, y)){
        printf("\nVoce acertou! Jogue novamente!");
        return 1;
    }

    return 0;
}

//Atirar na matriz selecionada
int atirar(char matriz[11][11], char base[11][11], int x, int y){
    if(matriz[x][y] == '-'){
        base[x][y] = 'Z';
        return 0;
    } 
    if(matriz[x][y] == 'S' || matriz[x][y] == 'C' || matriz[x][y] == 'N' || matriz[x][y] == 'P'){
        base[x][y] = 'X';
        matriz[x][y] = 'x';
        return 1;
    }
    return 0;
}