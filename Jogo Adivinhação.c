#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int i = 0;
int u = 0;

struct{
    char nome[30];
    int pontos;
}usuario[5];


void registro(){
    int op;
    int actualUser;
    printf("1 - Ver tabela de jogadores\n2 - Registrar-se\n3 - Escolher Jogador\n-> ");
    scanf("%d", &op);

    switch(op){

    case 1:
        system("cls");
        for(int j = 1; j <= strlen(usuario); j++){
            if(usuario[j-1].nome != NULL){
                printf("%d - %s com %d pontos\n", j, usuario[j-1].nome, usuario[j-1].pontos);
            }
        }
        system("pause");
        system("cls");
        main();

    case 2:
        system("cls");
        printf("Informe seu nome: ");
        scanf("%s", &usuario[i].nome);
        i++;
        system("cls");
        registro();

    case 3:
        system("cls");
        for(int x = 1; x <= strlen(usuario); x++){
            printf("%d - %s\n", x, usuario[x-1].nome);
        }
        printf("Qual usuário você deseja jogar?\n\n-> ");
        scanf("%d", &actualUser);
        if(usuario[actualUser].nome == NULL){
            printf("\n\nEsse jogador não existe!");
            registro();
        }else
        system("cls");
        u = actualUser - 1;
        main();

    default:
        registro();
    }

}


void main(){
    setlocale(LC_ALL,"Portuguese");
    srand(time(0));
    int randomNumber = rand() % 20;
    int dificulty = 0;
    int roundCount = 0;
    int stage = 1;
    int menuOp;

    printf("######MENU######\n");
    printf("\nJogando como: %s\nTotal de pontos: %d\n\n", usuario[u].nome, usuario[u].pontos);
    printf("1 -> Jogar\n2 -> Opções de Usuário\n-> ");
    scanf("%d", &menuOp);

    if(menuOp < 1 || menuOp > 2){
        system("cls");
        main();
    }

    if(menuOp == 2){
        system("cls");
        registro();
    }

    system("cls");
    printf("Escolha o numero de chances: \n\n-> 5 - Super Fácil\n-> 4 - Fácil\n-> 3 - Medio\n-> 2 - Dificil\n-> 1 - Insano\n\n-> ");
    scanf("%d", &dificulty);

    if(dificulty < 1 || dificulty > 5){
        system("cls");
        main();
    }
        while(roundCount < dificulty && stage <= 5){
            int inputValue;
            int positiveBet, negativeBet;
            printf("De um chute: ");
            scanf("%d", &inputValue);

            if(inputValue != randomNumber){
                printf("\nPalpite errado!\n");
                roundCount++;
                switch(roundCount){
                    case 4:
                         positiveBet = randomNumber + 15;
                         negativeBet = randomNumber - 10;

                         if(positiveBet > 100){
                            positiveBet = 100;
                         }
                         if(negativeBet < 0){
                            negativeBet = 0;
                         }

                    break;

                    case 5:
                        positiveBet = randomNumber + 10;
                        negativeBet = randomNumber - 5;

                        if(positiveBet > 100){
                            positiveBet = 100;
                         }
                         if(negativeBet < 0){
                            negativeBet = 0;
                         }

                        break;

                    default:

                        positiveBet = randomNumber + 25;
                        negativeBet = randomNumber - 10;

                        if(positiveBet > 100){
                            positiveBet = 100;
                         }
                         if(negativeBet < 0){
                            negativeBet = 0;
                         }
                        break;


                }
                printf("\nDica: o número está entre: %d - %d\n\n", negativeBet, positiveBet);
            }

            if(inputValue == randomNumber){
                int randomIncrement = rand() %20;
                randomNumber +=randomIncrement;
                usuario[i].pontos++;
                stage++;
                roundCount = 0;
                printf("Parabéns você acertou!\n\n");
            }
        }
        printf("\n\nO número aleatório era: %d", randomNumber);
    }

