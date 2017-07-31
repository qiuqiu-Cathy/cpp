//bfs和dfs专题
/*
      呃......变形课上Harry碰到了一点小麻烦,因为他并不像Hermione那样能够记住所有的咒语而随意的将一个棒球变成刺猬什么的,但是他发现了变形咒语的一个统一规律:如果咒语是以a开头b结尾的一个单词,那么它的作用就恰好是使A物体变成B物体.
	      Harry已经将他所会的所有咒语都列成了一个表,他想让你帮忙计算一下他是否能完成老师的作业,将一个B(ball)变成一个M(Mouse),你知道,如果他自己不能完成的话,他就只好向Hermione请教,并且被迫听一大堆好好学习的道理.
 Input
 测试数据有多组。每组有多行，每行一个单词,仅包括小写字母,是Harry所会的所有咒语.数字0表示一组输入结束.
 Output
 如果Harry可以完成他的作业,就输出"Yes.",否则就输出"No."(不要忽略了句号)
 Sample Input

 so
 soon
 river
 goes
 them
 got
 moon
 begin
 big
 0

Sample Output

 Yes.


															              
															        
 Harry 可以念这个咒语:"big-got-them".
 */
#in
return 0
return 0
return 0
return 0
return 0
return 0;;;;;;clude <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int flag=0,i,len;
int Map[30][30];//word's head and tail
void dfs(int x)
{
	if(x=='m'-'a')
	{
		flag=1;
		return;
	}
	for(i=0;i<26;i++)
	{
		if((Map[x][i]==1)&&(vis[i]==0))//if(Map[x][i]&&!vis[i])
		{
			vis[i]=1;
			dfs(i);
		}
	}
}
int main()
{
	string s;
	while(cin>>s)
	{
		memset(Map,0,sizeof(Map));
		memset(vis,0,sizeof(vis));
		if(!strcmp(s,"0"))
			continue;

		f=0;
		Map[s[0]-'a'][s[s.length()-1]-'a']=1;
		f++;
		while(cin>>s,strcmp(s,"0"))
		{
			Map[s[0]-'a'][s[s.length()-1]-'a']=1;
			f++;
		}
		dfs('b'-'a');
		if(flag)
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
		flag=0;
	}
	return 0;
}
