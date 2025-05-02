#include <bits/stdc++.h>
using namespace std;

//#define int long long

int dp[20][(1<<20)];
bool isEdge[20][20];
int n, m;
int cur;

int dfs(int pos, int vis, int sz) {
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = 0;
    if(sz > 2 && isEdge[pos][cur]) {
        ans++;
    }
    for (int i = cur; i < n; ++i) {
        if((vis & (1<<i))) continue;
        if(isEdge[pos][i]) {
            ans += dfs(i, (vis | (1<<i)), sz+1);
        }
    }
    return dp[pos][vis]=ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        isEdge[a][b] = isEdge[b][a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cur = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1<<i), 1);
    }
    cout << ans/2;
    return 0;
}
