//E - Connected Components?edu37
const int N = 200043;
 
set<int> g[N];
 
set<int> unused;
int cc = 0;
vector<int> comps;

void dfs(int x){
	unused.erase(x);
	comps[cc]++;
	int cur=-1;
	while(true){
		auto it=unused.ub(cur);
		if(it==unused.end())break;
		cur=*it;
		if(g[x].count(cur))continue;//not have edge passed
		dfs(cur);
	}
}

void solve(){
  int n,m;cin>>n>>m;
  rep(i,0,m){
  	int x,y;cin>>x>>y;x--,y--;
  	g[x].insert(y);g[y].insert(x);
  }
  rep(i,0,n)unused.insert(i);

  rep(i,0,n){
  	if(unused.count(i)){
  		comps.pb(0);//insert comp size;
  		dfs(i);
  		cc++;
  	}
  }
 sort(all(comps));
 cout<<comps.size()<<nl;
 repp(x,comps)cout<<x<<" ";	
}

//second method
//B. 0-1 MST

struct DSU{
	vi e,p;
	DSU(int N){e=vi(N,0),p=vi(N);iota(all(p),0);}
	int get(int x){return (p[x]==x)?x:p[x]=get(p[x]);}
	bool unite(int a,int b){
		a=get(a);b=get(b);
		if(a==b)return false;
		if(e[a]<e[b])swap(a,b);
		e[a]+=e[b];
		p[b]=a;
		return true;
	}
};

void solve(){
  int n,m;cin>>n>>m;
 vector<vi>g(n);
 rep(i,0,m){
 	int u,v;cin>>u>>v;u--,v--;
 	g[u].pb(v);
 	g[v].pb(u);
 }
 DSU dsu(n);map<int,int>mp;vi comp;
 for(int i=0;i<n;i++){
     dsu.e[i]=1;
     mp.clear();
     for(auto ch:g[i]){
     	if(ch>i)continue;
     	int p=dsu.get(ch);
     	mp[p]++;
     }
     repp(b,comp){
     	int fx=dsu.get(i);int fy=dsu.get(b);
     	if(fx==fy)continue;
     	if(dsu.e[fy]>mp[fy])dsu.unite(fx,fy);
     }
     int fx=dsu.get(i);
     if(fx==i)comp.pb(i);

 }
  int ans=0;
  rep(i,0,n)if(dsu.p[i]==i)ans++;
  cout<<ans-1<<nl;
 

	
}
