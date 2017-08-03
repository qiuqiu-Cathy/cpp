//����
//��N<3ʱ���϶����ʼ���õ���ʤ������Ϊ��ʱ��N==1��N==2��ֻҪ��һ�ξͿ������ꡣ
//��N>=3ʱ���϶��ǵ�2���õ���ʤ������Ϊ��NΪż��ʱ�����ܵ�1���ˣ���ô�ã���2���������һ����ͬ��������Ӳ�ң������1������Ӳ�ҳ����ĶԳơ�
//���һ���ǵ�2����ʤ������NΪ����ʱ���ڵ�1���У�
//ֻҪ��2�������õ�Ӳ�������1�������õ�Ӳ������ͬ�������1������Ӳ�ҳ����ĶԳơ�������1�ֺ󣬾ͱ����NΪż�������һ�����ˡ����Ҳ�ǵ�2��ʤ����
//�Բ���һ���Ǹ����ӣ�Ϊʲô�Լ��������԰�������aaaaa
//���⣺һȦӲ�ң���Alice ���ã�Bob���ã�������һö�����ڵ���ö��1,2,3��ö������Ӳ�ң�������ߵڶ�ö����1,3��öӲ�Ҳ����ڡ�
//      ˭������Ӳ��˭Ӯ
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
