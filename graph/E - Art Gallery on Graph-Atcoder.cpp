
int n,m,k;
vector<int>adj[2<<17];
vi p(2<<17);

vi dist(2<<17);


void solve(){

	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x-1].pb(y-1);
		adj[y-1].pb(x-1);
	}


for(int i=0;i<n;i++)dist[i]=-1;
PQ<pii>Q;
for(int i=0;i<k;i++){
	int p,h;cin>>p>>h;
	p--;
	dist[p]=h;
	Q.push(mpp(h,p));
}

int cnt=0;
while(!Q.empty()){
	int u=Q.top().S;
	int d=Q.top().F;
	Q.pop();
	if(dist[u]>d)continue;
	cnt++;
	if(d==0)continue;
	for(auto v:adj[u])if(dist[v]<d-1){
		dist[v]=d-1;
		Q.push(mpp(d-1,v));
	}
}
cout<<cnt<<nl;
for(int i=0;i<n;i++)if(dist[i]>=0)cout<<i+1<<(--cnt ?" ":"\n");



}
