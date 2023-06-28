
const int N = (int)2e5 + 100;

vector<int>adj[N];
bool vis[N];
int sz;

ll binpow(ll a,ll b,ll m){
	if(b==0)return a%m;
 ll res=1;
	while(b>0){
		if(b&1)res=res*a%m;
		 a=a*a%m;

		b>>=1;
	}

	return res;
}

void dfs(int u){
	vis[u]=true;
	sz++;
	for(auto v:adj[u]){
		if(vis[v])continue;
		dfs(v);
	}
}

void solve(){
	int n,k;cin>>n>>k;
//total sequences;and now minus bad sequence to find good one;
	int ans=binpow(n,k,mod);
	for(int i=1;i<=n;i++){
		int u,v,x;cin>>u>>v>>x;
		if(x==0)adj[u].pb(v),adj[v].pb(u);
	}

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sz=0;
			dfs(i);
			ans-=binpow(sz,k,mod);
			ans+=mod;
			ans%=mod;

		}
	}
cout<<ans<<nl;
	
}

	
