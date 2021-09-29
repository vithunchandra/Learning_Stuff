#include <iostream>

using namespace std;

bool CheckCol(int grid[9][9],int col,int num)
{
    for(int row=0; row<9; row++)
    {
        if(grid[row][col]==num)
        {return false;}
    }
    return true;
}

bool CheckRow(int grid[9][9],int row,int num)
{
    for(int col=0; col<9; col++)
    {
        if(grid[row][col]==num)
        {return false;}
    }
    return true;
}

bool CheckBox(int grid[9][9],int row,int col,int num)
{
    int start_row=row-(row%3);
    int start_col=col-(col%3);
    for (start_row;start_row<start_row+3;start_row++)
    {
        for (start_col; start_col<start_col+3 ;start_col++)
        {
            if(grid[start_row][start_col]==num)
            {return false;}
        }
    }
    return true;
}

bool IsSafe(int grid[9][9],int row,int col,int num)
{
    for(int x=0; x<9; x++)
    {
        if(grid[x][col]==num)
        {return false;}
    }
    for(int y=0; y<9; y++)
    {
        if(grid[row][y]==num)
        {return false;}
    }
    int start_row=row-(row%3);
    int start_col=col-(col%3);
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if(grid[start_row+i][start_col+j]==num)
            {return false;}
        }
    }
    
    return true;
}

bool SolveSudoku(int grid[9][9],int row, int col)
{
    if(row==8 && col==9){return true;}
    if(col==9){row++; col=0;}
    if(grid[row][col]>0)
    {
        return SolveSudoku(grid,row,col+1);
    }
    for(int i=1; i<=9; i++)
    {
        if(IsSafe(grid, row, col, i))
        {
            grid[row][col]=i;
            if(SolveSudoku(grid,row,col+1)){return true;}
        }
        grid[row][col]=0;
    }
    return false;
}

void Print(int grid[9][9])
{
    for(int row=0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            std::cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main ()
{
    int grid[9][9]={
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
    
    if(SolveSudoku(grid,0,0)){Print(grid);}
    else{cout<<"Sudoku Cannot Solved\n";}

    return 0;
}