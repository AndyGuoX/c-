#include <iostream>
using namespace std;

int KnapSack(int n,int w[],int v[]);

int *w, *v, n, C;

int main()
{
    int i;
    cout << "请输入背包容量：";
    cin >> C;
    cout<<"请输入物品个数：";
    cin >> n;
    w = new int [n];
    cout<<"请输入物品重量：";
    for(i = 0; i < n; i++)
        cin>>w[i];

    v = new int [n];
    cout<<"请输入物品价值：";
    for(i = 0; i < n; i++)
        cin>>v[i];

    cout<<"最优价值："<<KnapSack(n,w,v)<<endl;
    return 0;
}


int KnapSack(int n,int w[],int v[])
{
    int i,j;

    int **V = new int*[C+1];
    for (i = 0; i < C+1; i++)
        V[i] = new int[n+1];

    int *x = new int[n];
    for (i = 0; i <= n; i++)
        V[i][0] = 0;
    for (j = 0; j <= C; j++)
        V[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= C; j++)
            if(j < w[i-1])
                V[i][j] = V[i-1][j];
            else
                V[i][j] = V[i-1][j] >= (V[i-1][j-w[i-1]]+v[i-1]) ? V[i-1][j]: (V[i-1][j-w[i-1]]+v[i-1]);

    j = C;
    for (i = n; i > 0; i--)
    {
        if (V[i][j] > V[i-1][j])
        {
            x[i-1] = 1;
            j = j - w[i-1];
        }
        else
            x[i-1] = 0;
    }
    return V[n][C];
}
