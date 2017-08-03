/*
***尼姆博弈（Nimm Game）****：有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，
规定每次至少取一个，多者不限，最后取光者得胜。（对尼姆博弈，我们有这样地结论：
用（a，b，c）表示每堆石子数目，如果a^b^c==0，(^就是按位异或运算)就称这种局势是奇异局势，那么先手一定输。）
e.g.
火柴一共4根，
ⅰ.一堆2根，一堆2根，先手输
（先手无论取那一堆，取1个还是2个，都成为Ⅱ①或Ⅰ的非奇异局势），
此局势是奇异局势。此时2^3=(10)^(10)=(00)=0。

题目：

Here is a simple game. In this game, there are several piles of matches and two players. The two player play in turn. In each turn, one can choose a pile and take away arbitrary number of matches from the pile (Of course the number of matches, which is taken away, cannot be zero and cannot be larger than the number of matches in the chosen pile). If after a player’s turn, there is no match left, the player is the winner. Suppose that the two players are all very clear. Your job is to tell whether the player who plays first can win the game or not.
Input
The input consists of several lines, and in each line there is a test case. At the beginning of a line, there is an integer M (1 <= M <=20), which is the number of piles. Then comes M positive integers, which are not larger than 10000000. These M integers represent the number of matches in each pile.
Output
For each test case, output "Yes" in a single line, if the player who play first will win, otherwise output "No".
Sample Input
2 45 45
3 3 6 9
Sample Output
No
Yes
*/
#include <iostream>
using namespace std;
//thanks to tl~
int main()
{
    int M,ans;
    int num[20];
    while(cin >> M)
    {
        ans=0;
        for(int i=0;i<M;i++)
        {
            cin >> num[i];
            ans=ans^num[i];
        }
        if(ans==0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
