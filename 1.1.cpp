/*
题目：勇者斗恶龙 UVa 11292
你的王国里面有一条n个头的恶龙，你希望雇佣一些骑士把它杀死（砍掉所有的头）。村里有m个骑士可以雇佣，一个能力为x的骑士可以砍掉一个直径不超过x的头，
并且需要支付x个金币。如何雇佣骑士才能砍掉所有恶龙的头，并且支付的金币最少？注意：一个骑士智能砍死一个恶龙。
输入格式：输入包含多组数据，每组数据的第一行为正整数n和m（1<=n,m<=20000）；以下n行每行为一个整数，即恶龙的每个头的直径；以下m行每行为一个整数，
即每个骑士的能力。输入的结束标志为n=m=0.
输出格式：对于每组数据，输出最少花费。如果无解，则输出"Loowater is dooomed!"。
样例输入：
2 3 
5
4
7
8
4
2 1
5
5
10
0 0
样例输出：
11
Loowater is dooomed!
*/
//骑士的能力、恶龙头的直径按照从小到大的顺序排序，一个砍一个就可以了。但是不能砍掉当前需要砍掉的头的骑士则不要雇佣了。
#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
int main() {
	int n, m;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		//输入数据
		vector<int>Dragon;
		vector<int>Knight;
		for (int k = 0; k < n; k++) {
			int tmp;
			cin >> tmp;
			Dragon.push_back(tmp);
		}
		for (int k = 0; k < m; k++) {
			int tmp;
			cin >> tmp;
			Knight.push_back(tmp);
		}
		//进行大小排序
		sort(Dragon.begin(), Dragon.end());
		sort(Knight.begin(), Knight.end());
		unsigned int cur = 0;
		int cost = 0;
		for (unsigned int k = 0; k < m; k++) {
			if (Knight[k] >= Dragon[cur]) {
				cost += Knight[k];
				if (++cur == n) break;
			}
		}
		if (cur < n) cout << "Loowater is dooomed!" << endl;
		else cout << cost << endl;
		cin >> n >> m;
	}
	system("pause");
	return 0;
}