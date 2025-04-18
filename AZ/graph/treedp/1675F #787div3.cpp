int n,k;int ans;
vector<int>g[N],subt(N),a,H,path;
void dfs(int node,int p=-1){
	
	 for(auto ch:g[node]){
	 	if(ch==p)continue;
	 	dfs(ch,node);
	 	if(H[ch])H[node]=1;
	 	if(path[ch])path[node]=1;
	 }
	
 }

 

void solve(){		
 	int x,y;cin>>n>>k>>x>>y;x--,y--;
 	rep(i,0,n)g[i].clear();
 	H.clear();path.clear();a.clear();
 	H.resize(n+1);path.resize(n+1);a.resize(n+1);
 	path[y]=1;
 	rep(i,0,k)cin>>a[i],a[i]--,H[a[i]]=1;
 	rep(i,0,n-1){
 		int u,v;cin>>u>>v;u--,v--;
 		g[u].pb(v);g[v].pb(u);
 	}
 dfs(x);
  int ans=0;
  rep(i,0,n){
  	if(i==x)continue;
  	if(path[i])ans++;
  	else if(H[i])ans+=2;
  }
  
  
 cout<<ans<<nl;
  
