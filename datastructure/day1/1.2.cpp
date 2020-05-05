/*
1.2题目：突击战(UVa,11729)
你有n个部下，每个部下需要完成一项任务。第k个部下需要花费$B_{k}$分钟交代任务，然后他会立刻独立地、无间断地执行$J_{k}$分钟之后完成任务。
你需要选择交代任务的顺序，使得所有任务尽早地完成（即最后一个执行完的任务应当尽早结束）。注意，不能同时给两个部下交代任务，但是部下可以同时执行任务。
输入格式：输入包含多组数据，每一组数据的第一行为部下的个数$N(1\leq N\leq 1000)$；以下$N$行每一行两个整数$B$和$J$,$(1\leq B \leq 10000),(1\leq B \leq 10000)$,
即交代任务的时间和执行任务的时间。输入的结束标志为$N=0$。
输出格式：对于每组数据，输出所有任务完成的最短时间。
样例输入：
3
2 5
3 2
2 1
3
3 3
4 4
5 5
0
样例输出：
case 1:8
case 2:15
*/
//执行时间长的任务应当先交代，于是想出这样的一个贪心算法：按照J从小到大的顺序给各个任务排序，然后依次交代。
#include<vector>
#include<algorithm>
#include<iostream>
using std::sort;
using std::vector;
using std::cout;
using std::cin;
using std::cout;
using std::max;
using std::endl;
struct Subordinate {
	int B;
	int J;
	//重载运算符
	bool operator < (const Subordinate& x) const{
		return this->J > x.J;
	}
};
int main() {
	int N;
	int number = 1;
	cin >> N;
	while (N != 0) {
		vector<Subordinate>Jobs;
		for (int k = 0; k < N; k++) {
			Subordinate tmp;
			cin >> tmp.B >> tmp.J;
			Jobs.push_back(tmp);
		}
		sort(Jobs.begin(),Jobs.end());
		
		int s = 0;
		int ans = 0;
		for (int k = 0; k < N; k++) {
			s += Jobs[k].B;
			ans = max(ans,s+Jobs[k].J);
		}
		cout << "case " << number << ":" << ans << endl;
		number += 1;
		cin >> N;
	}
	system("pause");
	return 0;
}