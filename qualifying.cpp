#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
	int N;
	int num[505];
	int v; //记录积分
	int flagw;//记录晋级赛中赢的次数
	int flagf;//记录晋级赛中输的次数
	int f;//记录等级eg 1——>D;2——>C
	while(scanf("%d",&N)==1)
	{
		v=0;
		flagw=0;
		flagf=0;
		f=1;
		memset(num,0,sizeof(num));
		for(int i=0;i<N;i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i=0;i<N;i++)
		{
			if(v>=100)
			{
				if(num[i]==1)
					flagw++;
				if(num[i]==0)
					flagf++;
				if(flagw==2)
				{
					v=0;
					flagw=0;
					flagf=0;
					f++;
				}
				else if(flagf==2)
				{
					v=60;
					flagw=0;
					flagf=0;
				}

			}
			else
			{
				if(num[i]==1)
					v=v+10;
				if(num[i]==0)
				if(v>=5)
					v=v-5;
			}
		}
		if(f==1)
			printf("D\n");
		if(f==2)
			printf("C\n");
		if(f==3)
			printf("B\n");
		if(f==4)
			printf("A\n");
		if(f>=5)
			printf("S\n");
	}
	return 0;
}

