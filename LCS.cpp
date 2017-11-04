#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
char x[maxn];
char y[maxn];
int c[maxn][maxn];//Xi��Yj������������еĳ���
int b[maxn][maxn];
int m,n;
int len;
void lcsLength(int l1,int l2)
{
    for(int i=1;i<=l1;i++) c[i][0]=0;
    for(int i=1;i<=l2;i++) c[0][i]=0;
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
                //��ʾXi��Yj�����������������Xi-1��Yj-1���������������β������xi���õ���������
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
                //��ʾXi��Yj���������������Xi-1��Yj���������������ͬ
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
                //��ʾXi��Yj���������������Xi��Yj-1���������������ͬ
            }
        }
    }
}


void lcsOut(int m,int n,char path[],int pos)
{
    if(pos==0)
    {
        for(int i = 1;i <= len; i++)
        {
            if(i != 1) cout<<' ';
            cout << path[i];
        }
        cout << endl;//����ַ���
    }
    else
    {
        if(b[m][n] == 1)
        { //�����ǰ�������ַ���ȣ����빫���Ӵ�
            path[pos] = x[m];
            pos--;
            lcsOut(m-1,n-1,path,pos);  //�����Ϸ�����
        }
        else
        {
            if(c[m][n-1] > c[m-1][n])
            {
                lcsOut(m,n-1,path,pos);   //�������
            }
            else if(c[m][n-1] < c[m-1][n])
            {
                lcsOut(m-1,n,path,pos);  //���ϱ���
            }
            else
            {   //��c[m][n-1]==c[m-1][n]��ʱ�򣬷ֱ����ϡ��������
                //��˲����˲�ͬ���������
                lcsOut(m,n-1,path,pos);
                lcsOut(m-1,n,path,pos);
            }
        }
    }
}
void lcsOutall() {
    char ch[100];
    lcsOut(m,n,ch,len);
}

int main()
{
    int cnt,j=1;
    cin >> cnt;
    while(j <= cnt)
    {
        len=0;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        cin >> m >> n;
        for(int i = 1;i <= m; i++)
        {
            cin >> x[i];
            if(x[i]==' ')
                i--;
        }
        for(int i = 1;i <= n; i++)
        {
            cin >> y[i];
            if(y[i]==' ')
                i--;
        }
        lcsLength(m,n);
        len=c[m][n];
        printf("Case %d\n%d\n",j++,len);
        lcsOutall();

    }
    return 0;
}

