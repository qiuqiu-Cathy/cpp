/*
Welcome to HDU to take part in the first CCPC girls' competition!




As a pretty special competition, many volunteers are preparing for it with high enthusiasm.
One thing they need to do is blowing the balloons.

Before sitting down and starting the competition, you have just passed by the room where the boys are blowing the balloons. And you have found that the number of balloons of different colors are strictly different.

After thinking about the volunteer boys' sincere facial expressions, you noticed that, the problem with more balloon numbers are sure to be easier to solve.

Now, you have recalled how many balloons are there of each color.
Please output the solving order you need to choose in order to finish the problems from easy to hard.
You should print the colors to represent the problems.
Input
The first line is an integer TT which indicates the case number.
And as for each case, the first line is an integer nn, which is the number of problems.
Then there are nn lines followed, with a string and an integer in each line, in the ii-th line, the string means the color of ballon for the ii-th problem, and the integer means the ballon numbers.

It is guaranteed that:
TT is about 100.
1¡Ün¡Ü101¡Ün¡Ü10.
1¡Ü1¡Ü string length ¡Ü10¡Ü10.
1¡Ü1¡Ü bolloon numbers ¡Ü83¡Ü83.(there are 83 teams :p)
For any two problems, their corresponding colors are different.
For any two kinds of balloons, their numbers are different.
Output
For each case, you need to output a single line.
There should be nn strings in the line representing the solving order you choose.
Please make sure that there is only a blank between every two strings, and there is no extra blank.
Sample Input
3
3
red 1
green 2
yellow 3
1
blue 83
2
red 2
white 1
Sample Output
yellow green red
blue
red white
*/
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
struct problems
{
    string s;
    int num;
}p[15];
bool cmp(problems x,problems y)
{
    return x.num>y.num;
}
int main()
{
    int T,n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> p[i].s >> p[i].num;
        sort(p,p+n,cmp);
        for(int i=0;i<n-1;i++)
            cout << p[i].s <<" ";
        cout << p[n-1].s << endl;
    }
    return 0;
}
