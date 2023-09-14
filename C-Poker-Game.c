//
//  main.m
//  AkbarGasimovAssignment1
//
//  Created by Akber Gasimov on 17.08.23.
//

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void checker(int comb_score) { // this function is used for checking which combination is Hit
  if (comb_score == 30 || comb_score == 35) {
    printf("\nI got UN Full!\n");
  } else if (comb_score == 50) {
    printf("\nI got a Grande!\n");
  } else if (comb_score == 20 || comb_score == 25) {
    printf("\nI got a Escalera!\n");
  } else if (comb_score == 40 || comb_score == 45) {
    printf("\nI got a Poker!\n");
  }
}
int combinations(int dice1, int dice2, int dice3, int dice4, int dice5, int roll) { //this function is used for calculating current and final score
  int score = 0;

  if ((dice1 == dice2) && (dice2 == dice3) && (dice3 == dice4) && (dice4 == dice5)) { // Grande (five of a kind)
    return score = 50;
  } else if ((dice1 == dice2 && dice1 == dice3 && dice1 == dice4) ||
    (dice1 == dice2 && dice1 == dice3 && dice1 == dice5) ||
    (dice1 == dice2 && dice1 == dice4 && dice1 == dice5) ||
    (dice1 == dice3 && dice1 == dice4 && dice1 == dice5) ||
    (dice2 == dice3 && dice2 == dice4 && dice2 == dice5)) { // Poker (Four of a kind)
    if (roll == 1) {
      return score = 45;
    }
    return score = 40;
  } else if ((dice1 == dice2 && dice2 == dice3 && dice4 == dice5) ||
    (dice1 == dice2 && dice2 == dice4 && dice3 == dice5) ||
    (dice1 == dice2 && dice2 == dice5 && dice3 == dice4) ||
    (dice1 == dice3 && dice3 == dice4 && dice2 == dice5) ||
    (dice1 == dice3 && dice3 == dice5 && dice2 == dice4) ||
    (dice1 == dice4 && dice4 == dice5 && dice2 == dice3) ||
    (dice2 == dice3 && dice3 == dice4 && dice1 == dice5) ||
    (dice2 == dice3 && dice3 == dice5 && dice1 == dice4) ||
    (dice2 == dice4 && dice4 == dice5 && dice1 == dice3) ||
    (dice3 == dice4 && dice4 == dice5 && dice1 == dice2)) { // Full House
    if (roll == 1) {
      return score = 35;
    }
    return score = 30;
  } else if ((dice1 == 1 && dice2 == 2 && dice3 == 3 && dice4 == 4 && dice5 == 5) ||
    (dice1 == 2 && dice2 == 3 && dice3 == 4 && dice4 == 5 && dice5 == 6)) {
    if (roll == 1) { //Straight
      return score = 25;
    }
    return score = 20;
  } else if ((dice1 == dice2 && dice2 == dice3) || //Three of a kind
    (dice2 == dice3 && dice3 == dice4) ||
    (dice3 == dice4 && dice4 == dice5) ||
    (dice5 == dice1 && dice1 == dice3) ||
    (dice1 == dice2 && dice2 == dice4) ||
    (dice2 == dice4 && dice4 == dice5) ||
    (dice5 == dice1 && dice1 == dice4) ||
    (dice1 == dice3 && dice3 == dice5) ||
    (dice2 == dice3 && dice3 == dice5) ||
    (dice1 == dice2 && dice2 == dice5)) {

    if (dice1 == dice2 && dice2 == dice3) {
      return score = dice1 + dice2 + dice3;
    } else if (dice2 == dice3 && dice3 == dice4) {
      return score = dice2 + dice3 + dice4;
    } else if (dice3 == dice4 && dice4 == dice5) {
      return score = dice3 + dice4 + dice5;
    } else if (dice1 == dice3 && dice3 == dice5) {
      return score = dice1 + dice3 + dice5;
    } else if (dice1 == dice4 && dice4 == dice5) {
      return score = dice1 + dice4 + dice5;
    } else if (dice2 == dice4 && dice4 == dice5) {
      return score = dice2 + dice4 + dice5;
    }

  } else if ((dice1 == dice2) || (dice2 == dice3) || (dice3 == dice4) || (dice4 == dice5) ||
    (dice1 == dice3) || (dice1 == dice4) || (dice1 == dice5) ||
    (dice2 == dice4) || (dice2 == dice5) || (dice3 == dice5)) { // Pair
    if (dice1 == dice2) score = dice1 + dice2;
    else if (dice2 == dice3) return score = dice2 + dice3;
    else if (dice3 == dice4) return score = dice3 + dice4;
    else if (dice4 == dice5) return score = dice4 + dice5;
    else if (dice1 == dice3) return score = dice1 + dice3;
    else if (dice1 == dice4) return score = dice1 + dice4;
    else if (dice1 == dice5) return score = dice1 + dice5;
    else if (dice2 == dice4) return score = dice2 + dice4;
    else if (dice2 == dice5) return score = dice2 + dice5;
    else if (dice3 == dice5) return score = dice3 + dice5;
  } else {
    return score = 0; // Return a default value for no combination
  }
  return score;
}

