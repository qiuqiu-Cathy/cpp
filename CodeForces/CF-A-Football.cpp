/*
A. Football
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".

Examples
input
001001
output
NO
input
1000000001
output
YES
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
   char s[105];
   int cnt;
   while(cin >> s)
   {
       if(strlen(s)<7)
            cout << "NO" <<endl;
       else
       {
            for(int i=0;i<strlen(s)-6;i++)
            {
                cnt=0;

                for(int j=1;j<=6;j++)
                    if(s[i]==s[i+j])
                    {
                        cnt++;
                        if(cnt==6)
                        {
                            cout << "YES" << endl;
                            i=strlen(s)-7;
                        }
                    }
            }
            if(cnt!=6)
                cout << "NO" << endl;
       }
   }
   return 0;
}
