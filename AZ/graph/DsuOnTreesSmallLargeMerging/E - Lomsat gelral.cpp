int n;
int c[N],ans[N],mx[N];
vector<int>g[N];
map<int,int>C[N];

void dfs(int u,int p){
	ans[u]=c[u];
	mx[u]=1;
	C[u][c[u]]=1;
	for(auto ch:g[u]){
		if(ch==p)continue;
		dfs(ch,u);
		if(C[ch].size()>C[u].size()){
			swap(C[ch],C[u]);
			ans[u]=ans[ch];
			mx[u]=mx[ch];
		}
		for(auto a:C[ch]){
			C[u][a.F]+=a.S;
			if(C[u][a.F]>mx[u])mx[u]=C[u][a.F],ans[u]=a.F;
			else if(C[u][a.F]==mx[u])ans[u]+=a.F;

		}
		
	}
 
	
}

void solve(){
	cin>>n;
	rep(i,1,n+1){
		cin>>c[i];
	}
	rep(i,0,n-1){
		int a,b;cin>>a>>b;
		g[a].pb(b);g[b].pb(a);
	}
	dfs(1,0);
	rep(i,1,n+1)cout<<ans[i]<<" ";

}