int roll_a_dice(void) { // Rolling dice 1-6
  return (rand() % 6) + 1;
}

int play_user(int rounds) { // Function for User to play

  printf("\nGet ready to play!\n");
  printf("\nI rolled dices for you and you got");
  int dice1, dice2, dice3, dice4, dice5, comb_score, final_score = 0, roll = 1;
  int keep1 = 0, keep2 = 0, keep3 = 0, keep4 = 0, keep5 = 0;
  dice1 = roll_a_dice();
  dice2 = roll_a_dice();
  dice3 = roll_a_dice();
  dice4 = roll_a_dice();
  dice5 = roll_a_dice();
  printf("-> [Dice 1]: %d  [Dice 2]: %d [Dice 3]: %d  [Dice 4]: %d [Dice 5]: %d", dice1, dice2, dice3, dice4, dice5);
  comb_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);
  if (rounds == 1) {
    printf("\nCurrent score is %d\n", comb_score);
    comb_score = 0;
  }
  for (roll = 1; roll < 3; roll++) {
    printf("\nWhich ones do you want to keep?(Enter for no keeping): ");
    fflush(stdin);
    char enter;
    scanf("%c", & enter);
    while (enter != '\n') { // Scanf logic for keeping
      if (enter == '1') keep1 = 1;
      else if (enter == '2') keep2 = 1;
      else if (enter == '3') keep3 = 1;
      else if (enter == '4') keep4 = 1;
      else if (enter == '5') keep5 = 1;
      scanf("%c", & enter);
    }

    printf("\nRolled the remaining dices ->");
    if (keep1 == 0) {
      dice1 = roll_a_dice();
      printf("[Dice 1]: %d", dice1);

    }
    if (keep2 == 0) {
      dice2 = roll_a_dice();
      printf("[Dice 2]: %d", dice2);

    }
    if (keep3 == 0) {
      dice3 = roll_a_dice();
      printf("[Dice 3]: %d", dice3);

    }
    if (keep4 == 0) {
      dice4 = roll_a_dice();
      printf("[Dice 4]: %d", dice4);

    }
    if (keep5 == 0) {
      dice5 = roll_a_dice();
      printf("[Dice 5]: %d", dice5);

    }

    comb_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);

    printf("\nCurrent score is %d\n", comb_score);
    checker(comb_score);
    comb_score = 0;
    if (keep1 == 1 && keep2 == 1 && keep3 == 1 && keep4 == 1 && keep5 == 1)
      break;
  }
  final_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);
  printf("Final Dices are : [Dice 1] : %d [Dice 2] : %d [Dice 3] : %d [Dice 4] : %d [Dice 5] : %d\nYour final score is %d \n", dice1, dice2, dice3, dice4, dice5, final_score);
  roll = 3;
  return final_score;
}

