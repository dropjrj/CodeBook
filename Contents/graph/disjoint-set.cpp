#include <bits/stdc++.h>
using namespace std;

#define N 10
int p[N], rank[N]; // rank -> tree height, sz -> group size
void init()
{
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        rank[i] = 1;
    }
}
int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b) // tree height
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    if (rank[a] < rank[b])
        p[a] = b;
    else if (rank[a] > rank[b])
        p[b] = a;
    else
    {
        p[a] = b;
        rank[a]++;
    }
}
// void Union(int a, int b) // group size
// {
//     a = Find(a);
//     b = Find(b);
//     if (a == b)
//         return;
//     if (sz[a] < sz[b])
//         swap(a, b);
//     sz[a] += sz[b];
//     p[b] = a;
// }

int main()
{
	init();
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	return 0;
}
