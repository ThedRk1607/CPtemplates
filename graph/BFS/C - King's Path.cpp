
const int N=2<<17;
vector<int>adj[N];



map<pll,bool>allow,vis;
map<pll,ll>dist;

void solve(){
	ll x0,y0,x1,y1;cin>>x0>>y0>>x1>>y1;
	int n;cin>>n;
	FOR(i,0,n){
		int r,a,b;cin>>r>>a>>b;
		for(ll i=a;i<=b;i++)allow[{r,i}]=true;
	}

allow[{x0,y0}]=true;
allow[{x1,y1}]=true;

queue<pll>q;
q.push({x0,y0});
dist[{x0,y0}]=0;
vis[{x0,y0}]=1;

while(!q.empty()){
	auto it=q.front();q.pop();
	vis[{it.F,it.S}]=true;
	for(int r=0;r<8;r++){
		ll x=it.F+dxn[r];
		ll y=it.S+dyn[r];
		if(allow[{x,y}] and !vis[{x,y}]){
			if(!dist[{x,y}] or dist[{x,y}]>dist[{it.F,it.S}]+1){
				dist[{x,y}]=dist[{it.F,it.S}]+1;
				q.push({x,y});
			}
		}
		
	}
}

if(vis[{x1,y1}])cout<<dist[{x1,y1}];
else cout<<"-1\n";

	

}
