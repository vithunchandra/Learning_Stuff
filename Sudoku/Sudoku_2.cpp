#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

bool solve(int grid [9][9]);
bool check_condition(int grid [9][9], int row, int col, int number);
void print_grid(int grid[9][9]);
bool check_empty(int grid[9][9], int &row ,int &col);

bool solve(int grid [9][9])
{
    int row;
    int col;
    if(check_empty(grid,row,col)==false){return true;}
    for(int number=1;number<=9;number++)
    {
        if(check_condition(grid,row,col,number))
        {
            grid[row][col]=number;
            if(solve(grid)){return true;}
            grid[row][col]=0;
        }
    }
    //std::cout<<"false\n";
    return false;
}

bool check_empty(int grid[9][9], int &row ,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(grid[row][col]==0){return true;}
        }
    }
    return false;
}

bool check_condition(int grid [9][9], int row, int col, int number)
{
    for(int x=0; x<9; x++)
    {
        if(grid[row][x]==number){return false;}
    }
    for(int x=0; x<9; x++)
    {
        if(grid[x][col]==number){return false;}
    }

    int true_row=row-(row%3);
    int true_col=col-(col%3);

    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            if(grid[(true_row+x)][(true_col+y)]==number){return false;}
        }
    }
    return true;
}

void print_grid(int grid[9][9])
{
    for(int row=0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            std::cout<<grid[row][col]<<", ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    int grid[9][9] =    
                        {{ 1, 0, 0, 0, 0, 7, 0, 9, 0 },
                        { 0, 3, 0, 0, 2, 0, 0, 0, 8 },
                        { 0, 0, 9, 6, 0, 0, 5, 0, 0 },
                        { 0, 0, 5, 3, 0, 0, 9, 0, 0 },
                        { 0, 1, 0, 0, 8, 0, 0, 0, 2 },
                        { 6, 0, 0, 0, 0, 4, 0, 0, 0 },
                        { 3, 0, 0, 0, 0, 0, 0, 1, 0 },
                        { 0, 4, 0, 0, 0, 0, 0, 0, 7 },
                        { 0, 0, 7, 0, 0, 0, 3, 0, 0 }}; 
    if(solve(grid)==true)
    {
        std::cout<<"Sudoku Solved\n";
        print_grid(grid);
    }

    else{std::cout<<"Sudoku Cannnot Solved\n";}

    return 0;
}