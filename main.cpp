#include <iostream>
#include <stdlib.h>

using namespace std;

char o_or_x;
char tab[9]; //= {'1','2','3','4','5','6','7','8','9'};

void show_available_options();
void draw_a_board();
void set_to_board(int choosen_number);
void change_player();
void test_if_win();



int main(){

    o_or_x = 'o';

    for( char i = 1; i < 10; i++ ){
        cout << endl;
        show_available_options();
        cout << endl;
        draw_a_board();

        cout << "\nWybierz od 1 do 9\n";
        int choosen_number;
        cin >> choosen_number;

        set_to_board( choosen_number );

        change_player();

        test_if_win();
    }
    cout << "Remis\n";

    return 0;
}


void show_available_options(){
    for(int i = 1; i < 10; i++){
        if(i < 3 || i > 3 && i < 6 || i > 6 && i < 9){
            cout << i << " | ";
        }
        else if(i % 3 == 0){
            cout << i << "\n";
            if(i != 9){
                cout << "---------\n";
            }
        }
    }
}


void draw_a_board(){

    cout << tab[0] << " | " << tab[1] << " | " << tab[2] << "\n";
    cout << "---------\n";
    cout << tab[3] << " | " << tab[4] << " | " << tab[5] << "\n";
    cout << "---------\n";
    cout << tab[6] << " | " << tab[7] << " | " << tab[8] << "\n";
}


void change_player(){
    if( o_or_x == 'x') o_or_x ='o';
    else o_or_x = 'x';
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
    if( tab[0] == tab[1] && tab[1] == tab[2] && tab[0] == 'o' || tab[0] == tab[1] && tab[1] == tab[2] && tab[0] == 'x' ||
        tab[3] == tab[4] && tab[4] == tab[5] && tab[3] == 'o' || tab[3] == tab[4] && tab[4] == tab[5] && tab[3] == 'x' ||
        tab[6] == tab[7] && tab[7] == tab[8] && tab[6] == 'o' || tab[6] == tab[7] && tab[7] == tab[8] && tab[6] == 'x' ||
        tab[0] == tab[3] && tab[3] == tab[6] && tab[0] == 'o' || tab[0] == tab[3] && tab[3] == tab[6] && tab[0] == 'x' ||
        tab[1] == tab[4] && tab[4] == tab[7] && tab[1] == 'o' || tab[1] == tab[4] && tab[4] == tab[7] && tab[1] == 'x' ||
        tab[2] == tab[5] && tab[5] == tab[8] && tab[2] == 'o' || tab[2] == tab[5] && tab[5] == tab[8] && tab[2] == 'x' ||
        tab[0] == tab[4] && tab[4] == tab[8] && tab[0] == 'o' || tab[0] == tab[4] && tab[4] == tab[8] && tab[0] == 'x' ||
        tab[2] == tab[4] && tab[4] == tab[6] && tab[2] == 'o' || tab[2] == tab[4] && tab[4] == tab[6] && tab[2] == 'x' ){

            draw_a_board();
            if( o_or_x == 'x') { cout << " \nWygrywa kolko\n"; }
            else    cout << " \nWygrywa krzyzyk\n";
            cout << " Koniec gry!\n"; exit(0);
        }
}