int play_computer(int rounds) { // Function for computer to play
  printf("\nI rolled dices and got ->");
  int dice1, dice2, dice3, dice4, dice5, comb_score, final_score = 0, roll = 1;
  int keep1 = 0, keep2 = 0, keep3 = 0, keep4 = 0, keep5 = 0;
  dice1 = roll_a_dice();
  dice2 = roll_a_dice();
  dice3 = roll_a_dice();
  dice4 = roll_a_dice();
  dice5 = roll_a_dice();
  printf(" [Dice 1]: %d  [Dice 2]: %d [Dice 3]: %d  [Dice 4]: %d [Dice 5]: %d", dice1, dice2, dice3, dice4, dice5);
  comb_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);
  checker(comb_score);

  if (rounds == 1) {
    printf("\nCurrent score is %d\n", comb_score);
    comb_score = 0;
  }
  for (roll = 1; roll < 3; roll++) { //Grande
    if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5) {
      keep1 = 1;
      keep2 = 1;
      keep3 = 1;
      keep4 = 1;
      keep5 = 1;
    } else if ((dice1 == dice2 && dice1 == dice3 && dice1 == dice4) || //Four of a kind-Poker
      (dice1 == dice2 && dice1 == dice3 && dice1 == dice5) ||
      (dice1 == dice2 && dice1 == dice4 && dice1 == dice5) ||
      (dice1 == dice3 && dice1 == dice4 && dice1 == dice5) ||
      (dice2 == dice3 && dice2 == dice4 && dice2 == dice5)) {
      if (dice1 == dice2) {
        keep1 = 1;
        keep2 = 1;
      }
      if (dice2 == dice3) {
        keep2 = 1;
        keep3 = 1;
      }
      if (dice3 == dice4) {
        keep3 = 1;
        keep4 = 1;
      }
      if (dice4 == dice5) {
        keep4 = 1;
        keep5 = 1;
      }
      if (dice5 == dice1) {
        keep5 = 1;
        keep1 = 1;
      }
    } else if ((dice1 == dice2 && dice2 == dice3 && dice4 == dice5) || // Full House
      (dice1 == dice2 && dice2 == dice4 && dice3 == dice5) ||
      (dice1 == dice2 && dice2 == dice5 && dice3 == dice4) ||
      (dice1 == dice3 && dice3 == dice4 && dice2 == dice5) ||
      (dice1 == dice3 && dice3 == dice5 && dice2 == dice4) ||
      (dice1 == dice4 && dice4 == dice5 && dice2 == dice3) ||
      (dice2 == dice3 && dice3 == dice4 && dice1 == dice5) ||
      (dice2 == dice3 && dice3 == dice5 && dice1 == dice4) ||
      (dice2 == dice4 && dice4 == dice5 && dice1 == dice3) ||
      (dice3 == dice4 && dice4 == dice5 && dice1 == dice2)) {
      keep1 = 1;
      keep2 = 1;
      keep3 = 1;
      keep4 = 1;
      keep5 = 1;

    } else if ((dice1 == 1 && dice2 == 2 && dice3 == 3 && dice4 == 4 && dice5 == 5) ||
      (dice1 == 2 && dice2 == 3 && dice3 == 4 && dice4 == 5 && dice5 == 6)) { //Straight

      keep1 = 1;
      keep2 = 1;
      keep3 = 1;
      keep4 = 1;
      keep5 = 1;

    } else if ((dice1 == dice2 && dice2 == dice3) || //Three of a kind
      (dice2 == dice3 && dice3 == dice4) ||
      (dice3 == dice4 && dice4 == dice5) ||
      (dice5 == dice1 && dice1 == dice3) ||
      (dice1 == dice2 && dice2 == dice4) ||
      (dice2 == dice4 && dice4 == dice5) ||
      (dice5 == dice1 && dice1 == dice4) ||
      (dice1 == dice3 && dice3 == dice5) ||
      (dice2 == dice3 && dice3 == dice5) ||
      (dice1 == dice2 && dice2 == dice5)) {

      if (dice1 == dice2 && dice2 == dice3) {
        keep1 = 1;
        keep2 = 1;
        keep3 = 1;
      } else if (dice2 == dice3 && dice3 == dice4) {
        keep2 = 1;
        keep3 = 1;
        keep4 = 1;
      } else if (dice3 == dice4 && dice4 == dice5) {
        keep3 = 1;
        keep4 = 1;
        keep5 = 1;
      } else if (dice5 == dice1 && dice1 == dice3) {
        keep1 = 1;
        keep3 = 1;
        keep5 = 1;
      } else if (dice1 == dice4 && dice4 == dice5) {
        keep1 = 1;
        keep4 = 1;
        keep5 = 1;
      } else if (dice2 == dice4 && dice4 == dice5) {
        keep2 = 1;
        keep4 = 1;
        keep5 = 1;
      } else if (dice1 == dice2 && dice2 == dice4) {
        keep1 = 1;
        keep2 = 1;
        keep4 = 1;
      } else if (dice1 == dice3 && dice3 == dice5) {
        keep1 = 1;
        keep3 = 1;
        keep5 = 1;
      } else if (dice2 == dice3 && dice3 == dice5) {
        keep2 = 1;
        keep3 = 1;
        keep5 = 1;
      } else if (dice1 == dice2 && dice2 == dice5) {
        keep1 = 1;
        keep2 = 1;
        keep5 = 1;
      }

    } //Pair
    else if ((dice1 == dice2) || (dice2 == dice3) || (dice3 == dice4) || (dice4 == dice5) ||
      (dice1 == dice3) || (dice1 == dice4) || (dice1 == dice5) ||
      (dice2 == dice4) || (dice2 == dice5) || (dice3 == dice5)) {

      if (dice1 == dice2) {
        keep1 = 1;
        keep2 = 1;
      } else if (dice2 == dice3) {
        keep2 = 1;
        keep3 = 1;
      } else if (dice3 == dice4) {
        keep3 = 1;
        keep4 = 1;
      } else if (dice4 == dice5) {
        keep4 = 1;
        keep5 = 1;
      } else if (dice1 == dice3) {
        keep1 = 1;
        keep2 = 1;
      } else if (dice1 == dice4) {
        keep1 = 1;
        keep4 = 1;
      } else if (dice1 == dice5) {
        keep1 = 1;
        keep5 = 1;
      } else if (dice2 == dice4) {
        keep2 = 1;
        keep4 = 1;
      } else if (dice2 == dice5) {
        keep2 = 1;
        keep5 = 1;
      } else if (dice3 == dice5) {
        keep3 = 1;
        keep5 = 1;
      }

    }
    comb_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);

    printf("\nMy current score is : %d", comb_score);
    printf("\nI am keeping:");
    if (keep1 == 1) {
      printf("[Dice 1] : %d", dice1);
    } else if (keep1 == 0) {
      dice1 = roll_a_dice();
    }
    if (keep2 == 1) {
      printf("[Dice 2] : %d", dice2);
    } else if (keep2 == 0) {
      dice2 = roll_a_dice();
    }
    if (keep3 == 1) {
      printf("[Dice 3] : %d", dice3);
    } else if (keep3 == 0) {
      dice3 = roll_a_dice();
    }
    if (keep4 == 1) {
      printf("[Dice 4] : %d", dice4);
    } else if (keep4 == 0) {
      dice4 = roll_a_dice();
    }
    if (keep5 == 1) {
      printf("[Dice 5] : %d", dice5);
    } else if (keep5 == 0) {
      dice5 = roll_a_dice();
    }
    printf("\n\nI rolled remaining dices are->");
    if (keep1 == 0) {
      printf("[Dice 1] : %d", dice1);
    }
    if (keep2 == 0) {
      printf("[Dice 2] : %d", dice2);
    }
    if (keep3 == 0) {
      printf("[Dice 3] : %d", dice3);
    }
    if (keep4 == 0) {
      printf("[Dice 4] : %d", dice4);
    }
    if (keep5 == 0) {
      printf("[Dice 5] : %d", dice5);
    }

    comb_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);

    checker(comb_score);
    comb_score = 0;
    if (keep1 == 1 && keep2 == 1 && keep3 == 1 && keep4 == 1 && keep5 == 1)
      break;
  }
  final_score = combinations(dice1, dice2, dice3, dice4, dice5, roll);
  printf("\n\nFinal Dices are : [Dice 1] : %d [Dice 2] : %d [Dice 3] : %d [Dice 4] : %d [Dice 5] : %d\nMy final score is %d \n", dice1, dice2, dice3, dice4, dice5, final_score);
  roll = 3;

  return final_score;
}

