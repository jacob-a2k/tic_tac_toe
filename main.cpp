#include <iostream>
#include <stdlib.h>

using namespace std;

void show_available_options();      // rysujemy szablon boardlicy z ponumerowanymi miejscami
void draw_a_board(char board[]);        // pokazujemy plansze z uzupelnionymi polami
bool has_winner(char player, char board[]);
char change_player(char player);
bool is_number_in_correct_range(int number);
int try_get_slot(char board[]);
void do_move(char board[], char player);
void play_game(char board[], char start_player);

int main(){
    char start_player = 'o';
	for(;;){
		char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		play_game(board, start_player);
		start_player = change_player(start_player);
	}
	return 0;
}

void show_available_options(){      // Wyswietlenie boardlicy z ponumerowanymi miejscami
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

void draw_a_board(char board[]){            // Wyswietlenie pustej planszy do gry
    for(int i = 0; i < 9; i++){
        if(i < 2 || i > 2 && i < 5 || i > 5 && i < 8){
            cout << board[i] << " | ";
        }
        else if(i % 2 == 0 || i % 5 == 0){
            cout << board[i] << "\n";
            if(i != 8){
                cout << "---------\n";
            }
        }
    }
}

char change_player(char player){
	if(player == 'o') return 'x';
	else return 'o';
}

bool has_winner(char player, char board[]){
    return  board[0] == board[1] && board[1] == board[2] && board[0] == player ||
            board[3] == board[4] && board[4] == board[5] && board[3] == player ||
            board[6] == board[7] && board[7] == board[8] && board[6] == player ||

            board[0] == board[3] && board[3] == board[6] && board[0] == player ||
            board[1] == board[4] && board[4] == board[7] && board[1] == player ||
            board[2] == board[5] && board[5] == board[8] && board[2] == player ||

            board[0] == board[4] && board[4] == board[8] && board[0] == player ||
            board[2] == board[4] && board[4] == board[6] && board[2] == player;
}

bool is_number_in_correct_range(int number){
    return number > 0 && number < 10;
}

int try_get_slot(char board[]){
    for(;;){
        cout << endl;
        show_available_options();
        cout << endl;
        draw_a_board(board);
        cout << "\nWybierz od 1 do 9\n";
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
    for(char i = 1; i < 10; i++){
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
