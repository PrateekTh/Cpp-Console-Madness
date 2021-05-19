#include<iostream>
#include<windows.h>
#include<conio.h>

/*#include<dos.h>
#include<time.h>*/

using namespace std;

#define X 1280
#define Y 720

class frame{
public:
    int width = X;
    int height = Y;

    char display[X][Y];

    void render(){
        for (int y = 0; y < Y; y++)
        {
            for(int x = 0; x < X; x++){
                cout << display[x][y];
            }
        }
    }
};

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

    void draw(frame sc){
        sc.display[x][y] = 'x';
    }

};

class car{
public:
    vec pos;
    char ch = '+';

    car(){
        pos.x = X/2;
        pos.y = Y - 3;
    }

    void draw(frame f){
        for (int i = -1; i < 2; i++)
        {
            f.display[pos.x + i][pos.y] = ch;
        }

        for (int i = -1; i < 3; i++)
        {
            f.display[pos.x][pos.y + i] = ch;
        }
    }
};

class enemy{
    public:
    vec pos;
    char ch = 'x';

    void draw(frame f){
        for (int i = -1; i < 2; i++)
        {
            f.display[pos.x + i][pos.y] = ch;
        }

        for (int i = -1; i < 3; i++)
        {
            f.display[pos.x][pos.y + i] = ch;
        }
    }

    void spawn(){
        int x = rand()*10/RAND_MAX;

        pos.y = 1;
        pos.x = x;
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
void input(vec pos){
    if(kbhit()){
        char ch;
        switch (ch)
        {
        case 'a':
            pos.x--;
            break;
        
        case 'd':
            pos.x++;
            break;

        case 'w':
            pos.y--;
            break;

        case 's':
            pos.y++;
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
    bool game = true;


    //main loop STATUS:INCOMPLETE
    while(game){

        //enemy re-spawner
        for (int i = 0; i < 5; i++)
        {
            if(enemies[i].pos.y == Y){
                enemies[i].spawn();
            }
        }

        player.draw(console);//add the player to the console

        for (int i = 0; i < 5; i++)
        {
            enemies[i].draw(console);
        }

        console.render();//draw the current frame

        for (int i = 0; i < 5; i++)//check for collisions
        {
            if(collison(enemies[i],player)){
                game = false;
            }
        }

        for (int i = 0; i < 5; i++)//shift down the enemies each loop
        {
            enemies[i].pos.y++;
        }

        Sleep(20);//don't want it to run at clock speed obv
    }

    cout << "Sorry Noob :)";
}

int main(){


return 0;
}