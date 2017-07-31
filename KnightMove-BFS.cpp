//the rule of chess 'L'  8 directions
//BFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
//thanks to tl~
int startx,starty,endx,endy;
int map[10][10];
char start[3],eend[3];
struct node
{
	int x,y,num;
};
int d[8][2]={1,2,  2,1,  2,-1,  1,-2,  -1,-2,  -2,-1,  -2,1,  -1,2 };
void bfs(int x,int y)
{
	node t,p;
	queue<node>q;
	t.x=x;
	t.y=y;
	t.num=0;
	memset(map,0,sizeof(map));//clear the visit of chessboard every board
	map[t.x][t.y]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==endx&&t.y==endy)
		{
			printf("To get from %s to %s takes %d knight moves.\n",start,eend,t.num);
			return;
		}
		for(int i=0;i<8;i++)
		{
			if((t.x+d[i][0]>0)&&(t.x+d[i][0]<9)&&(t.y+d[i][1]>0)&&(t.y+d[i][1]<9)&&
					//判断边界
					(!map[t.x+d[i][0]][t.y+d[i][1]]))//判断移动的格子是否被访问
			{
				p.x=t.x+d[i][0];
				p.y=t.y+d[i][1];
				p.num=t.num+1;
				q.push(p);
				map[p.x][p.y] = 1;
			}
		}
	}
}
int main()
{
	while(scanf("%s%s",start,eend)!=EOF)
	{
		startx=start[0]-'a'+1;
		starty=start[1]-'1'+1;
		endx=eend[0]-'a'+1;
		endy=eend[1]-'1'+1;
		bfs(startx,starty);
	}
	return 0;
}
/*
Input 
e2 e4
Output
To get from e2 to e4 takes 2 knights move.
*/
