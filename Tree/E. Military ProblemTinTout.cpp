const int N=2<<17;
vector<int>adj[N];
vector<int>tin(N),tout(N),top(N);

int timer=0;
bool vis[N];
void dfs(int u){
	top[timer]=u;
	tin[u]=timer++;
	
	for(auto e:adj[u]){
		dfs(e);
		
	}
	tout[u]=timer-1;
	

}



void solve(){
	int n,q;cin>>n>>q;
	FOR(i,1,n){
		int p;cin>>p;
		p--;
		assert(0<=p and p<n);
		adj[p].pb(i);
		
	}

	
	dfs(0);

	while(q--){
		int u,k;cin>>u>>k;u--,k--;
		    // assert(0 <= u and u < n);
            // assert(0 <= k and k < n);

		int ans=-1;

		if(tout[u]>=k+tin[u])ans=top[tin[u]+k]+1;
		cout<<ans<<nl;
		
	}



}
