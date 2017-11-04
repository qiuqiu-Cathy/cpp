#include<bits/stdc++.h>
using namespace std;

//thanks to tl~

struct Node
{
	int type;  //叶子节点
	int lt, rt;
	int val;  //每个节点的权值
	int id;
	string code;
} a[1000];
int cnt = 0;
void init()
{
	a[0].lt = a[0].rt = 0;
	cnt = 0;
}
int NewNode(int val, int type, int id)
{
	cnt ++;
	a[cnt].val = val;
	a[cnt].type = type;
	a[cnt].id = id;
	a[cnt].code = "";
	a[cnt].lt = a[cnt].rt = 0;
	return cnt;
}
struct cmp
{
	bool operator()(const int x, const int y)
	{
		return a[x].val > a[y].val || (a[x].val == a[y].val && a[x].id < a[y].id);
		//保证相同权值w的两个字母x、y，先输入权值的字母x的Huffman编码长度不超过后输入权值的字母y的Huffman编码长度
	}
};
pair<int, string> ans[1000];
void dfs(int pos, string code)
{
	a[pos].code = code;
	if (a[pos].lt)
		dfs(a[pos].lt, code + "0");  //dfs哈夫曼树，向左遍历标1
	if (a[pos].rt)
		dfs(a[pos].rt, code + "1");  //向右遍历标0
}
int main()
{
	int T;
	cin >> T;
	int casenum = 0;
	while (T--)
	{
		cout << "Case " << ++ casenum << endl;
		init();
		int n;
		cin >> n;
		priority_queue<int, vector<int> , cmp>q;  //利用一个优先队列来维护各个节点，
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			q.push(NewNode(val, 1, i));
		}
		int time = n;
		while (q.size() != 1)
		{
			int temp_id1 = q.top();  //最小的节点信息弹出
			Node temp1 = a[temp_id1];
			q.pop();
			int temp_id2 = q.top(); //第二小的节点信息弹出
			Node temp2 = a[temp_id2];
			q.pop();
			int x = NewNode(temp1.val + temp2.val , 0, time++);
			a[x].lt = temp_id2;
			a[x].rt = temp_id1;
			q.push(x);
		}
		dfs(q.top(), "");
		for (int i = 1; i <= cnt; i++)
			if (a[i].type == 1)
				ans[a[i].id] = make_pair(a[i].val, a[i].code);
		for (int i = 0; i < n; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
		cout << endl;
	}
}
