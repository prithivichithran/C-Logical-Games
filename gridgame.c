#include <stdio.h>
#include <stdlib.h>
int arrayval(int grid[3][3]);
int* checkforzero (int grid[3][3],int *grid_zeroth_pos);
int isGridValid(int grid[3][3]);
int input(char move,int grid[3][3],int *grid_zeroth_pos);
int main()
{
	int grid[3][3]={
                        {1,0,2},
                        {3,4,5},
                        {6,7,8}
                    }; // Harcoding the values of grid initially Users can change values for various experience
    int grid_zeroth_pos[2],valid=0;
    system("clear");
    arrayval(grid);
    int *indxCurrent=checkforzero(grid,grid_zeroth_pos);
    valid = isGridValid(grid);
    int a,b,temp;
    a=indxCurrent[0];
	b=indxCurrent[1];    
    char move;
	while (valid!=1) //Swaping the values in grid using this function
    {
		printf("Enter Your Move\n");
		scanf("%s",&move);
		move = input(move,grid,grid_zeroth_pos);
		switch(move)
		{
		case 'w':
		temp=grid[a][b];
		grid[a][b]=grid[a-1][b];
		grid[a-1][b]=temp;
		arrayval(grid);
		break;
		case 'a':
		temp=grid[a][b];
		grid[a][b]=grid[a][b-1];
		grid[a][b-1]=temp;
		arrayval(grid);
		break;
		case 's':
		temp=grid[a][b];
		grid[a][b]=grid[a+1][b];
		grid[a+1][b]=temp;
		arrayval(grid);
		break;
		case 'd':
		temp=grid[a][b];
		grid[a][b]=grid[a][b+1];
		grid[a][b+1]=temp;
		arrayval(grid);
		break;
		}
		indxCurrent=checkforzero(grid,grid_zeroth_pos);
		a=indxCurrent[0];
		b=indxCurrent[1];
		valid = isGridValid(grid);
		system("clear");
		arrayval(grid);
	}
	system("clear");
	arrayval(grid);
	if(valid==1)
	{
		printf("*************\nYou Have Won!\n*************\n");
	}
    
    return 0;
}
/**
 * The Function Used Here is to print the hardcoded values of the Grid
 * Argument passed here is the actual grid value in a two dimensional array
 * Value is returned For Explicit Value
 */ 
int arrayval(int grid[3][3])
{
    int i,j;  //locally declaring for the grid values
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf(" %3d ",grid[i][j]); //Printing The Hardcoded Values
        }
        printf("\n");
    }
    return 1;
}
/**
 * Function used for checking the position where the zero is
 * here if grid value has 0 it returns its current position
 */
int* checkforzero (int grid[3][3],int *grid_zeroth_pos)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            while(grid[i][j]==0)
            {
				grid_zeroth_pos[0]=i;
				grid_zeroth_pos[1]=j;
			return grid_zeroth_pos;
            }
        }
    }
				grid_zeroth_pos[0]=-1;
				grid_zeroth_pos[1]=-1;
    return grid_zeroth_pos;
}
/**
 * Checking for The Grid value in way it is in ascending starting with zero
 * if the values in grid is arranged ascending it returns valid=1
 * else it returns 0
 */
int isGridValid(int grid[3][3])
{
	int i,j,m=0;
	for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
			if(m<=grid[i][j])
			{
				 m=grid[i][j];
				 continue ;
			} 
			else 
			{
				return 0;
			}
		}
		
	}
	

	return 1;
}
/**
 * here the function is used to get values of up,down,left,right from user
 * here the users move is returned in order to swap them
*/
int input(char move,int grid[3][3],int *grid_zeroth_pos)
{
	int *indxCurrent=checkforzero(grid,grid_zeroth_pos),i,j;
	i=indxCurrent[0];
	j=indxCurrent[1];
	switch(move)
	{
		case 'w' :
		if(i>0)
		{		
			return move;
        }
        else
        {
			printf("Invalid Move\n");
		}
        break;
        case 'a' :
         if(j>0)
		{
			return move;
        }
        else
        {
			printf("Invalid Move\n");
		}
		break ;
		case 's' :
         if(i<2)
		{
			return move;
		}
		else
        {
			printf("Invalid Move\n");
		}
		break ;
		case 'd' :
		if(j<2)
		{
			return move;
        }
        else
        {
			printf("Invalid Move\n");
		}
        break;
        default :
        printf("Enter Valid Move\n");
        break ;
	}	
return 'q';
}

