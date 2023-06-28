
const int N = (int)2e5 + 100;

vector<int>adj[N];
bool vis[N];



void solve(){
	int n,m;cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vi ans;

	ZERO(vis);
	PQS q;
	q.push(1);
	vis[1]=true;

	while(!q.empty()){
		int x=q.top();
		q.pop();
		ans.pb(x);

		for(auto i:adj[x]){
			if(vis[i])continue;
			vis[i]=true;
			q.push(i);
		}
	}

	FORR(x,ans)cout<<x<<" ";
	
}
