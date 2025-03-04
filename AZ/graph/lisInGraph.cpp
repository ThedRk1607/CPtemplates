#define N 100010
int n,m,u,v,w,f[N*3];
vector<pair<int,int>> t,e[N];

void solve(){
cin>>n>>m;
	while(m--)cin>>u>>v>>w,e[w].pb({u,v});//take according to weight like sort with weight;
	for(int i=1;i<=N;i++){
		t.clear();
		for(auto ed:e[i])t.pb({ed.S,f[ed.F]+1});//take every u from which we came to v;
		for(auto ed:t)f[ed.F]=max(f[ed.F],ed.S);//dp[v]=max(dp[v],dp[u]+1);
	}
	cout<<*max_element(f+1,f+n+1);

}
