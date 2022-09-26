#include <iostream>
#include <stdlib.h>

using namespace std;

bool we_have_a_winer;       // zwraca tru jak ktos wygra
bool correct_number;        // prawda gdy wybrany numer nie byl jeszcze wybierany
char o_or_x;                // przechowuje znak kolka lub krzyzyka
char tab[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void show_available_options();      // rysujemy szablon tablicy z ponumerowanymi miejscami
void draw_a_board();        // pokazujemy plansze z uzupelnionymi polami
void set_to_board(int choosen_number);      // zpisz x lub o do odpowiedniego indeksu talicy
void change_player();   // nastepuje zmiana gracza
void test_if_win();     // sprawdza czy juz ktos wygral
void clear_board();     // czysci tablice przed kolejna rozgrywka

int main(){
    for(;;){

        o_or_x = 'o';

        for( char i = 1; i < 10; i++ ){
            do{
                cout << endl;
                show_available_options();
                cout << endl;
                draw_a_board();

                cout << "\nWybierz od 1 do 9\n";
                int choosen_number;
                cin >> choosen_number;

                set_to_board( choosen_number );
                if(correct_number == false) {
                    i--;
                }
            }while(correct_number != true);

            test_if_win();
            if(we_have_a_winer == true){
                break;
            }
        }
        if(we_have_a_winer != true){
        cout << "\n=================================\n";
        cout << "Remis\n";
        cout << "=================================\n";
        }

    clear_board();

    }
    return 0;
}


void show_available_options(){      // Wyswietlenie tablicy z ponumerowanymi miejscami
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


void draw_a_board(){            // Wyswietlenie pustej planszy do gry
    for(int i = 0; i < 9; i++){
        if(i < 2 || i > 2 && i < 5 || i > 5 && i < 8){
            cout << tab[i] << " | ";
        }
        else if(i % 2 == 0 || i % 5 == 0){
            cout << tab[i] << "\n";
            if(i != 8){
                cout << "---------\n";
            }
        }
    }
}


void change_player(){
    if( o_or_x == 'x') o_or_x ='o';
    else o_or_x = 'x';
}


void set_to_board( int choosen_number ){
    if( choosen_number == 1 ){
            if( tab[0] != 'o' && tab[0] != 'x'){
                tab[0] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 2){
        if( tab[1] != 'o' && tab[1] != 'x'){
                tab[1] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 3){
        if( tab[2] != 'o' && tab[2] != 'x'){
                tab[2] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 4){
        if( tab[3] != 'o' && tab[3] != 'x'){
                tab[3] = o_or_x;
                correct_number = true;
                change_player();
            }
            else
                {
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 5){
        if( tab[4] != 'o' && tab[4] != 'x'){
                tab[4] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 6){
        if( tab[5] != 'o' && tab[5] != 'x'){
                tab[5] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 7){
        if( tab[6] != 'o' && tab[6] != 'x'){
                tab[6] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 8){
        if( tab[7] != 'o' && tab[7] != 'x'){
                tab[7] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
    }
    else if( choosen_number == 9){
        if( tab[8] != 'o' && tab[8] != 'x'){
                tab[8] = o_or_x;
                correct_number = true;
                change_player();
            }
            else{
                cout << "Bledny ruch\n";
                correct_number = false;
            }
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
            if( o_or_x == 'x') {
                cout << "\n=================================\n";
                cout << "Wygral o\n";
                cout << "=================================\n";
                we_have_a_winer = true;
            }
            else{
                cout << "\n=================================\n";
                cout << "Wygral x\n";
                cout << "=================================\n";
                we_have_a_winer = true;
            }
        }
}


void clear_board(){
    for(int i = 0; i < 9; i++){
        tab[i] = ' ';
    }
    we_have_a_winer = false;
}



