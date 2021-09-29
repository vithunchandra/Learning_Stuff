#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>

bool gameover;
const int width = 20;
const int height = 20;
int x,y,fruitx,fruity,score;
int tailx[100];
int taily[100];
int tempx,tempy;
int count_tail;
enum direction{stop=0, left, right, up, down};
direction dir;

void draw()
{
    for(int i=0; i<=width+2; i++){std::cout<<"#";}
    std::cout<<"\n";
    for(int i=0; i<=height; i++)
    {
        for(int j=0; j<=width+1; j++)
        {
            if(j==0){std::cout<<"#";}
            if(j==width+1){std::cout<<"#";}
            if(x==j && y==i)
            {
                std::cout<<'O';
            }
            else if(fruitx==j && fruity==i){std::cout<<'F';}
            else
            {   
                bool print=true;
                for(int k=0;k<count_tail;k++)
                {
                    if(tailx[k]==j && taily[k]==i){std::cout<<"o"; print=false;}
                }
                if(print){std::cout<<" ";}
            }
            
        }
        std::cout<<"\n";
    }
    for(int i=0; i<=width+2; i++){std::cout<<"#";}
    std::cout<<"\nSCORE ="<<score<<std::endl;
}

void setup()
{
    bool status=false;
    srand(time(0));
    gameover = false;
    dir=stop;
    x=width/2;
    y=height/2;
    fruitx=(rand()%18)+1;
    fruity=(rand()%18)+1;
    score=0;
}

void input()
{       
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w':
                dir=up;
                break;
            case 's':
                dir=down;
                break;
            case 'a':
                dir=left;
                break;
            case 'd':
                dir=right;
                break;
            case 'x':
                gameover=true;
                break;
            default:
                break;
        }
    }
}

void logic()
{
    switch(dir)
    {
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        case left:
            x--;
            break;
        case right:
            x++;
            break;
        default:
            break;
    }
    for(int i=count_tail; i>=0; i--)
    {
        if(i==0)
        {
            tailx[i]=tempx;
            taily[i]=tempy;
        }
        else
        {
            tailx[i]=tailx[i-1];
            taily[i]=taily[i-1];
        }    
    }
    for(int i=1;i<=count_tail;i++)
    {
        if(x==tailx[i] && y==taily[i]){gameover=true;}
    }
    if(x>width || x<0 || y>height || y<0){gameover=true;}
    if(x==fruitx && y==fruity)
    {
        count_tail++;
        score=score+100;
        bool status=false;
        do
        {
            fruitx=(rand()%18)+1;
            fruity=(rand()%18)+1;
            for(int i=0;i<=count_tail;i++)
            {
                if(fruitx==tailx[i] && fruity==taily[i]){status=true;}
            }
        }while(status);
    }
    tempx=x;
    tempy=y;
}

int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("CLS");
    }
    std::cout<<"Ooops You Lose\n Score ="<<score<<std::endl;
    system("pause");
    return 0;
}