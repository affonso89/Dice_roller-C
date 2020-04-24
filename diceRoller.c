/*
Write a program to roll dices
d4, d6, d8, d10, d12 and d20
User should be able to roll multiple dices
Choose dice side and number of dices
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display();

int rollDice();

void getCommand(int *dChoice, int *nbrChoice);

void setDices(int *dChoice, int *nbrChoice, int dices[12]);

int main(){
  
  int dices[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  
  system("clear");
  
  display(dices);
  rollDice(dices);
  
  return 0;
}

void display(int dices[12]){
  
  printf("==============================\n");
  printf("         DICE ROLLER\n");
  printf("==============================\n");
  printf("DICES        Nbr       RESULTS\n");
  printf("[1] d4        %d          %d\n", dices[0], dices[6]);
  printf("[2] d6        %d          %d\n", dices[1], dices[7]);
  printf("[3] d8        %d          %d\n", dices[2], dices[8]);
  printf("[4] d10       %d          %d\n", dices[3], dices[9]);
  printf("[5] d12       %d          %d\n", dices[4], dices[10]);
  printf("[6] d20       %d          %d\n", dices[5], dices[11]);
}

int rollDice(int dices[12]){
  int dChoice,nbrChoice;
  char comm;
  time_t t;
  srand((unsigned) time(&t));
  
  getCommand(&dChoice, &nbrChoice);
  
  while(comm != 'X'){
    
    setDices(&dChoice, &nbrChoice, dices);
    
    printf("Command: ");
    scanf("%c", &comm);
    
    system("clear");
    display(dices);
    
    if(comm == 'P' || comm == 'p'){
      
      getCommand(&dChoice, &nbrChoice);
      
      setDices(&dChoice, &nbrChoice, dices);
      
    } else if(comm == 'R' || comm == 'r'){
      
      dices[6] = rand() % ((4*dices[0] + 1)-(1*dices[0]))+(1*dices[0]);
      dices[7] = rand() % ((6*dices[1] + 1)-(1*dices[1]))+(1*dices[1]);
      dices[8] = rand() % ((8*dices[2] + 1)-(1*dices[2]))+(1*dices[2]);
      dices[9] = rand() % ((10*dices[3] + 1)-(1*dices[3]))+(1*dices[3]);
      dices[10] = rand() % ((12*dices[4] + 1)-(1*dices[4]))+(1*dices[4]);
      dices[11] = rand() % ((20*dices[5] + 1)-(1*dices[5]))+(1*dices[5]);
      
    } else if(comm == 'X' || comm == 'x'){
      break;
    }
      
  }
}

void getCommand(int *dChoice, int *nbrChoice){
  
  printf("\nChoose which dice you want to roll: ");
  scanf("%d", dChoice);
  while(*dChoice < 1 || *dChoice > 6){
    printf("\nInvalid entry. Choose which dice you want to roll: ");
    scanf("%d", dChoice);
  }
  printf("\nChoose how many dices to roll (9 max): ");
  scanf("%d", nbrChoice);
  while(*nbrChoice < 1 || *nbrChoice > 9){
    printf("\nInvalid entry. Choose how many dices to roll (9 max): ");
    scanf("%d", nbrChoice);
  }
}

void setDices(int *dChoice, int *nbrChoice, int dices[12]){
  
  if(*dChoice == 1){
    dices[0] = *nbrChoice;
  } else if(*dChoice == 2){
    dices[1] = *nbrChoice;
  } else if(*dChoice == 3){
    dices[2] = *nbrChoice;
  } else if(*dChoice == 4){
    dices[3] = *nbrChoice;
  } else if(*dChoice == 5){
    dices[4] = *nbrChoice;
  } else if(*dChoice == 6){
    dices[5] = *nbrChoice;
  }
  
  system("clear");
  display(dices);
  
  printf("\nType [P] to pick more dices.\n");
  printf("Type [R] to ROLL.\n");
  printf("Type [X] to EXIT.\n");
  
}