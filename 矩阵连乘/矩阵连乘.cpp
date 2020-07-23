
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

//int min(int, int);
/*
回溯最优解
	s[i][i] 存储 从 i 到 j 的 最优切分位置
*/
string result(vector<vector<int>> &s, int k1, int k2);

int main()
{
	int num;
	cout << "请输入矩阵的个数：" << endl;
	cin >> num;

	vector<vector<int>> matrix(num, vector<int>(2, 0));			//num行两列的二维向量，用于存储各个矩阵的行列数
	cout << "请输入各个矩阵的行列数：" << endl;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> m(num, vector<int>(num, INT_MAX));	//m[i][j]记录问题的最优解, 各个元素初始化为INT_MAX!!!
	vector<vector<int>> s(num, vector<int>(num, -1));		//s[i][j]回溯问题的最优解 → 记录切分位置k

	//当 i = j 时, m[i][j] = 0
	for (int i = 0; i < num; ++i)
	{
		m[i][i] = 0;
	}

	//自底向上，对角线方向进行
	for (int i = 1; i < num; ++i)		//控制沿对角线遍历的次数	√
	{
		for (int j = 0; j < num - i; ++j)	//控制每条对角线上元素的个数	√
		{
			int temp = i + j;
			for (int k = j; k < temp; ++k)
			{
				//m[j][temp] = min(m[j][k] + m[k + 1][temp] + (matrix[j][0] * matrix[k][1] * matrix[temp][1]), m[j][temp]);
				if (m[j][k] + m[k + 1][temp] + (matrix[j][0] * matrix[k][1] * matrix[temp][1]) < m[j][temp])
				{
					m[j][temp] = m[j][k] + m[k + 1][temp] + (matrix[j][0] * matrix[k][1] * matrix[temp][1]);
					s[j][temp] = k;
				}
			}
		}
	}

	//输出最优解
	cout << "最小乘法次数：" << endl;
  	cout << m[0][num-1] << endl;

	//回溯最优解
	cout << "分割方法：" << endl;
	/*for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cout << i << ' ' << j << ' ' << s[i][j] << endl;
		}
	}
	cout << endl;
	cout << endl;*/
	cout << result(s, 0, num - 1) << endl;
	cout << endl;

	return 0;
}

//回溯最优解
string result(vector<vector<int>> &s, int k1, int k2)
{
	if (k1 == k2)
	{
		return string(1, 'A' + k1);
	}

	int split = s[k1][k2];

	return " ( " + result(s, k1, split) + " * " + result(s, split + 1, k2) + " ) ";
}

//int min(int x, int y)
//{
//	return x < y ? x : y;
//}
