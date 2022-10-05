#include <iostream>
#include <stdlib.h>

using namespace std;

void show_available_options();      // rysujemy szablon tablicy z ponumerowanymi miejscami
void draw_a_board(char tab[]);        // pokazujemy plansze z uzupelnionymi polami
bool has_winner(char o_or_x, char tab[]);
void clear_board(char tab[]);
char change_player(char o_or_x);
bool is_number_in_correct_range(int number);
int try_get_slot(char tab[]);
void do_move(char tab[], char o_or_x);
void play_game(char tab[], char o_or_x);

int main(){
	for(;;){
		char tab[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		char o_or_x = 'o';
		play_game(tab, o_or_x);
		clear_board(tab);
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

char change_player(char o_or_x){
	if(o_or_x == 'o') return 'x';
	else return 'o';
}

bool has_winner(char o_or_x, char tab[]){
    return  tab[0] == tab[1] && tab[1] == tab[2] && tab[0] == o_or_x ||
            tab[3] == tab[4] && tab[4] == tab[5] && tab[3] == o_or_x ||
            tab[6] == tab[7] && tab[7] == tab[8] && tab[6] == o_or_x ||

            tab[0] == tab[3] && tab[3] == tab[6] && tab[0] == o_or_x ||
            tab[1] == tab[4] && tab[4] == tab[7] && tab[1] == o_or_x ||
            tab[2] == tab[5] && tab[5] == tab[8] && tab[2] == o_or_x ||

            tab[0] == tab[4] && tab[4] == tab[8] && tab[0] == o_or_x ||
            tab[2] == tab[4] && tab[4] == tab[6] && tab[2] == o_or_x;
}

void clear_board(char tab[]){
	for(int i = 0; i < 9; i++){
		tab[i] = ' ';
	}
}

bool is_number_in_correct_range(int number){
    return number > 0 && number < 10;
}

int try_get_slot(char tab[]){
    for(;;){
        cout << endl;
        show_available_options();
        cout << endl;
        draw_a_board(tab);
        cout << "\nWybierz od 1 do 9\n";
        int choosen_number;
        cin >> choosen_number;

        if(!is_number_in_correct_range(choosen_number)){
            cout << "Bledny ruch!\n";
            continue;
        }
        int index = choosen_number - 1;

        if(tab[index] != ' '){
            cout << "Bledny ruch!\n";
            continue;
        }
        return index;
    }
}

void do_move(char tab[], char o_or_x){
    int slot = try_get_slot(tab);
    tab[slot] = o_or_x;
}

void play_game(char tab[], char o_or_x){
    for(char i = 1; i < 10; i++){
        do_move(tab, o_or_x);
        if(has_winner(o_or_x, tab)){
            draw_a_board(tab);
            cout << "\n=================================\n";
            cout << "Wygral " << o_or_x << "!\n";
            cout << "=================================\n";
            return;
        }
        o_or_x = change_player(o_or_x);
    }
    cout << "\n=================================\n";
    cout << "Remis\n";
    cout << "=================================\n";
}
