#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct Board {
    char *values;
    int size;
};

void show_available_options(int column_and_row);
void draw_a_board(Board board);
bool has_winner(char player, Board board);
char change_player(char player);
bool is_number_in_correct_range(int number, int column_and_row);
int try_get_slot(char board[], int column_and_row);
void do_move(Board board, char player);
void play_game(Board board, char start_player);
int board_size();
void create_board_to_game(Board board);

int main(){
    char start_player = 'o';
	for(;;){
        Board board;
        board.size = board_size();
        int all = board.size * board.size;
        board.values = new char[all];

        create_board_to_game(board);
		play_game(board, start_player);
		start_player = change_player(start_player);
		delete[] board.values;
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
                for(int i = 0; i <= c_a_r; i++){
                    cout << setw(2);
                    cout << "----";
                }
            cout << endl;
    		}
    	}
    }
}

void draw_a_board(Board board){
	for(int i = 0; i < board.size * board.size; i++){
        if(i % board.size == 0){
            if( i != 0){
                cout << endl;
                for(int i = 0; i <= board.size; i++){
                    cout << setw(2);
                    cout << "----";
                }
            cout << endl;
            }
            cout << setw(2);
            cout << board.values[i];
        }
        else if(i % board.size != 0){
            cout << setw(2);
            cout << " | ";
            cout << setw(2);
            cout << board.values[i];
        }
	}
}

char change_player(char player){
    return player == 'o' ? 'x' : 'o';   // operator ternarny "? :"
}

bool has_winner(char player, Board board){
    int z = 0;
	for(int i = 0; i < board.size; i++){         //sprawdzanie w pionie tylu kolumn ile poda uzytkownik
		for(int j = i; j < (board.size * board.size - board.size);j = j + board.size){       // komorki tablicy w pionie
			if(board.values[j] == board.values[j + board.size] && board.values[j] == player){
                z++;
			}
		}
		if(z == (board.size -1)){
            return true;
		}
        z = 0;
	}
	for(int i = 0; i < (board.size * board.size); i = i + board.size){         // sprawdznie w poziomie tylu kolumn ile poda uzytkownik
        for(int j = i; j < (i + board.size -1); j++){                   // komorki tablicy w poziomie
            if(board.values[j] == board.values[j + 1] && board.values[j] == player){
                z++;
            }
        }
        if(z == (board.size -1)){
            return true;
        }
        z = 0;
	}
	for(int i = 0; i < (board.size *board.size -1); i = i + (board.size + 1)){
        if(board.values[i] == board.values[i + (board.size +1)] && board.values[i] == player){       //sprawdzenie skosu od lewej do prawej
            z++;                                                                                        //od gora do dolu
        }
	}
	if(z == (board.size -1)){
		return true;
	}
	z = 0;

	for(int i = (board.size * board.size - board.size); i > board.size; i = i - (board.size -1) ){       //sprawdzenie skosu od lewej do prawej
        if(board.values[i] == board.values[ i - (board.size -1) ] && board.values[i] == player){      //od dolu do gory
            z++;
        }
	}
	if(z == (board.size -1)){
        return true;
	}
	z = 0;

	return false;
}

bool is_number_in_correct_range(int number, int c_a_r){
    return number > 0 && number <= (c_a_r * c_a_r);
}

int try_get_slot(Board board){
    for(;;){
        cout << endl;
        show_available_options(board.size);
        cout << endl;
        draw_a_board(board);
        cout << "\nWybierz od 1 do "<<  board.size * board.size << " \n";
        int choosen_number;
        cin >> choosen_number;

        if(!is_number_in_correct_range(choosen_number, board.size)){
            cout << "Bledny ruch!\n";
            continue;
        }
        int index = choosen_number - 1;

        if(board.values[index] != ' '){
            cout << "Bledny ruch!\n";
            continue;
        }
        return index;
    }
}

void do_move(Board board, char player){
    int slot = try_get_slot(board);
    board.values[slot] = player;
}

void play_game(Board board, char start_player){
    char player = start_player ;
    for(char i = 1; i <= board.size * board.size; i++){
        do_move(board, player);
        if(has_winner(player, board)){
            draw_a_board(board);
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

void create_board_to_game(Board board){
    for(int i = 0; i < board.size * board.size; i++ ){
        board.values[i] = ' ';
    }
}
