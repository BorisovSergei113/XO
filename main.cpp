#include <iostream>
#include <iomanip>
using namespace std;


char ** init_pole(char **pole){
 pole = new char * [3];
    for (int i = 0 ; i<3; i++) {
            pole[i]=new char [3];
        for (int j =0; j<3; j++) {
            pole[i][j]='0';
        }
    }
    return pole;
}

void next_turn(char ** pole,bool player){
    int choose =1;
    if (player){
    for (int i =0; i<3; i++) {
        for(int j =0;j<3;j++){
            if(pole[i][j]=='0'){
                cout<<choose<<"->"<<char(i+97)<<char(j+49)<<"(Player X)"<<endl;
                choose++;
            }
        }
    }
}
    if (!player){
        for (int i =0; i<3; i++) {
            for(int j =0;j<3;j++){
                if(pole[i][j]=='0'){
                    cout<<choose<<"->"<<char(i+97)<<char(j+49)<<"(Player O)"<<endl;
                    choose++;
                }
            }
        }
    }
    cout<<choose<<"->quit"<<endl;
}

void next_turn(char **pole,int turn,bool player){
    int choose =1;
    for (int i =0; i<3; i++) {
        for(int j =0;j<3;j++){
            if(pole[i][j]=='0'){
                if (choose== turn && player) {
                    pole[i][j]= 'X';
                    return;
                }
                if (choose== turn && !player) {
                    pole[i][j]='O';
                    return;
                }
                choose++;
            }
        }
    }
    if(turn==choose){
        cout<<"Quit"<<endl;
        exit(0);
    }
}
int case_chose(){
    int turn =0;
    cin>>turn;
    cout<<endl;
    return turn;
}

bool proverka_hor(char **pole){
    for (int i =0; i<3; i++) {
        if(pole[i][0]=='X' && pole[i][1]=='X' && pole[i][2]=='X'){
        cout<<"Player"<<"  "<<pole[i][0]<<" win"<<endl;
         return true;
        }
        if(pole[i][0]=='O' && pole[i][1]=='O' && pole[i][2]=='O'){
             cout<<"Player"<<"  "<<pole[i][0]<<" win"<<endl;
            return true;
    }
    }
        return false;
}

bool proverka_ver(char **pole){
    for (int j=0; j<3; j++) {
        if(pole[0][j]=='X' && pole[1][j]=='X' && pole[2][j]=='X'){
          cout<<"Player"<<"  "<<pole[0][j]<<" win"<<endl;
        return true;
        }
        if(pole[0][j]=='O' && pole[1][j]=='O' && pole[2][j]=='O'){
            cout<<"Player"<<"  "<<pole[0][j]<<" win"<<endl;
            return true;
        }
    }
    return false;
}

bool proverka_d(char **pole){
    if(pole[0][0]=='X' && pole[1][1]=='X' && pole[2][2]=='X'){
     cout<<"Player"<<"  "<<pole[0][0]<<" win"<<endl;
    return true;
    }
    if(pole[0][0]=='O' && pole[1][1]=='O' && pole[2][2]=='O'){
         cout<<"Player"<<"  "<<pole[0][0]<<" win"<<endl;
        return true;
    }
    if(pole[0][2]=='X' && pole[1][1]=='X' && pole[2][0]=='X'){
      cout<<"Player"<<"  "<<pole[0][2]<<" win"<<endl;
    return true;
    }
    if(pole[0][2]=='O' && pole[1][1]=='O' && pole[2][0]=='O'){
        cout<<"Player"<<"  "<<pole[0][2]<<" win"<<endl;
        return true;
    }
    return false;
}

bool win_game(char **pole){
    return (proverka_hor(pole)||proverka_ver(pole)||proverka_d(pole));
}

void out_pole(char **pole){
    char c;
    cout<<setw(5)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<endl;
    cout<<setw(15)<<"+---+---+---+"<<endl;
    for (int i=0; i<3; i++)
    {
        cout<<char(i+97)<<setw(2);
        cout<< "|";
        for (int j=0; j<3; j++)
        {
            c = pole [i][j];
            c== '0' ? c=' ' : c=c;
            cout <<setw(2) << c <<setw (2) << "|";
        }
        cout <<endl;
        cout<<setw(15)<<"+---+---+---+"<<endl;
    }
    cout<<endl;
}

void del_mem(char **pole){
    for (int i=0; i<3; i++) {
        delete [] pole[i];
    }
    delete [] pole;
}

int main() {
    char **pole = nullptr;
    bool player = true;
    int xod=0;
    
    pole=init_pole(pole);
    out_pole(pole);
    while (!win_game(pole) && xod!=9) {
        xod=xod+1;
        next_turn(pole,player);
        next_turn(pole,case_chose(),player);
        out_pole(pole);
        player=!player;
    }
    if(xod==9) cout<<"Draw"<<endl;
    
    del_mem(pole);
    
    return 0;
}
