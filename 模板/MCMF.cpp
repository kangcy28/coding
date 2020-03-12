#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 210;
const int maxm = 220;

struct Edge {
    int from, to, cap, flow, cost;
    Edge () {} //作为Edge类数组的默认构造函数
    Edge (int u, int v, int ca, int fl, int co):from(u), to(v), cap(ca), flow(fl), cost(co)
    {}
};

struct MCFC {
    int n, m, s, t;
    Edge edges[maxm];
    int first[maxn];
    int next[maxm];
    int inq[maxn];
    int d[maxm];
    int p[maxn];
    int a[maxn];
    int Q[maxn];

    MCFC() {}

    void init(int n) {
        this->n = n;
        memset(first, -1, sizeof(first));
        m = 0;
    }

    void addEdge(int u, int v, int cap, int cost) {
        edges[m] = Edge(u, v, cap, 0, cost);
        next[m] = first[u];
        first[u] = m++;
        edges[m] = Edge(v, u, 0, 0, -cost);
        next[m] = first[v];
        first[v] = m++;
    }

    bool bellmanFord(int s, int t, int &flow, long long &cost) {

        for (int i = 0; i < n; i++) d[i] = INF;
        memset(inq, false, sizeof(inq));
        d[s] = 0; inq[s] = true; p[s] = 0; a[s] = INF;
        int front, rear;
        Q[rear = front = 0] = s;
        while (front <= rear) {
            int u = Q[front++];
            inq[u] = false;
            for (int i = first[u]; i != -1; i = next[i]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = i;
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {Q[++rear] = e.to; inq[e.to] = true;}
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += (long long)d[t] * (long long)a[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int mincostMaxflow(int s, int t, long long& cost) {
        int flow = 0; cost = 0;
        while (bellmanFord(s, t, flow, cost));
        return flow;
    }
}g;

int main(void) {
    int nn, mm, s, t, u, v, cap, cost, totFlow = 0;
    long long totCost = 0;
    while(~scanf("%d%d", &nn, &mm)) {
        s = 1;
        t= nn;
        g.init(t+1);
        for (int i = 0; i < mm; i++) {
            scanf("%d%d%d%d", &u, &v, &cap, &cost);
            g.addEdge(u, v, cap, cost);
        }
        totFlow = g.mincostMaxflow(1, t, totCost);
        printf("最小花费:%lld 最大流:%d\n", totCost, totFlow);
    }
    return 0;
}