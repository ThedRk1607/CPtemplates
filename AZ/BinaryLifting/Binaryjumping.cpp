int L;
vector<vii>g;
vector<vi>up;
vi dep;

void dfs(int node,int p,int d){
	dep[node]=d;
	up[node][0]=p;
	for(int i=1;i<=L;i++)up[node][i]=up[up[node][i-1]][i-1];

	for(auto ch:g[node]){
		if(ch.F==p)continue;
		dfs(ch.F,node,d+1);
	}
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	 for(int i=L;i>=0;i--){
		int bit=((dep[a]-dep[b])&(1<<i));
		if(bit)a=up[a][i];//to make depth equal bal;
	 }
	if(a==b)return a;
	for(int i=L;i>=0;i--){
		if(up[a][i]!=up[b][i]){//going upward till find lca;
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0];
}
void solve(){
	int n;cin>>n;
  L=ceil(log2(n));
  up.assign(n+5,vi(L+5));dep.resize(n+5);g.resize(n+5);
  rep(i,0,n-1){
  	int u,v;cin>>u>>v;
  	g[u].pb({v,i+1});
  	g[v].pb({u,i+1});
  }
  dfs(1,0,0);
 int lac=lca(a,b);



 
 }
 
