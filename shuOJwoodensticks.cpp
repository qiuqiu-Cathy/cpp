/* 描述

   There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows: 

   (a) The setup time for the first wooden stick is 1 minute. 

    (b) Right after processing a stick of length l and weight w , the machine will need no setup time for a stick of length l' and weight w' if l <= l' and w <= w'. Otherwise, it will need 1 minute for setup. 

	You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are ( 9 , 4 ) , ( 2 , 5 ) , ( 1 , 2 ) , ( 5 , 3 ) , and ( 4 , 1 ) , then the minimum setup time should be 2 minutes since there is a sequence of pairs ( 4 , 1 ) , ( 5 , 3 ) , ( 9 , 4 ) , ( 1 , 2 ) , ( 2 , 5 ) .
	输入

	The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n , 1 <= n <= 5000 , that represents the number of wooden sticks in the test case, and the second line contains 2n positive integers l1 , w1 , l2 , w2 ,..., ln , wn , each of magnitude at most 10000 , where li and wi are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.
	输出

	The output should contain the minimum setup time in minutes, one per line.
	样例输入1

	3 
	5 
	4 9 5 2 2 1 3 5 1 4 
	3 
	2 2 1 1 2 2 
	3 
	1 3 2 2 3 1 

	样例输出1

	2
	1
	3
 */
#include <bits/stdc++.h>
using namespace std;
// thanks to tl~
int l[5005];
int w[5005];
int main()
{
	int T,n,i,sett,llarge,wlarge;
	cin >> T;
	while(T--)
	{
		sett=1;
		memset(l,0,sizeof(l));
		memset(w,0,sizeof(w));
		cin >> n ;
		for(i=0;i<n;i++)
		{
			cin >> l[i] >> w[i];
		}
		llarge=l[0];
		wlarge=w[0];
		for(i=1;i<n;i++)
		{
			if(llarge<l[i])
			{
				llarge=l[i];
				sett++;
				if(wlarge<w[i])
					wlarge=w[i];
			}
			else if(wlarge<w[i])
			{
				wlarge=w[i];
				sett++;
			}
		}
		cout << sett << endl;
	}
	return 0;
}
