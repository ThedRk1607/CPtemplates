//find set of cliques in graph for every component check cnte==cntv*(cntv-1)/2;
const int N=150125;
int n,m;
vector<int>adj[N];
bool vis[N];
int cnte,cntv;
void dfs(int u)
{	assert(!vis[u]);
	vis[u]=true;
	++cntv;
	cnte+=adj[u].size();
	for(auto v:adj[u]){
		
		if(vis[v])continue;

		 
		  dfs(v);

	}
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);

	}

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnte=0,cntv=0;
			dfs(i);
			
			ll x=cntv*(cntv-1);
			if(x!=cnte){
				cout<<"NO\n";
				return;
			}
		}
	}
cout<<"YES\n";

}
