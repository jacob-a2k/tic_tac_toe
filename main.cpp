#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void show_available_options(int column_and_row);
void draw_a_board(char board[], int column_and_row);
bool has_winner(char player, char board[], int column_and_row);
char change_player(char player);
bool is_number_in_correct_range(int number, int column_and_row);
int try_get_slot(char board[], int column_and_row);
void do_move(char board[], char player, int column_and_row);
void play_game(char board[], char start_player, int column_and_row);
int board_size();
void create_board_to_game(int all, char tab[]);

int main(){
    char start_player = 'o';
	for(;;){
        int column_and_row = board_size();
        int all = column_and_row * column_and_row;
        char board[all];
        create_board_to_game(all, board);
		play_game(board, start_player, column_and_row);
		start_player = change_player(start_player);
	}
	return 0;
}

void show_available_options(int c_a_r){     // c_a_r == column_and_row

    for(int i = 1; i <= c_a_r * c_a_r; i++){
    	if(i % c_a_r != 0){
            cout << setw(2);
    		cout << i << " | ";
    	}
    	else if(i % c_a_r == 0){
    		cout << i << "\n";
    		if(i != c_a_r * c_a_r){
    			cout << "---------------------\n";
    		}
    	}
    }
}

void draw_a_board(char board[], int c_a_r){
	for(int i = 0; i < c_a_r * c_a_r; i++){
        if(i % c_a_r == 0){
            if( i != 0){
                cout << "\n---------------------\n";
            }
            cout << setw(2);
            cout << board[i];
        }
        else if(i % c_a_r != 0){
            cout << setw(2);
            cout << " | ";
            cout << setw(2);
            cout << board[i];
        }
	}
}

char change_player(char player){
    return player == 'o' ? 'x' : 'o';   // operator ternarny "? :"
}

bool has_winner(char player, char board[], int c_a_r){
    int z = 0;
	for(int i = 0; i < c_a_r; i++){         //sprawdzanie w pionie tylu kolumn ile poda uzytkownik
		for(int j = i; j < (c_a_r * c_a_r - c_a_r);j = j + c_a_r){       // komorki tablicy w pionie
			if(board[j] == board[j + c_a_r] && board[j] == player){
                z++;
			}
		}
		if(z == (c_a_r -1)){
            return true;
		}
        z = 0;
	}
	for(int i = 0; i < (c_a_r * c_a_r); i = i + c_a_r){         // sprawdznie w poziomie tylu kolumn ile poda uzytkownik
        for(int j = i; j < (i + c_a_r); j++){                   // komorki tablicy w poziomie
            if(board[j] == board[j + 1] && board[j] == player){
                z++;
            }
        }
        if(z == (c_a_r -1)){
            return true;
        }
        z = 0;
	}
	for(int i = 0; i < c_a_r -1; i++){
        	if(board[i * (c_a_r + 1)] == board[ ((i + 1) * c_a_r + (i + 1)) ] && board[i] == player){       //sprawdzenie skosu od lewej do prawej
        		z++;                                                                                        //od gora do dolu
        	}
	}
	if(z == c_a_r -1){
		return true;
	}
	z = 0;

	for(int i = (c_a_r * c_a_r - c_a_r); i > c_a_r; i = i - (c_a_r -1) ){       //sprawdzenie skosu od lewej do prawej
        if(board[i] == board[ i - (c_a_r -1) ] && board[i] == player){      //od dolu do gory
            z++;
        }
	}
	if(z == (c_a_r -1) ){
        return true;
	}
	z = 0;

	return false;
}

bool is_number_in_correct_range(int number, int c_a_r){
    return number > 0 && number <= (c_a_r * c_a_r);
}

int try_get_slot(char board[], int c_a_r){
    for(;;){
        cout << endl;
        show_available_options(c_a_r);
        cout << endl;
        draw_a_board(board,c_a_r);
        cout << "\nWybierz od 1 do "<<  c_a_r * c_a_r << " \n";
        int choosen_number;
        cin >> choosen_number;

        if(!is_number_in_correct_range(choosen_number, c_a_r)){
            cout << "Bledny ruch!\n";
            continue;
        }
        int index = choosen_number - 1;

        if(board[index] != ' '){
            cout << "Bledny ruch!\n";
            continue;
        }
        return index;
    }
}

void do_move(char board[], char player, int c_a_r){
    int slot = try_get_slot(board, c_a_r);
    board[slot] = player;
}

void play_game(char board[], char start_player, int c_a_r){
    char player = start_player ;
    for(char i = 1; i <= c_a_r * c_a_r; i++){
        do_move(board, player, c_a_r);
        if(has_winner(player, board, c_a_r)){
            draw_a_board(board, c_a_r);
            cout << "\n=================================\n";
            cout << "Wygral " << player << "!\n";
            cout << "=================================\n";
            return;
        }
        player = change_player(player);
    }
    cout << "\n=================================\n";
    cout << "Remis\n";
    cout << "=================================\n";
}

int board_size(){
    cout << "Witaj!Podaj liczbe kolumn i wierszy na planszy: ";
    int column_and_row;
    cin >> column_and_row;
    return column_and_row;
}

void create_board_to_game(int all, char tab[]){
    for(int i = 0; i < all; i++ ){
        tab[i] = ' ';
    }
}
