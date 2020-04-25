/*
��Ŀ�����߶����� UVa 11292
�������������һ��n��ͷ�Ķ�������ϣ����ӶһЩ��ʿ����ɱ�����������е�ͷ����������m����ʿ���Թ�Ӷ��һ������Ϊx����ʿ���Կ���һ��ֱ��������x��ͷ��
������Ҫ֧��x����ҡ���ι�Ӷ��ʿ���ܿ������ж�����ͷ������֧���Ľ�����٣�ע�⣺һ����ʿ���ܿ���һ��������
�����ʽ����������������ݣ�ÿ�����ݵĵ�һ��Ϊ������n��m��1<=n,m<=20000��������n��ÿ��Ϊһ����������������ÿ��ͷ��ֱ��������m��ÿ��Ϊһ��������
��ÿ����ʿ������������Ľ�����־Ϊn=m=0.
�����ʽ������ÿ�����ݣ�������ٻ��ѡ�����޽⣬�����"Loowater is dooomed!"��
�������룺
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
���������
11
Loowater is dooomed!
*/
//��ʿ������������ͷ��ֱ�����մ�С�����˳������һ����һ���Ϳ����ˡ����ǲ��ܿ�����ǰ��Ҫ������ͷ����ʿ��Ҫ��Ӷ�ˡ�
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
		//��������
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
		//���д�С����
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