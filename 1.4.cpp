/*
1.4��Ŀ��Ĺ�ص���(NEERC 2006,LA 3708)
��һ���ܳ�Ϊ10000��Բ�ϵȾ�ֲ���$n$�����ܡ���������$m$�µĵ��ܼ���(λ�ÿ����������)��ϣ������$n+m$��������Բ���Ͼ��ȷֲ�����������Ҫ�ƶ�����һЩԭ�е�
���ܡ�Ҫ��$n$�������ƶ����ܾ�����С��
�����ʽ������������������ݣ�ÿ�����ݽ�һ�У�������������$n$��$m$��$2\leq n \leq 1000,1\leq m \leq 1000$��,��ԭʼ�ĵ��������������ӵĵ�������������Ľ���
��־Ϊ�ļ�������EOF��
�����ʽ�������һ�У�Ϊ��С�ܾ��룬��ȷ��$10^{-4}$��
�������룺
2 1
2 3
3 1
10 10
���������
1666.6667
1000.0
1666.6667
0.0
*/
#include<cstdio>
#include<cmath>
int main() {
	int n, m;
	while (scanf_s("%d%d",&n,&m)==2) {
		double ans = 0.0;
		for (int k = 1; k < n; k++) {
			double pos = (double)k / n * (n + m);
			ans += fabs(pos-floor(pos+0.5))/(n+m);
		}
		printf("%.4f\n",ans*10000);
	}
	return 0;
}