const int N=2<<17;
vector<pii>adj[N];
vi t[N];
bool vis[N];
vector<int>dist(N,1e9);
int n,m;
set<int>st;

void solve(){
 cin>>n>>m;
 FOR(i,0,m){
 	int a,b,c;cin>>a>>b>>c;
 	adj[a].pb({b,c});
 	adj[b].pb({a,c});
 }	

 FOR(i,1,n+1){
 	int k;cin>>k;
 	FOR(j,0,k){
 		int x;cin>>x;
 		st.insert(x);
 		t[i].pb(x);
 	}
 }

 PQS q;
 q.push({0,1});
 dist[1]=0;

 while(!q.empty()){
 	auto it=q.top();
 	q.pop();
 	if(it.S==n)break;

 if(dist[it.S]!=it.F)continue;
 	 int pos=(int)(lb(all(t[it.S]),dist[it.S])-t[it.S].begin());
 	 while(pos<(int)t[it.S].size() and t[it.S][pos]==dist[it.S])pos++,dist[it.S]++;
 	
 	for(auto e:adj[it.S]){
 		if(dist[it.S]+e.S<dist[e.F]){
 			dist[e.F]=dist[it.S]+e.S;
 			q.push({dist[e.F],e.F});
 		}
 	}
 }
 
 	
 

if(dist[n]==1e9){
	cout<<"-1\n";
}else cout<<dist[n]<<nl;
	
}
 
