int n;int ans;
vector<int>g[N],subt(N);
void dfs(int node,int p=-1){
	vi a;subt[node]=1;bitset<N>st;st[0]=1;
	for(auto ch:g[node]){if(ch==p)continue;
		dfs(ch,node);
		a.pb(subt[ch]);st|=st<<subt[ch];//take size of all child of node;
		subt[node]+=subt[ch];
	}
	int res=0;
	// for(auto x:a){
	// 	res=max(res,(subt[node]-1-x)*x);
	// }
	for(int i=0;i<N;i++)
		if(st[i])amax(res,(subt[node]-i-1)*i);
	ans+=res;
}

void solve(){		
cin>>n;
//rep(i,0,n)g[i].clear();
rep(i,1,n){
	int p;cin>>p;g[p-1].pb(i);
}
dfs(0);
cout<<ans;
	
	
}
