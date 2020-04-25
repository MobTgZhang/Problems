/*
1.2��Ŀ��ͻ��ս(UVa,11729)
����n�����£�ÿ��������Ҫ���һ�����񡣵�k��������Ҫ����$B_{k}$���ӽ�������Ȼ���������̶����ء��޼�ϵ�ִ��$J_{k}$����֮���������
����Ҫѡ�񽻴������˳��ʹ���������������ɣ������һ��ִ���������Ӧ�������������ע�⣬����ͬʱ���������½������񣬵��ǲ��¿���ͬʱִ������
�����ʽ����������������ݣ�ÿһ�����ݵĵ�һ��Ϊ���µĸ���$N(1\leq N\leq 1000)$������$N$��ÿһ����������$B$��$J$,$(1\leq B \leq 10000),(1\leq B \leq 10000)$,
�����������ʱ���ִ�������ʱ�䡣����Ľ�����־Ϊ$N=0$��
�����ʽ������ÿ�����ݣ��������������ɵ����ʱ�䡣
�������룺
3
2 5
3 2
2 1
3
3 3
4 4
5 5
0
���������
case 1:8
case 2:15
*/
//ִ��ʱ�䳤������Ӧ���Ƚ������������������һ��̰���㷨������J��С�����˳���������������Ȼ�����ν�����
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
	//���������
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