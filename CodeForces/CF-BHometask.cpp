/*
给你n个0~9的数字，可以不全部都用，问你能够组成同时被2、3、5整除的最大的数是多少。
*/
#include <bits/stdc++.h>
using namespace std;
const int  N=1e5+5;
vector<int>tar;
int vis[N];

int main()
{
    int n;
    while(cin >>n)
    {
        memset(vis,0,sizeof(vis));
        int flag=0,sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            sum+=x;
            if(!x)
                flag=1;
            tar.push_back(x);
        }
        if(!flag)
            cout << -1 << endl;
        else
        {
            sort(tar.begin(),tar.end());
            if(sum%3==0)
            {
                reverse(tar.begin(),tar.end());//从大到小
                if(tar.size()!=1&&tar[0]==0) //一串0的情况
                    cout << 0 << endl;
                else
                {
                    for(int i=0;i<tar.size();i++)
                        cout << tar[i];
                    cout << endl;
                }
            }
            else
            {
                int ok=0;
                if(sum%3==1)
                {
                    flag=0;
                    for(int i=0;i<tar.size();i++)
                    {
                        if(tar[i]%3==1)
                        {
                            ok=1;
                            vis[i]=1;
                            flag=1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        for(int i=0;i<tar.size();i++)
                        {
                            if(tar[i]%3==2)
                            {
                                vis[i]=1;
                                flag++;
                            }
                            if(flag==2)
                            {
                                ok=1;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    flag=0;
                    for(int i=0;i<tar.size();i++)
                    {
                        if(tar[i]%3==2)
                        {
                            vis[i]=1;
                            flag=1;
                            ok=1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        for(int i=0;i<tar.size();i++)
                        {
                            if(tar[i]%3==1)
                            {
                                vis[i]=1;
                                flag++;
                            }
                            if(flag==2)
                            {
                                ok=1;
                                break;
                            }
                        }
                    }
                }
                vector<int>ans;
                for(int i=tar.size()-1;i>=0;i--)
                    if(!vis[i])
                        ans.push_back(tar[i]);
                if(!ok)
                    cout << -1 << endl;
                if(ans[0]==0&&ans.size()!=1)
                    cout << 0 << endl;
                else
                {
                    for(int i=0;i<ans.size();i++)
                        cout << ans[i];
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
