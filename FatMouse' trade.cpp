//2017 shu 7.24 贪心 
/*
FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean. 
The warehouse has N rooms. The i-th room contains Jii pounds of JavaBeans and requires Fii pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get Jii* a% pounds of JavaBeans if he pays Fii* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain. 
Input
The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers Jii and Fii respectively. The last test case is followed by two -1's. All integers are not greater than 1000. 
Output
For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain. 
Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
Sample Output
13.333
31.500
*/
#include <iostream>
#include <cstdio>
#include<algorithm>
//#include <iomanip> //作用主要是控制输入输出格式
using namespace std;
//thanks to tl~
struct room
{
    int j,f;   //j javabeans==f cat food 
    double price;//单位猫粮可换取的javabeans
}r[1005];
bool cmp(room x,room y)
{
     //if(x.price!=y.price)
         return x.price>y.price;
    // else
         //return x.j<y.j;//??还没想明白 
} 
int main()
{
    int m,n;//拥有m猫粮，n个房间
    double cf;//最多换取的javabeans 
    while(cin>> m >> n)
    {
         if(m==-1&&n==-1)
               break;
         else
         {
             cf=0; 
             for(int i=0;i<n;i++)
             {
                     cin >> r[i].j >>r[i].f; 
                     r[i].price=(r[i].j*1.0)/(r[i].f*1.0);
                     //cout << r[i].price <<endl; 
             }
             sort(r,r+n,cmp) ;
             for(int i=0;i<n;i++)  
             {  
                     if(m>=r[i].f)  
                     {  
                         m-=r[i].f;  
                         cf+=r[i].j;  
                     }  
                     else  
                     {  
                         cf+=r[i].price*m;
                         break;  
                     }  
              }  
              printf("%.3lf\n",cf);  
         }               
    } 
    return 0;
}
             /*while(m!=0)
             {
                     int j=0;
                     double max=p[0];
                     for(int i=1;i<n;i++)
                     {
                             if(p[i]>max)
                             {     
                                   max=p[i];
                                   j=i;
                             }
                     }
                     if(m<F[j])
                     {
                               cf=cf+m*p[j];
                               m=0;
                               //cout << j << " " << cf << " " << m <<endl;
                     }
                     else if(m>=F[j])
                     {
                               m=m-F[j];
                               p[j]=0;
                               cf=cf+J[j];
                               //cout <<j << " "<< cf << " " << m <<endl;
                     }  
                 
             }
            //cout << cf <<endl;
            printf("%.3f\n",cf); 
            //cout <<setprecision(3) <<std::fixed<<cf <<endl;
         */
           
