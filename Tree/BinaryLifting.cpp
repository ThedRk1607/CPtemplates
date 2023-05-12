int depth[200005];
int up[200005][20];
vi adj[200005];
int timer;
vi tin,tout;

struct BinaryLift{


void dfs(int v, int p=-1)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= 21; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int jump(int x, int d) {
	FOR(i,0,20) {
		if ((d >> i) & 1) x = up[x][i];
	}
	return x;
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	a = jump(a, depth[a] - depth[b]);
	if (a == b) return a;

	ROF(i,0, 20) {
		int aT = up[a][i], bT = up[b][i];
		if (aT != bT) a = aT, b = bT;
	}

	return up[a][0];
}
	
};
