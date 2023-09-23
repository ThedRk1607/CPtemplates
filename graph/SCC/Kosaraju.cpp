const int N=2<<17;
vector<int>adj[N],adjR[N];
vb vis;
int n,m;
vi order,components(N);
set<int>st;

void dfs1(int u){
	vis[u]=1;
	for(auto e:adj[u]){
		if(vis[e])continue;
		dfs1(e);
	}
	order.pb(u);
}

void dfs2(int u,int c){
	vis[u]=1;
	components[u]=c;
	st.insert(c);
	for(auto e:adjR[u]){
		if(vis[e])continue;
		dfs2(e,c);
	}

}



void solve(){
	int n,m;cin>>n>>m;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adjR[y].pb(x);
	}

vis.assign(N,false);
FOR(i,1,n+1)if(!vis[i])dfs1(i);
vis.assign(N,false);
reverse(all(order));
int c=0;

for(auto e:order){

	if(!vis[e]){
		c++;
		dfs2(e,c);
	}
}
cout<<st.size()<<nl;
FOR(i,1,n+1)cout<<components[i]<<" ";

    }
