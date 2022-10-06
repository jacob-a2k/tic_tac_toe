#include <iostream>
#include <stdlib.h>

using namespace std;

void show_available_options();
void draw_a_board(char board[]);
bool has_winner(char player, char board[]);
char change_player(char player);
bool is_number_in_correct_range(int number);
int try_get_slot(char board[]);
void do_move(char board[], char player);
void play_game(char board[], char start_player);

int main(){
    char start_player = 'o';
	for(;;){
		char board[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
		play_game(board, start_player);
		start_player = change_player(start_player);
	}
	return 0;
}

void show_available_options(){
    for(int i = 1; i < 17; i++){
        if(i < 4 || i > 4 && i < 8 || i > 8 && i < 12 || i > 12 && i < 16){
            cout << i << " | ";
        }
        else if(i % 4 == 0){
            cout << i << "\n";
            if(i != 16){
                cout << "---------------\n";
            }
        }
    }
}

void draw_a_board(char board[]){
    for(int i = 0; i < 16; i++){
        if(i < 3 || i > 3 && i < 7 || i > 7 && i < 11 || i > 11 && i < 15){
            cout << board[i] << " | ";
        }
        else if(i % 3 == 0 || i % 7 == 0 || i % 11 == 0){
            cout << board[i] << "\n";
            if(i != 15){
                cout << "---------------\n";
            }
        }
    }
}

char change_player(char player){
    return player == 'o' ? 'x' : 'o';   // operator ternarny "? :"
}

bool has_winner(char player, char board[]){
    return  board[0] == board[1]   && board[1]  == board[2]  && board[2]  == board[3]  && board[0]  == player ||
            board[4] == board[5]   && board[5]  == board[6]  && board[6]  == board[7]  && board[4]  == player ||
            board[8] == board[9]   && board[9]  == board[10] && board[10] == board[11] && board[8]  == player ||
            board[12] == board[13] && board[13] == board[14] && board[14] == board[15] && board[12] == player ||


            board[0] == board[4]   && board[4]  == board[8]  && board[8]  == board[12]  && board[0]  == player ||
            board[1] == board[5]   && board[5]  == board[9]  && board[9]  == board[13]  && board[1]  == player ||
            board[2] == board[6]   && board[6]  == board[10] && board[10] == board[14]  && board[2]  == player ||
            board[3] == board[7]   && board[7]  == board[11] && board[11] == board[15]  && board[3]  == player ||

            board[0] == board[5]   && board[5]  == board[10] && board[10] == board[15]  && board[0]  == player ||
            board[3] == board[6]   && board[6]  == board[9]  && board[9]  == board[12]  && board[3]  == player;
}

bool is_number_in_correct_range(int number){
    return number > 0 && number < 17;
}

int try_get_slot(char board[]){
    for(;;){
        cout << endl;
        show_available_options();
        cout << endl;
        draw_a_board(board);
        cout << "\nWybierz od 1 do 16\n";
        int choosen_number;
        cin >> choosen_number;

        if(!is_number_in_correct_range(choosen_number)){
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

void do_move(char board[], char player){
    int slot = try_get_slot(board);
    board[slot] = player;
}

void play_game(char board[], char start_player){
    char player = start_player ;
    for(char i = 1; i < 17; i++){
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
