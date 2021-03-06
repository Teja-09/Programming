#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int n, int val[], int wt[])
{
	int i, w;
	int k[n+1][W+1];
	
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
			{
				k[i][w] = 0;
			}
			else if(wt[i-1] <= W)
			{
				k[i][w] = max(k[i-1][w], k[i-1][w-wt[i-1]] + val[i-1]);
			}
			else
			{
				k[i][w] = k[i-1][w];
			}
		}
	}
	return k[n][W];
}

int main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	int ans = knapsack(W, n, val, wt);
	cout << ans;
}
