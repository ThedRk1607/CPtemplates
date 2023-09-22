const int N=2<<17;
vector<int>adj[N];
bool vis[N];
int m,n;
vi c;

int ans=0;
void dfs(int u,int p,int k){
	if(k>m)return;
	int cnt=1;
	for(auto v:adj[u]){
		if(v==p)continue;
			cnt=0;
		
		dfs(v,u,k*c[v-1]+c[v-1]);
		
		
	}
	ans+=cnt;
}

void solve(){
	cin>>n>>m;

	FOR(i,0,n){
		int a;cin>>a;
		c.pb(a);
	}

	FOR(i,0,n-1){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1,-1,c[0]);
	cout<<ans<<nl;

    }

