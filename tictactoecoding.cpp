#include <iostream>
#include <conio.h>

using namespace std;

void printInputMatrix();

void printBoard();

int addMark();

int check();

char board[3][3] = {' ',' ',' ',
                    ' ',' ',' ',
                    ' ',' ',' '};

int turn = 1;
char mark = 'O';
int input;

int main () {

    int won = 0;
    int validInput = 0;
    string start;

    cout<<"---------------------------------------------"<<endl;
    cout<<"  Selamat Datang di Permainan Tic Tac Toe!!"<<endl;
    cout<<"   Permainan ini dibuat oleh 'Gan/4/Sie'!"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"\n\nCatatan : Permainan ini membutuhkan 2 orang pemain agar permainan menjadi lebih menarik!\n";
    cout<<"\n--->>>Silahkan Ketik 'Y' untuk Mulai Bermain atau '0' untuk Batal Bermain : ";
    cin>>start;


    if(start == "Y" || start == "y") {
        for(int i =0; i<9; i++) {
            system("cls");
            printBoard();
            if(turn) cout<<"\nSekarang Giliran Pemain 1 (Simbol : O)"<<endl;
            else cout<<"\nSekarang Giliran Pemain 2 (Simbol : X)"<<endl;
            printInputMatrix();
            cout<<"\nKetik Kode Matrix untuk meletakkan simbol Anda disini : ";
            cin>>input;
            while(input<1 || input>9) {
                cout<<"Kode Invalid! Mohon Ketik Ulang dengan Benar : ";
                cin>>input;
            }
            if(turn) mark = 'O';
            else mark = 'X';

            validInput = addMark();
            if( !validInput ){
                i--;
                continue;
            }

            won = check();
            if ( won ) {
                system("cls");
                printBoard();
                if(turn) {
                    cout<<"\n---------------------------------------------------------"<<endl;
                    cout<<"           Selamat Pemain ke-1 Kamu MENANG!"<<endl;
                    cout<<"          Terima Kasih telah mencoba codingan ini!!"<<endl;
                    cout<<"    Sampai bertemu di Pemrograman selanjutnya, Byeeeee!"<<endl;
                    cout<<"---------------------------------------------------------"<<endl;
                }
                else {
                    cout<<"\n---------------------------------------------------------"<<endl;
                    cout<<"           Selamat Pemain ke-1 Kamu MENANG!"<<endl;
                    cout<<"          Terima Kasih telah mencoba codingan ini!!"<<endl;
                    cout<<"    Sampai bertemu di Pemrograman selanjutnya, Byeeeee!"<<endl;
                    cout<<"---------------------------------------------------------"<<endl;
                }
                getch();
                break;
            }
            if(i==8) {
                system("cls");
                printBoard();
                cout<<"\n---------------------------------------------------------"<<endl;
                cout<<"                     Permainan SERI!!!"<<endl;
                cout<<"          Terima Kasih telah mencoba codingan ini!!"<<endl;
                cout<<"    Sampai bertemu di Pemrograman selanjutnya, Byeeeee!"<<endl;
                cout<<"---------------------------------------------------------"<<endl;
            }

            turn = !turn;
        }
    }

    else {
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"       Terima Kasih telah mencoba codingan ini!!"<<endl;
        cout<<"  Sampai bertemu di Pemrograman selanjutnya, Byeeeee!"<<endl;
        cout<<"-------------------------------------------------------"<<endl;

        return 0;
    }
    

    return 0;
}

void printInputMatrix() {
    cout<<"\n\nINPUT MATRIX\n"<<endl;
    cout<<" 1 | 2 | 3"<<endl;
    cout<<"-----------"<<endl;
    cout<<" 4 | 5 | 6"<<endl;
    cout<<"-----------"<<endl;
    cout<<" 7 | 8 | 9"<<endl;
}

void printBoard(){
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
}

int addMark(){
    for(int i=0,k=1; i<3; i++){
        for(int j=0; j<3; j++,k++){
            if(k == input)
                if(board[i][j] == ' ') {
                    board[i][j] = mark;
                    return 1;
                }
                else {
                    cout<<"Kode masukkan salah!"<<endl;
                    getch();
                    return 0;
                }
        }
    }
}

int check(){
    //mengecek baris
    if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
        return 1;
    if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
        return 1;
    if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
        return 1;

    //mengecek kolom
    if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
        return 1;
    if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
        return 1;
    if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
        return 1;

    //mengecek bidang diagonal
    if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
        return 1;
    if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
        return 1;
    
    return 0;
}