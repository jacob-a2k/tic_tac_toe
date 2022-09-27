#include <iostream>
#include <stdlib.h>

using namespace std;

void show_available_options();      // rysujemy szablon tablicy z ponumerowanymi miejscami
void draw_a_board(char tab[]);        // pokazujemy plansze z uzupelnionymi polami
void set_to_board_if_number(int choosen_number, bool & correct_number, char & o_or_x, char tab[]);    // wpisuje do odpowiedniego indeksu zaleznie od wybranego numeru
void set_to_board(int choosen_number, bool & correct_number, char & o_or_x, char tab[]);      // zpisz x lub o do odpowiedniego indeksu talicy
//void change_player(char & o_or_x);   // nastepuje zmiana gracza
void test_if_win(bool & we_have_a_winer, char & o_or_x, char tab[]);     // sprawdza czy juz ktos wygral
void clear_board(bool & we_have_a_winer, char tab[]);     // czysci tablice przed kolejna rozgrywka

int main(){
    for(;;){

        bool we_have_a_winer;       // zwraca tru jak ktos wygra
        char o_or_x = 'o';          // przechowuje znak kolka lub krzyzyka
        char tab[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

        for( char i = 1; i < 10; i++ ){

            bool correct_number;    // prawda gdy wybrany numer nie byl jeszcze wybierany

            do{
                cout << endl;
                show_available_options();
                cout << endl;
                draw_a_board(tab);

                cout << "\nWybierz od 1 do 9\n";
                int choosen_number;
                cin >> choosen_number;

                set_to_board( choosen_number, correct_number, o_or_x, tab );
                if(correct_number == false) {
                    i--;
                }
            }while(correct_number != true);

            test_if_win(we_have_a_winer, o_or_x, tab);
            if(we_have_a_winer == true){
                break;
            }
        }
        if(we_have_a_winer != true){
        cout << "\n=================================\n";
        cout << "Remis\n";
        cout << "=================================\n";
        }

    clear_board(we_have_a_winer, tab);

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


void draw_a_board(char tab[]){            // Wyswietlenie pustej planszy do gry
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

/*
void change_player(char & o_or_x){
    if( o_or_x == 'x') o_or_x ='o';
    else o_or_x = 'x';
}
*/


void set_to_board_if_number(int choosen_number, bool &correct_number, char & o_or_x, char tab[]){
	int i = choosen_number - 1;
	if(tab[i] != 'o' && tab[i] != 'x'){
		tab[i] = o_or_x;
		correct_number = true;
		if( o_or_x == 'x') o_or_x ='o';
        else o_or_x = 'x';
	}
	else{
		cout << "Bledny ruch\n";
		correct_number = false;
	}
}


void set_to_board( int choosen_number, bool & correct_number, char & o_or_x, char tab[]){
    for(int i = 1; i < 10; i++){
		if(choosen_number == i){
			set_to_board_if_number(choosen_number, correct_number, o_or_x, tab);
		}
	}
}


void test_if_win(bool & we_have_a_winer, char & o_or_x, char tab[]){
    if( tab[0] == tab[1] && tab[1] == tab[2] && tab[0] == 'o' || tab[0] == tab[1] && tab[1] == tab[2] && tab[0] == 'x' ||
        tab[3] == tab[4] && tab[4] == tab[5] && tab[3] == 'o' || tab[3] == tab[4] && tab[4] == tab[5] && tab[3] == 'x' ||
        tab[6] == tab[7] && tab[7] == tab[8] && tab[6] == 'o' || tab[6] == tab[7] && tab[7] == tab[8] && tab[6] == 'x' ||
        tab[0] == tab[3] && tab[3] == tab[6] && tab[0] == 'o' || tab[0] == tab[3] && tab[3] == tab[6] && tab[0] == 'x' ||
        tab[1] == tab[4] && tab[4] == tab[7] && tab[1] == 'o' || tab[1] == tab[4] && tab[4] == tab[7] && tab[1] == 'x' ||
        tab[2] == tab[5] && tab[5] == tab[8] && tab[2] == 'o' || tab[2] == tab[5] && tab[5] == tab[8] && tab[2] == 'x' ||
        tab[0] == tab[4] && tab[4] == tab[8] && tab[0] == 'o' || tab[0] == tab[4] && tab[4] == tab[8] && tab[0] == 'x' ||
        tab[2] == tab[4] && tab[4] == tab[6] && tab[2] == 'o' || tab[2] == tab[4] && tab[4] == tab[6] && tab[2] == 'x' ){

            draw_a_board(tab);
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


void clear_board(bool & we_have_a_winer, char tab[]){
    for(int i = 0; i < 9; i++){
        tab[i] = ' ';
    }
    we_have_a_winer = false;
}



