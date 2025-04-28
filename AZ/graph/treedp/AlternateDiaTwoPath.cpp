int n;
vector<vi>T;
vi subt;int deep;
int dfs(int node,int dep,int p){
	int sum=0,mx1=0,mx2=0;
	for(auto ch:T[node]){
		if(ch==p)continue;
		int x=dfs(ch,dep+1,node);
		sum=max(sum,x);
		if(deep>mx1)mx2=mx1,mx1=deep;
		else if(deep>mx2)mx2=deep;
	}
	sum=max(sum,mx1+mx2);deep=mx1+1;
	return sum;
}

void solve(){
	cin>>n;
	T.clear();T.resize(n+1);
	subt.clear();subt.assign(n+1,0);
	rep(i,0,n-1){
		int u,v;cin>>u>>v;u--,v--;
		T[u].pb(v);T[v].pb(u);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(auto ch:T[i])ans=max(ans,dfs(i,0,ch)*dfs(ch,0,i));
	}
	cout<<ans;

}
	
