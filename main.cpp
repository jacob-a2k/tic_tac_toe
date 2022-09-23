#include <iostream>
#include <stdlib.h>

using namespace std;

int player;
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char who_play;              // gra kolko czy krzyzyk

void game();
void draw_board();
void pick_slot(int slot);
void check();               //sprawdzmy czy ktos wygral
void change_player();

int main(){


    game();


    return 0;
}


void game(){
    cout << " Plyer one, choose your marker: ";
    char marker_1;
    cin >> marker_1;

    player = 1;
    who_play = marker_1;

    draw_board();

    // mozna wykonac maksymalnie 9 ruchow poniewaz tyle jest pól
    for(int i = 0; i < 9; i++){
        cout << "It is player " << player << " turn. Enter a slot: ";
        int slot;
        cin >> slot;

        pick_slot(slot);

        draw_board();

        change_player();
    }
    cout << " Tic_Tac_Toe ended in a draw!\n";

}


void pick_slot( int slot){

    if(slot == 1){
        if(who_play == 'o'){
            board[0] = 'o';
            who_play = 'x';

        }
        else{
            board[0] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 2){
        if(who_play == 'o'){
            board[1] = 'o';
            who_play = 'x';
        }
        else{
            board[1] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 3){
        if(who_play == 'o'){
            board[2] = 'o';
            who_play = 'x';
        }
        else{
            board[2] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 4){
        if(who_play == 'o'){
            board[3] = 'o';
            who_play = 'x';
        }
        else{
            board[3] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 5){
        if(who_play == 'o'){
            board[4] = 'o';
            who_play = 'x';
        }
        else{
            board[4] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 6){
        if(who_play == 'o'){
            board[5] = 'o';
            who_play = 'x';
        }
        else{
            board[5] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 7){
        if(who_play == 'o'){
            board[6] = 'o';
            who_play = 'x';
        }
        else{
            board[6] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 8){
        if(who_play == 'o'){
            board[7] = 'o';
            who_play = 'x';
        }
        else{
            board[7] = 'x';
            who_play = 'o';
        }
        check();
    }

    if(slot == 9){
        if(who_play == 'o'){
            board[8] = 'o';
            who_play = 'x';
        }
        else{
            board[8] = 'x';
            who_play = 'o';
        }
        check();
    }
}


void check  (){
     if((board[0] == board[1] && board[1] == board[2] && board[0] != '1') ||       // sprawdzenie kto wygral
        (board[3] == board[4] && board[4] == board[5] && board[0] != '1') ||       // w pionie, poziomie, skos
        (board[6] == board[7] && board[7] == board[8] && board[0] != '1') ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != '1') ||
        (board[1] == board[4] && board[4] == board[7] && board[0] != '1') ||
        (board[2] == board[5] && board[5] == board[8] && board[0] != '1') ||
        (board[0] == board[4] && board[8] == board[2] && board[0] != '1') ||
        (board[2] == board[4] && board[4] == board[6] && board[0] != '1') ){

             draw_board();

             if( who_play == 'x'){
                cout << " Circle WINS!\n";
             }
             else{
                cout << " Cross WINS!\n";
             }
             cout << " Game Over!";
             exit(0);
     }
}


void draw_board(){
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;     // narysowanie planszy
    cout << "----------\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "----------\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}


void change_player(){
    if( player == 1 ) player = 2;
    else player = 1;
}
