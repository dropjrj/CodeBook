#include <bits/stdc++.h>
using namespace std;

#define N 10+5

int main()
{
	int G[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
			G[j][i] = G[i][j];
		}
	}
	for (k = 0; k < n; k++)
	    for (i = 0; i < n; i++)
    	    for (j = 0; j < n; j++)
        	    w[i][j] = w[j][i] = min(w[i][j], w[i][k] + w[k][j]);
	return 0;
}
