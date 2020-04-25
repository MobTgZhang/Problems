/*
1.3题目：分金币(UVa 11300)
圆桌旁边坐着$n$个人，每一个人都有一定数量的金币，金币总数量能被$n$整除。每个人可以给他左右相邻的人一些金币，最终使得每一个人的金币数目相等。你的任务是求出
被转手的金币数量的最小值。例如，$n=4$,并且4个人的金币数量为1,2,5,4的时候，只需要转移4枚金币（第3个人给第2个人两个金币，第2个人和第4个人给第1个人1枚金币）即
可以实现每个人手中的金币数量相等。
输入格式：输入包含多组数据。每一组数据的第一行为整数$n,(n \leq 1000000)$，以下$n$行每一行为一个整数，按照逆时针顺序给出每个人拥有的金币数目。输入的结束标志为
文件结束符EOF。
输出格式：对于每组数据，输出被转手金币数量的最小值。输入保证这个值在64位无符号整数范围之内。
样例输入：
3
100
100
100
4
1
2
5
4
输出样例：
0
4
*/
//分析参见书上
# include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;
int main() {
	std::ios::sync_with_stdio(false);
	string line;
	cin >> line;
	stringstream tmp_stream;
	while (line.find("EOF")>line.size()) {
		tmp_stream << line;
		int N;
		tmp_stream >> N;
		vector<long long> CoinsList;
		long long total = 0;
		for (int k = 0; k < N; k++) {
			long long tmp; cin >> tmp;
			total += tmp;
			CoinsList.push_back(tmp);
		}
		
		long long M = total / N;
		vector<long long>C_list;
		C_list.push_back(0);
		for (int k = 1; k < N; k++) {
			C_list.push_back(C_list[k - 1] + CoinsList[k] - M);
		}
		sort(C_list.begin(),C_list.end());
		long long x1 = C_list[N / 2];
		long long ans = 0;
		for (int k = 0; k < N; k++) {
			ans += abs(x1 - C_list[k]);
		}
		cout << ans << endl;
		tmp_stream.clear();
		cin >> line;
	}
	system("pause");
	return 0;
}