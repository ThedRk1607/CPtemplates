//every vertx should have degree of 2 for cycle;
int n,m;
vector<int>adj[200005];
bool vis[200005];
int bad=0;
int deg[200005];
void dfs(int u,int p){
	vis[u]=true;
	if(deg[u]!=2)bad=1;
	for(auto v:adj[u]){
		
		if(vis[v])continue;
		dfs(v,p);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	int res=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bad=0;
			dfs(i,i);
			if(bad==0)res++;

		}
	}
	
cout<<res<<nl;

}
