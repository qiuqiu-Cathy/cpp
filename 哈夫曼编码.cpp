#include <bits/stdc++.h>
using namespace std;

//thanks to tl~
//thanks to syw~

int Node[55];

typedef struct
{
    int bit[100];
    int start;
} CodeType;        //哈夫曼编码结构体

typedef struct
{
    int weight;
    int parent;
    int xl;
    int xr;
    int value;
} NodeType;        // 哈夫曼结点结构体

// 构造一棵哈夫曼树
void HuffmanTree (NodeType HuffNode[110],  int n)
{
    //m1、m2：构造哈夫曼树不同过程中两个最小权值结点的权值，
    //x1、x2：构造哈夫曼树不同过程中两个最小权值结点在数组中的序号。
    int m1, m2, x1, x2;

    //初始化 HuffNode[] 中的结点
    for (int i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;//权值
        HuffNode[i].parent =-1;
        HuffNode[i].xl =-1;
        HuffNode[i].xr =-1;
        HuffNode[i].value=i; //实际值，可根据情况替换为字母
    }

    //输入 n 个叶子结点的权值
    for (int i=0; i<n; i++)
    {
        cin >> HuffNode[i].weight;
        Node[i]=HuffNode[i].weight;
    }

    // 循环构造 Huffman树
    for (int i=0; i<n-1; i++)
    {
        m1=m2=10000;     // m1、m2中存放两个无父结点且结点权值最小的两个结点
        x1=x2=0;
        // 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树
        for (int j=n+i-1; j>=0; j--)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
            {
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1 )
            {
                m2=HuffNode[j].weight;
                x2=j;
            }
        }
        // 设置找到的两个子结点 x1、x2 的父结点信息
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n+i].xl = x2;
		HuffNode[n+i].xr = x1;
    }
}

//解码
void decodeing(char string[],NodeType Buf[],int Num)
{
	int i,tmp=0,code[1024];
	int m=2*Num-1;
	char *nump;
	char num[1024];
	for(i=0;i<strlen(string);i++)
	{
	    if(string[i]=='0')
	  		num[i]=0;
	  	else
	  		num[i]=1;
	}
	i=0;
	nump=&num[0];

	while(nump<(&num[strlen(string)]))
	{
		tmp=m-1;
	 	while((Buf[tmp].xl!=-1)&&(Buf[tmp].xr!=-1))
	  	{

	   		if(*nump==0)
	   		{
	     		tmp=Buf[tmp].xl ;
	   		}
	   		else tmp=Buf[tmp].xr;
	   		nump++;

  		}
  		printf("%d",Buf[tmp].value);
 	}
}


int main(void)
{
    int t;
    scanf("%d",&t);
    for(int cnt=1;cnt<=t;cnt++)
    {
    	if(cnt!=1)
            cout << endl;
	    NodeType HuffNode[110];
	    CodeType HuffCode[55],  cd;
	    int j, c, p, n;
	    char pp[100];
        cin >> n;
	    HuffmanTree (HuffNode, n);


	    for (int i=0; i < n; i++)
	    {
	        cd.start = n-1;
	        c = i;
	        p = HuffNode[c].parent;
	        while (p != -1)   /* 父结点存在 */
	        {
	            if (HuffNode[p].xl == c)
	                cd.bit[cd.start] = 0;
	            else
	                cd.bit[cd.start] = 1;
	            cd.start--;        //求编码的低一位
	            c=p;
	            p=HuffNode[c].parent;    // 设置下一个循环条件
	        }

	        //保存求出的每个叶结点的哈夫曼编码和编码的起始位
	        for (j=cd.start+1; j<n; j++)
	        {
	        	HuffCode[i].bit[j] = cd.bit[j];
	        }
	        HuffCode[i].start = cd.start;
	    }
	    cout << "Case " << cnt << endl;
	    //输出已保存好的所有存在编码的哈夫曼编码
	    for (int i=0; i<n; i++)
	    {
	        cout << Node[i] << " ";
	        for (j=HuffCode[i].start+1; j < n; j++)
	            cout << HuffCode[i].bit[j];
	        cout << endl;
	    }
	}
    return 0;
}
