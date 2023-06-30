
const int N=100005;
int n,k;
vector<int>adj[N];
bool vis[N];
int color[N];
vi ord;

void dfs(int s)
{
	if (!color[s])
	{
		color[s] = 1;

		for (int e : adj[s])
			dfs(e);

		color[s] = 2;
		ord.push_back(s);
	}

	else if (color[s] == 1)
	{
		printf("-1");
		exit(0);
	}
}

void solve(){
	cin>>n>>k;
	vi v(k);
	FORR(x,v)cin>>x;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=0;j<x;j++){
			int y;cin>>y;
			adj[i].pb(y);
		}
	}
	ZERO(color);
	for(int i=0;i<k;i++){
		if(!color[v[i]])dfs(v[i]);
	}


cout<<ord.size()<<nl;
FORR(x,ord)cout<<x<<" ";

	
}
