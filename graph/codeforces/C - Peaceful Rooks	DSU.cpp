
int ans;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression) or par/root of x;
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) {
			ans++;
			return false;
		}
		
		//place for edit someting if needed;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

void solve(){
	int n,m;cin>>n>>m;
	ans=0;
	DSU dsu(n+1);
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		if(x==y)continue;
		dsu.unite(x,y);
		ans++;
	}
	cout<<ans<<nl;

	


}
