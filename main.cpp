#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

void show_available_options();      // rysujemy szablon tablicy z ponumerowanymi miejscami
void draw_a_board(char tab[]);        // pokazujemy plansze z uzupelnionymi polami
char set_to_board(int choosen_number,char tab[], char o_or_x);
char if_slot_is_empty(int choosen_number, char tab[], char o_or_x);
char change_player(char o_or_x);
bool test_if_win(char o_or_x, char tab[]);
void clear_board(char tab[]);

int main(){
	for(;;){

		char tab[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		char o_or_x ;

		for(char i = 1; i < 10; i++){
			o_or_x = change_player(o_or_x);
            char our_sign;
			do{
				cout << endl;
				show_available_options();
				cout << endl;
				draw_a_board(tab);
				cout << "\nWybierz od 1 do 9\n";
				int choosen_number;
                cin >> choosen_number;


				int index = choosen_number - 1;
				our_sign = set_to_board(choosen_number, tab, o_or_x);
				if(our_sign != 'f'){
					tab[index] = our_sign;
				}
				else{
					cout << "Bledny ruch!\n";
				}
			}while(our_sign == 'f');

			if(test_if_win(o_or_x, tab) == true){
				break;
			}
		}
		if(test_if_win(o_or_x, tab) != true){
	        	cout << "\n=================================\n";
        		cout << "Remis\n";
        		cout << "=================================\n";
		}

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


char if_slot_is_empty(int choosen_number, char tab[], char o_or_x){
	char sign;
	int  i = choosen_number - 1;
	if(tab[i] != 'o' && tab[i] != 'x'){     //warunek sprawdzajacy czy w polu jest znak
		sign = o_or_x;
		return sign;
	}
	else{
		sign = 'f';
		return sign;
	}
}


char set_to_board(int choosen_number,char tab[], char o_or_x){
	char sign;
	for(int i = 1; i < 10; i++){
		if(choosen_number == i){
			sign = if_slot_is_empty(choosen_number, tab, o_or_x) ;
			return sign;
		}
		else if( choosen_number < 1 || choosen_number > 9){
            sign = 'f';
            return sign;
		}
	}
}


char change_player(char o_or_x){
	if(o_or_x == 'o') return 'x';
	else return 'o';
}


bool test_if_win(char o_or_x, char tab[]){
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
                	cout << "Wygral x\n";
                	cout << "=================================\n";
                	return true;
            	}
            	else{
              	  	cout << "\n=================================\n";
              	  	cout << "Wygral o\n";
                	cout << "=================================\n";
                	return true;
            	}
		}
}


void clear_board(char tab[]){
	for(int i = 0; i < 9; i++){
		tab[i] = ' ';
	}
}





