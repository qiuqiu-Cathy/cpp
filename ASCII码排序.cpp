/*
���������ַ��󣬰����ַ���ASCII���С�����˳������������ַ���
Input
���������ж��飬ÿ��ռһ�У��������ַ���ɣ�֮���޿ո�
Output
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
Sample Input
qwe
asd
zxc
Sample Output
e q w
a d s
c x z
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
    char s[5];
    while(cin >> s)
    {
        int a[5],temp;
        for(int i=0;i<3;i++)
        {
            a[i]=s[i];
          //  cout << a[i] << endl;
        }

        for(int i=0;i<2;i++)
            for(int j=i+1;j<3;j++)
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
        for(int i=0;i<3;i++)
            s[i]=a[i];

        cout << s[0] << " " << s[1] << " " << s[2] << endl;
    }
    return 0;
}
