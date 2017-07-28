#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int Map[30][30];
int flag=0;
int vis[30];
void dfs(int x)
{
    if(x=='m'-'a')
    {
        flag=1;
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(Map[x][i]&&!vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    string s;
    flag=0;
    memset(Map,0,sizeof(Map));
    memset(vis,0,sizeof(vis));
    while(cin >> s)
    {
        Map[s[0]-'a'][s[s.length()-1]-'a']=1;
        while(cin >> s&&s[0]!='0')
        {
            Map[s[0]-'a'][s[s.length()-1]-'a']=1;
        }
        dfs('b'-'a');
        if(flag==1)
            cout << "Yes." << endl;
        else
            cout  << "No." <<endl;
        memset(Map,0,sizeof(Map));
        memset(vis,0,sizeof(vis));
        flag=0;
    }
    //return 0;
}

