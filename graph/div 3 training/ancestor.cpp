const int N=2<<17;
int n,m;
vector<int>adj[N];
bool vis[N];
int tin[N],tout[N];
int timer;

void dfs(int node,int p=-1){
	
	tin[node]=timer++;
	for(auto v:adj[node]){
		if(v==p)continue;
		dfs(v,node);
	}

	tout[node]=timer++;

}

void solve(){
	cin>>n;
	int p=1;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==0){
			p=i;
			continue;
		}
		adj[x].pb(i);
		
	}
	
   timer=0;
	dfs(p);

	cin>>m;
	while(m--){
		int x,y;cin>>x>>y;
		if(tout[x]>=tout[y] and tin[x]<=tin[y])cout<<1<<nl;
		else cout<<0<<nl;


	}
}

