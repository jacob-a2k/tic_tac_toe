#include <iostream>

using namespace std;

void draw_a_bord();

int main()
{
    draw_a_bord();

    return 0;
}

void draw_a_bord(){

    for(int i = 1; i < 10; i++){
        if( i < 3 || i > 3 && i < 6 || i > 6 && i < 9){
            cout << i << " | ";
        }
        else if( i % 3 == 0 ){
            cout << i;
            if(i != 9){
                cout << "\n---------\n";
            }
        }
    }
}
