
const int N=2e5+5;
int dp[N],id[N];
vector<pii>adj[N];

void dfs(int u){
	for(auto v:adj[u]){
		if(dp[v.F]==0){
			dp[v.F]=dp[u]+(v.S<=id[u]);
			id[v.F]=v.S;
			dfs(v.F);
		}
	}
}

void solve(){
	int n;cin>>n;
	  for(int i=1; i<=n; i++) dp[i] = id[i] = 0, adj[i].clear();

	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].pb({v,i});
		adj[v].pb({u,i});
	}

	dp[1]=1;
	
	dfs(1);
	ll ans=0;
	FOR(i,1,n+1)amax(ans,dp[i]);
	cout<<ans<<nl;
	
}
