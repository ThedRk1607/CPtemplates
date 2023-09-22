const int N=2<<17;
vector<int>adj[N];
bool vis[N];
int n,m;
vector<int>color(N,-1);
bool bipart;


void dfs(int u,int c=0){
	color[u]=c;
	for(auto e:adj[u]){
		if(color[e]==-1)dfs(e,!c);
		else {
			if(color[e]==c)bipart=false;
		}
	}
}

void solve(){
	cin>>n>>m;
	
	vector<pii>e;
	
	FOR(i,0,m){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		e.pb({u,v});
	}


	bipart=true;
	dfs(1);
	if(!bipart){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i=0;i<m;i++){
		cout<<(color[e[i].F]<color[e[i].S]);
	}


	


    }
