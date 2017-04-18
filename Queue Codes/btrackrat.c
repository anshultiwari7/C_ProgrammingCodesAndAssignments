#include<stdio.h>

int solveMazeUtil(int maze[4][4],int x,int y,int sol[4][4])
{
	if(x==3 && y==3)
	{
	sol[x][y]=1;
	return 1;
	}

	if(isSafe(maze,x,y)==1)
	{
		sol[x][y]=1;
		if (solveMazeUtil(maze,x+1,y,sol) == 1)
			return 1;

		if (solveMazeUtil(maze,x,y+1,sol) == 1)
			return 1;       /* BACKTRACK:   unmark x,y as part of solution path */

		sol[x][y]=0;
		return 0;

	}
 return 0;
}


int solve(int maze[4][4])
{
 int i,j,sol[4][4]={{0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0}};
	if(solveMazeUtil(maze,0,0,sol)==0)
	{
		printf("Solution doesn't exist");
		return 0;
	}
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf("%d ",sol[i][j]);
	printf("\n");
	}
 return 1;
}

int isSafe(int maze[4][4],int x,int y)
{
	if(x>=0 && x<4 && y>=0 && y<4 && maze[x][y]==1)
    return 1;
	return 0;
}



int main()
{
int maze[4][4]={{1,0,0,0},
                {1,1,0,1},
                {0,1,0,0},
                {1,1,1,1}};
solve(maze);
return 0;
}
