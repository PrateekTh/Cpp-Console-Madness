#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

/*#include<dos.h>
#include<time.h>*/

using namespace std;

#define X 100
#define Y 45

class vec{
    public:
    int x;
    int y;

    vec(){
        x = 0;
        y = 0;
    }

    vec( int a, int b){
        x = a;
        y = b;
    }

    void add(int a, int b){
        x = x + a;
        y = y + b;
    }

    void sub(int a, int b){
        x = x - a;
        y = y - b;
    }

};


class car{
public:
    vec pos;
    char ch = '+';

    car(){
        pos.x = 50;
        pos.y = 40;
    }
};

class enemy{
    public:
    vec pos;
    char ch = 'x';

    void spawn(){
        int x = rand()*X/RAND_MAX;

        pos.y = 1;
        pos.x = x;
    }
};


class frame{
public:
    int width = X;
    int height = Y;

    char display[X][Y];

    void clear(){
        for (int y = 0; y < Y; y++)
        {
            for(int x = 0; x < X; x++){
                display[x][y] = ' ';
            }
        }
    }

    void addtoconsole(enemy e){
        display[e.pos.x][e.pos.y] = 'x';
    }

    void addtoconsole(car c){
        display[X/2][Y-10] = '+';
        cout << '+';
    }

    void render(){

        for (int y = 0; y < Y; y++)
        {
            cout << endl;

            for(int x = 0; x < X; x++){
                cout << display[x][y];
            }

        }
    }
};





//checks for collisons
int collison(enemy e, car c){

    if( ((e.pos.x - c.pos.x) < 2) && ((e.pos.x - c.pos.x) > -2 )){
        /*collision happened*/
        return 1;
    }

    if( ((e.pos.y - c.pos.y) < 2) && ((e.pos.y - c.pos.y) > -2 )){
        /*collision happened*/
        return 1;
    }
    return 0;
}

//handles input
void input(car player){
    if(kbhit()){
        char ch;
        switch (ch)
        {
        case 'a':
            if(player.pos.x > 0){player.pos.x--;}
            break;

        case 'd':
            if(player.pos.x < X){player.pos.x++;}
            break;

        case 'w':
            if(player.pos.y > 0){player.pos.y--;}
            break;

        case 's':
            if(player.pos.y < Y){player.pos.y++;}
            break;

        default:
            break;
        }
    }
}

//the game
void play(){
    frame console;
    car player;
    enemy enemies[4];
    for (int i = 0; i < 5; i++)
        {
            enemies[i].spawn();
        }
    bool game = true;

    cout << "HERE BEFORE MAIN";

    //main loop STATUS:INCOMPLETE
    while(game){
        cout << "FUCK";
        console.clear();//clear the last frame (data)

        //enemy re-spawner
        for (int i = 0; i < 5; i++)
        {
            if(enemies[i].pos.y == Y){
                enemies[i].spawn();
            }
        }

        console.addtoconsole(player);
        

        for (int i = 0; i < 5; i++)//add the enemies to the console
        {
            console.addtoconsole(enemies[i]);
        }

        console.render();//draw the current frame

        cout << "HERE BEFORE INPUT";

        input(player);//the input from the player

        cout << "HERE BEFORE CLS";
        system("CLS");
        Sleep(100);//don't want it to run at clock speed obv


        /*for (int i = 0; i < 5; i++)//check for collisions
        {
            if(collison(enemies[i],player)){
                //game = false;
            }
        }*/

        for (int i = 0; i < 5; i++)//shift down the enemies each loop
        {
            enemies[i].pos.y++;
        }


    }

    cout << "Sorry Noob :)";
}

int main(){

play();

return 0;
}
