/*****************
姓名：郭旭
时间：2019/4/23
项目名称：快速排序
*****************/
#include<iostream>
using namespace std;
int k;
void print(int a[], int n) {
	for (int j = 0; j<n; j++) {
		cout << a[j] << "  ";
	}
	cout << endl;
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void partition(int a[], int low, int high)
{
	int i = low, j = high;
	int privotKey = a[low];                             //基准元素
	while (low < high) {                                   //从表的两端交替地向中间扫描
		while (low < high  && a[high] >= privotKey) high--;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
		swap(&a[low], &a[high]);
		while (low < high  && a[low] <= privotKey) low++;
		swap(&a[low], &a[high]);
	}
    print(a, k);
	if (i < j)
	{
		partition(a, i, low - 1);          //递归排序
		partition(a, low + 1, j);
	}
}
int main()
{
	int a, b;
	double totaltime;
	cout << "输入初始序列的个数：";
	cin >> k;
	int*array = new int[k];
    cout << "请依次输入这" <<k << "位数，以空格隔开" << endl;
    for(int i = 0; i < k; i++){
        cin >> array[i];
    }
    cout << "初始数列:" << endl;
    print(array, k);
	cout << "排序步骤：" << endl;
	partition(array, 0, k - 1);
	cout << "排序后数列:" << endl;
    print(array, k);
	delete[] array;
	return 0;
}
//时间复杂度：（O(nlog2n)）；

