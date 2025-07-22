int n,m,ans,t;
int tin[N],low[N],sz[N],vis[N];
vector<int>g[N];

int fi(int x){return x*(x-1)/2;}

void dfs(int node,int p){
	tin[node]=low[node]=++t;sz[node]=1;vis[node]=1;
	for(auto ch:g[node]){
		if(ch==p)continue;
		if(!vis[ch])dfs(ch,node),sz[node]+=sz[ch];
		low[node]=min(low[node],low[ch]);
	}
	//bridge; (p->node);
	if(tin[node]==low[node])ans=min(ans,fi(n-sz[node])+fi(sz[node]));

}

void solve(){
	cin>>n>>m;t=0;
	rep(i,0,n+2)g[i].clear(),tin[i]=low[i]=0,sz[i]=0,vis[i]=0;
	while(m--){int x,y;cin>>x>>y;g[x].pb(y);g[y].pb(x);}
	ans=fi(n);
	dfs(1,0);
	cout<<ans<<nl;
}
	
