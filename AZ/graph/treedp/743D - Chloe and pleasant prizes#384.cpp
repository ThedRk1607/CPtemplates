int n;int ans;
vector<int>g[N],subt(N),a(N),mxsub(N,-inf);
void dfs(int node,int p=-1){
	 subt[node]=a[node];mxsub[node]=-inf;
	 for(auto ch:g[node]){
	 	if(ch==p)continue;
	 	dfs(ch,node);
	 	subt[node]+=subt[ch];
	 	mxsub[node]=max(mxsub[node],mxsub[ch]);	
	 }
	mxsub[node]=max(mxsub[node],subt[node]);	
 }

 void dfs2(int node,int out,int p=-1){
 	 if(out!=-inf)ans=max(ans,subt[node]+out);
 	 vii mxtwo;
 	 for(auto ch:g[node]){
 	 	if(ch==p)continue;
 	 	mxtwo.pb({mxsub[ch],ch});sort(all(mxtwo),greater<pii>());
 	 	if(mxtwo.size()==3)mxtwo.pop_back();
 	 }
 	 mxtwo.pb({-inf,-1});
 	 for(auto ch:g[node]){
 	 	if(ch==p)continue;
 	 	int cur=(mxtwo[0].S==ch)?mxtwo[1].F:mxtwo[0].F;
 	 	dfs2(ch,max(out,cur),node);
 	}
 }


//in one dfs
// void dfs(int u,int p){
// 	mx[u]=-inf;sum[u]=a[u];
// 	for(int v:g[u]){
// 		if(v==p)continue;
// 		dfs(v,u);
// 		sum[u]+=sum[v];
// 		ans=max(ans,mx[u]+mx[v]);
// 		mx[u]=max(mx[u],mx[v]);
// 	}
// 	mx[u]=max(mx[u],sum[u]);
// }
void solve(){		
 	cin>>n;
 	rep(i,0,n)g[i].clear();
 	rep(i,0,n)cin>>a[i];
 	rep(i,0,n-1){
 		int u,v;cin>>u>>v;u--,v--;
 		g[u].pb(v);g[v].pb(u);
 	}
 ans=-inf;
  dfs(0);
  dfs2(0,-inf);
  if(ans==-inf){cout<<"Impossible\n";return;}
 cout<<ans;
  
	
}


