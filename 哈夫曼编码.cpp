#include <bits/stdc++.h>
using namespace std;

//thanks to tl~
//thanks to syw~

int Node[55];

typedef struct
{
    int bit[100];
    int start;
} CodeType;        //����������ṹ��

typedef struct
{
    int weight;
    int parent;
    int xl;
    int xr;
    int value;
} NodeType;        // ���������ṹ��

// ����һ�ù�������
void HuffmanTree (NodeType HuffNode[110],  int n)
{
    //m1��m2���������������ͬ������������СȨֵ����Ȩֵ��
    //x1��x2���������������ͬ������������СȨֵ����������е���š�
    int m1, m2, x1, x2;

    //��ʼ�� HuffNode[] �еĽ��
    for (int i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;//Ȩֵ
        HuffNode[i].parent =-1;
        HuffNode[i].xl =-1;
        HuffNode[i].xr =-1;
        HuffNode[i].value=i; //ʵ��ֵ���ɸ�������滻Ϊ��ĸ
    }

    //���� n ��Ҷ�ӽ���Ȩֵ
    for (int i=0; i<n; i++)
    {
        cin >> HuffNode[i].weight;
        Node[i]=HuffNode[i].weight;
    }

    // ѭ������ Huffman��
    for (int i=0; i<n-1; i++)
    {
        m1=m2=10000;     // m1��m2�д�������޸�����ҽ��Ȩֵ��С���������
        x1=x2=0;
        // �ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ�����
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
        // �����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n+i].xl = x2;
		HuffNode[n+i].xr = x1;
    }
}

//����
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
	        while (p != -1)   /* �������� */
	        {
	            if (HuffNode[p].xl == c)
	                cd.bit[cd.start] = 0;
	            else
	                cd.bit[cd.start] = 1;
	            cd.start--;        //�����ĵ�һλ
	            c=p;
	            p=HuffNode[c].parent;    // ������һ��ѭ������
	        }

	        //���������ÿ��Ҷ���Ĺ���������ͱ������ʼλ
	        for (j=cd.start+1; j<n; j++)
	        {
	        	HuffCode[i].bit[j] = cd.bit[j];
	        }
	        HuffCode[i].start = cd.start;
	    }
	    cout << "Case " << cnt << endl;
	    //����ѱ���õ����д��ڱ���Ĺ���������
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
