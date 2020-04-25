/*
1.3��Ŀ���ֽ��(UVa 11300)
Բ���Ա�����$n$���ˣ�ÿһ���˶���һ�������Ľ�ң�����������ܱ�$n$������ÿ���˿��Ը����������ڵ���һЩ��ң�����ʹ��ÿһ���˵Ľ����Ŀ��ȡ�������������
��ת�ֵĽ����������Сֵ�����磬$n=4$,����4���˵Ľ������Ϊ1,2,5,4��ʱ��ֻ��Ҫת��4ö��ң���3���˸���2����������ң���2���˺͵�4���˸���1����1ö��ң���
����ʵ��ÿ�������еĽ��������ȡ�
�����ʽ����������������ݡ�ÿһ�����ݵĵ�һ��Ϊ����$n,(n \leq 1000000)$������$n$��ÿһ��Ϊһ��������������ʱ��˳�����ÿ����ӵ�еĽ����Ŀ������Ľ�����־Ϊ
�ļ�������EOF��
�����ʽ������ÿ�����ݣ������ת�ֽ����������Сֵ�����뱣֤���ֵ��64λ�޷���������Χ֮�ڡ�
�������룺
3
100
100
100
4
1
2
5
4
���������
0
4
*/
//�����μ�����
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