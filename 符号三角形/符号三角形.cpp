
#include <iostream>
using namespace std;
#define MAX 100

//全局变量
int count=0;
int sum=0;//最终结果
int p[MAX][MAX]={2};//1是-，0是+
int n=0;
int half=0;//half=n*(n+1)/4

void back_triangle(int t);

int main()
{
    cout<<"请输入n: ";
	cin>>n;
	half=n*(n+1)/2;
	if(half%2!=0)
	{
		printf("您输入的数字对于该问题并不成立!,请重新输入：");
		return 1;
	}
	half/=2;
	back_triangle(1);
	cout<<"共有"<<sum<<"种三角形"<<endl;
    return 0;
}

void back_triangle(int t)
{
	if(count>half || t*(t-1)/2-count>half)
		return ;
	if(t>n)
	{
		sum++;
		for(int temp=1;temp<=n;temp++)
		{
			for(int tp=1;tp<=n;tp++)
			{
				cout<<p[temp][tp];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else
	{
		int i;
		for(i=0;i<2;i++)
		{
			p[1][t]=i;
			count+=i;
			int j;
			for(j=2;j<=t;j++)
			{
				p[j][t-j+1]=(p[j-1][t-j+1]^p[j-1][t-j+2]);
				count+=p[j][t-j+1];
			}

			back_triangle(t+1);

			for(j=2;j<=t;j++)
				count-=p[j][t-j+1];
			count-=i;
		}
	}
}

