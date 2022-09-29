#include <bits/stdc++.h>
using namespace std;

#define N 10
int p[N], sz[N];
struct Edge
{
    int s, t, w;
    Edge(int s, int t, int w) : s(s), t(t), w(w) {}
    bool operator < (const Edge &rhs) const { return w < rhs.w; }
};
void init()
{
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
}
int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b) // group size
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}
int kruskal()
{
    int cost = 0;
    vector<Edge> E;
    init();
    for (int i = 0; i < N; i++)
    {
        int s, t, w;
        cin >> s >> t >> w;
        E.push_back(Edge(s,t,w));
    }
    sort(E.begin(), E.end());
    for (auto it : E)
    {
        it.s = Find(it.s);
        it.t = Find(it.t);
        if (it.s == it.t)
            continue;
        cost += it.w;
        Union(it.s, it.t);
    }
    return cost;
}

int main()
{
    init();
    int cost = kruskal();
    cout << cost << endl;
    return 0;
}