void scoresheet(int player_score, int computer_score, int rounds) {
  printf("\nOur scoresheet after round %d\n", rounds);
  printf("\n=============================\n");
  printf("Computer \t Player\n");
  printf("%d \t\t\t\t %d\n", computer_score, player_score);
}
int main(void) {

  srand(time(NULL));
  int rounds, player_start, computer_start, computer_score = 0, player_score = 0;
  printf("Welcome to the Cacho Alalay game.\n");
  printf("Let’s get started!\n\n");

  printf("How many rounds would you like to play?: ");
  scanf("%d", & rounds);

  //Rolling dice for computer and player to decide who will play first
  computer_start = roll_a_dice();
  player_start = roll_a_dice();
  printf("\nI have rolled the dice and got %d!\n", computer_start);
  printf("I have rolled the dice for you and you got %d!", player_start);

  //tie condition
  while (computer_start == player_start) {
    printf("\nRerolling again!");
    computer_start = roll_a_dice();
    player_start = roll_a_dice();
    printf("\nI have rolled the dice and got %d!\n\n", computer_start);
    printf("\nI have rolled the dice for you and you got %d!\n\n", player_start);
  }

  if (computer_start > player_start) {
    printf("\nI go first!\n\n");
  } else {
    printf("\nYou go first!\n\n");
  }
  //round logic if player starts first it will go, player->computer->player->computer in order.
  for (int i = 1; i <= rounds; i++) {
    if (computer_start > player_start) {
      printf("Round %d --- Computer", i);
      computer_score += play_computer(i);
      printf("Round %d --- Player", i);
      player_score += play_user(i);
      scoresheet(player_score, computer_score, i);
    } else {
      printf("Round %d --- Player", i);
      player_score += play_user(i);
      printf("Round %d --- Computer", i);
      computer_score += play_computer(i);
      scoresheet(player_score, computer_score, i);
    }
  }
  if (player_score > computer_score) {
    printf("\nPLAYER WINS!\n");
  } else if (computer_score > player_score) {
    printf("\nCOMPUTER WINS!\n");
  } else {
    printf("\nTIE!\n");
  }

  return 0;
}
