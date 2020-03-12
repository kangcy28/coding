#include <iostream>
#include <string.h>

using namespace std;

const int N = 105;

int n, m, a[105], b[105];
int g[105][105], match[105];

bool vis[105];
bool dfs(int u) {
    for(int v = 1; v <= m; ++v) {
        if(!g[u][v] || vis[v]) continue;
        vis[v] = true;
        if(!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
//#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i] && b[j] % a[i] == 0) g[i][j] = 1;
                else if(!b[j]) g[i][j] = 1;

        memset(match, 0, sizeof match);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            ans += dfs(i);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}