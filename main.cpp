#include <iostream>
#include <stdlib.h>

using namespace std;


int first_or_second;
char o_or_x;
char tab[9] = {'1','2','3','4','5','6','7','8','9'};

void draw_a_board();
void set_to_board(int choosen_number);
void change_player();
void test_if_win();


int main(){

    cout << " This is our game table\n";
    draw_a_board();
    cout << "\n Choose your character( 'x' or 'o' ): ";
    char sign;
    cin >> sign;
    o_or_x = sign;

    first_or_second = 1;

    for( char i = 1; i < 9; i++ ){
        cout << " \nPlayer " << first_or_second << " now it is your turn !\n";
        cout << " Insert " << o_or_x << " to number: ";
        int choosen_number;
        cin >> choosen_number;

        set_to_board( choosen_number );

        draw_a_board();

        change_player();

        test_if_win();
    }
    cout << "To byla zacieta rozgrywka! Probojcie dalej!\n";
    return 0;
}


void draw_a_board(){

    for(int i = 0; i < 9; i++){
        if( i < 2 || i > 2 && i < 5 || i > 5 && i < 8){
            cout << tab[i] << " | ";
        }
        else if( i % 2 == 0 ){
            cout << tab[i];
            if(i != 8){
                cout << "\n---------\n";
            }
        }
        else if( i % 5 == 0 ){
            cout << tab[i];
            if(i != 8){
                cout << "\n---------\n";
            }
        }
    }
}


void change_player(){
    if( o_or_x == 'x') o_or_x ='o';
    else o_or_x = 'x';

    if( first_or_second == 1 ) first_or_second = 2;
    else first_or_second = 1;
}


void set_to_board( int choosen_number ){
    if( choosen_number == 1 ){
        tab[0] = o_or_x;
    }
    else if( choosen_number == 2){
        tab[1] = o_or_x;
    }
    else if( choosen_number == 3){
        tab[2] = o_or_x;
    }
    else if( choosen_number == 4){
        tab[3] = o_or_x;
    }
    else if( choosen_number == 5){
        tab[4] = o_or_x;
    }
    else if( choosen_number == 6){
        tab[5] = o_or_x;
    }
    else if( choosen_number == 7){
        tab[6] = o_or_x;
    }
    else if( choosen_number == 8){
        tab[7] = o_or_x;
    }
    else if( choosen_number == 9){
        tab[8] = o_or_x;
    }
}


void test_if_win(){
    if( tab[0] == tab[1] && tab[1] == tab[2] ||
        tab[3] == tab[4] && tab[4] == tab[5] ||
        tab[6] == tab[7] && tab[7] == tab[8] ||
        tab[0] == tab[3] && tab[3] == tab[6] ||
        tab[1] == tab[4] && tab[4] == tab[7] ||
        tab[2] == tab[5] && tab[5] == tab[8] ||
        tab[0] == tab[4] && tab[4] == tab[8] ||
        tab[2] == tab[4] && tab[4] == tab[6] ){
            if( o_or_x == 'x') { cout << " \nWygywa kolko\n"; }
            else    cout << " \nWygrywa krzyzyk\n";
            cout << " Koniec gry!\n"; exit(0);
        }
}


