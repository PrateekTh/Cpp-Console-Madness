#include<iostream>
using namespace std;

#include <windows.h>

int height = 40;
int width = 120;

float playerX;
float playerY;
float playerA;

float miniheight = 16;
float miniwidth = 16;

float FOV = 3.1459/4;

int main(){

    //create screen
    wchar_t *screen = new wchar_t[width*height];
    HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(console);
    DWORD dwbytes = 0;

    wstring map;

    map += L"################";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"################";

    while(1){

        screen[width*height - 1] = '\0';
        WriteConsoleOutputCharacter(console, screen, width * height, {0,0}, &dwbytes );

        for (int n = 0; n<height; n++){

            float RayAngle = (playerA - FOV/2.0f) + ((float)n/(float)width) * FOV;

            float DistanceToWall = 0;
            bool hitwall = false;

            while(!hitwall){

            }

        }


    }



    return 0;
}