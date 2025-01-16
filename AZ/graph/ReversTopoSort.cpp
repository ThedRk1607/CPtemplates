//Educational Codeforces Round 25-E
void solve(){
	int n,m;cin>>n>>m;
	vector<vi>g(n+1);
	vi ind(n+1,0),ans(n+1,-1);
	rep(i,0,m){
		int u,v;cin>>u>>v;
		g[v].pb(u);ind[u]++;
	}
	PQ q;
	rep(i,1,n+1)if(ind[i]==0)q.push(i);
	 int label=n;
	while(!q.empty()){
		auto it=q.top();q.pop();
		ans[it]=label--;
		for(auto ch:g[it]){
			if(ans[ch]!=-1)continue;
			ind[ch]--;
			if(ind[ch]==0)q.push(ch);
		}
	}

	rep(i,1,n+1)cout<<ans[i]<<" ";
}
