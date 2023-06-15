
vector<pii>adj[2<<17];
int dist[2<<17];

void solve(){

 	int n,e,t;cin>>n>>e>>t;
 	int m;cin>>m;
 for(int i=0;i<m;i++){
 	int x,y,z;cin>>x>>y>>z;
 	adj[y].pb({x,z});
 }

FOR(i,0,2<<17)dist[i]=1e9;

 int cnt=0;
 priority_queue< pair<int,int> , vector< pair<int,int> > ,greater< pair<int,int> > > q;
 
 	
 		q.push({e,0});
 		dist[e]=0;
     
 		while(!q.empty()){
 			auto x=q.top();
 			q.pop();
 			

 			for(auto v:adj[x.F]){
 				if(dist[x.F]+v.S<dist[v.F]){
 					dist[v.F]=v.S+dist[x.F];
 					q.push({v.F,v.S+dist[x.F]});
 				}
 			}
 		}

 		for(int i=1;i<=n;i++)if(dist[i]<=t)cnt++;
 			cout<<cnt<<nl;


}
