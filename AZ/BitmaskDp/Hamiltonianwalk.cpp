void solve(){
	int n,m;cin>>n>>m;
	vector<int>g[n+1];
	rep(i,0,n)g[i].clear();
	rep(i,0,m){
		int x,y;cin>>x>>y;x--,y--;
		g[x].pb(y);
	}
	vector<vi>dp(1LL<<n,vi(n+1,0));
	dp[1][0]=1;
	for(int mask=0;mask<(1LL<<n);mask++){
		for(int node=0;node<n;node++){
			for(auto ch:g[node]){
				if(mask>>ch&1LL or !dp[mask][node])continue;
				dp[mask|(1LL<<ch)][ch]=add(dp[mask|(1LL<<ch)][ch],dp[mask][node]);
			}
			
		}
	}
	cout<<dp[(1<<n)-1][n-1];

}
	
