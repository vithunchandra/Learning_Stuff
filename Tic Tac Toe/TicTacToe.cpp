#include <iostream>
#include <vector>
#include <cstdio>

void engine(std::vector<std::vector<int>>&board,std::vector<std::vector<int>>&playerdata,int input,int &key)
{
    //input data//
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==input)
            {   
                if(playerdata[i][j]==input)
                {
                    playerdata[i][j]=0;
                    board[i][j]=0;
                    key--;
                }
            
            }
        }
    }
}

void checkwin(std::vector<std::vector<int>>&playerdata, int &check)
{
    //checkwin//
    
    //horizontal//
    for(int i=0;i<3;i++)
    {
        if(playerdata[i][0]==0)
        {
            if(playerdata[i][1]==0)
            {
                if(playerdata[i][2]==0)
                {
                std::cout<<"you win"<<std::endl;
                check=1;
                }
            }

        }

    }

    //vertikal//
    for(int i=0;i<3;i++)
    {
        if(playerdata[0][i]==0)
        {
            if(playerdata[1][i]==0)
            {
                if(playerdata[2][i]==0)
                {
                std::cout<<"you win"<<std::endl;
                check=1;
                }
            }

        }

    }

    //melintang1//
    
        if(playerdata[0][0]==0)
        {
            if(playerdata[1][1]==0)
            {
                if(playerdata[2][2]==0)
                {
                std::cout<<"you win"<<std::endl;
                check=1;
                }
            }

        }

    //melintang2//
    
        if(playerdata[0][2]==0)
        {
            if(playerdata[1][1]==0)
            {
                if(playerdata[2][0]==0)
                {
                std::cout<<"you win"<<std::endl;
                check=1;
                }
            }  

        }
}

void printboard (std::vector<std::vector<int>>&printboard)
{

}



int main ()
{    
std::vector<std::vector<int>>board={{1,2,3},{4,5,6},{7,8,9}};
std::vector<std::vector<char>>printboard={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
std::vector<std::vector<int>>playerdata1 ={{1,2,3},{4,5,6},{7,8,9}};
std::vector<std::vector<int>>playerdata2 ={{1,2,3},{4,5,6},{7,8,9}};
int check=0;
int key1=1;
int key2=1;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<printboard[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }

for(int i=0;i<5;i++)
{   
    //player1//
    int input1;
    std::cout<<"choose you number"<<std::endl;
    std::cin>>input1;

    engine(board,playerdata1,input1,key1);

    if(key1==1)
    {
        std::cout<<"that's player 2 number"<<std::endl;
    }
    
    key1=1;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(playerdata1[i][j]==0)
            {
                printboard[i][j]='X';
            }
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<printboard[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }
    
    checkwin(playerdata1,check);
    /*std::cout<<"check = "<<check<<std::endl;*/

    if (check==1)
    {
        return 0;
    }
     
    else if(check==0)
    {
         std::cout<<"player 2 your turn"<<std::endl;
    }

    //player2//
    int input2;
    std::cout<<"choose your number"<<std::endl;
    std::cin>>input2;
    engine(board,playerdata2,input2,key2);
    
    if(key2==1)
    {
        std::cout<<"that's player 1 number"<<std::endl;
    }

    key2=1;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(playerdata2[i][j]==0)
            {
                printboard[i][j]='O';
            }
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<printboard[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }

    checkwin(playerdata2,check);
    /*std::cout<<"check = "<<check<<std::endl;*/
    
    if (check==1)
    {
        return 0;
    }
     
    else if(check==0)
    {
        std::cout<<"player 1 your turn"<<std::endl;
    }
}

    std::cout<<"draw"<<std::endl;


return 0;
}
