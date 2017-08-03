//博弈
//当N<3时，肯定是最开始先拿的人胜利。因为此时，N==1，N==2，只要拿一次就可以拿完。
//当N>=3时，肯定是第2个拿的人胜利，因为当N为偶数时，不管第1个人，怎么拿，第2个人拿与第一个人同样数量的硬币，且与第1人所拿硬币呈中心对称。
//最后一定是第2个人胜利。当N为奇数时，在第1轮中，
//只要第2个人所拿的硬币数与第1个人所拿的硬币数不同，且与第1人所拿硬币呈中心对称。经过第1轮后，就变成了N为偶数的情况一样的了。最后也是第2人胜利。
//卧槽我一定是个孩子！为什么自己不多试试啊。。。aaaaa
//题意：一圈硬币，由Alice 先拿，Bob后拿，可以拿一枚或相邻的两枚，1,2,3三枚连续的硬币，如果拿走第二枚，则1,3两枚硬币不相邻。
//      谁先拿完硬币谁赢
/*
Alice and Bob decide to play a funny game. At the beginning of the game they pick n(1 <= n <= 10 6) coins in a circle, as Figure 1 shows. A move consists in removing one or two adjacent coins, leaving all other coins untouched. At least
 one coin must be removed. Players alternate moves with Alice starting. The player that removes the last coin wins. (The last player to move wins. If you can't move, you lose.)

Figure 1

Note: For n > 3, we use c1, c2, ..., cn to denote the coins clockwise and if Alice remove c2, then c1 and c3 are NOT adjacent! (Because there is an empty place between c1 and c3.)

Suppose that both Alice and Bob do their best in the game.
You are to write a program to determine who will finally win the game.
Input
There are several test cases. Each test case has only one line, which contains a positive integer n (1 <= n <= 10 6). There are no blank lines between cases. A line with a single 0 terminates the input.
Output
For each test case, if Alice win the game,output "Alice", otherwise output "Bob".
Sample Input
1
2
3
0
Sample Output
Alice
Alice
Bob
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//thanks to tl~
int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
            break;
        else
        {
            if(n<3)
                cout << "Alice" << endl;
            if(n>=3)
                cout << "Bob" << endl;
        }
    }
    return 0;
}
