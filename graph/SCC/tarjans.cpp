
const int N=2<<17;
vector<int>adj[N];
bool vis[N];
int n,m;
vector<int>disk(N,-1),lowLink(N,-1);
stack<int>st;
map<int,int>mp;
set<int>s;
int tmr=0;

void dfs(int u){
	static int tm=0;
	disk[u]=lowLink[u]=++tm;
	st.push(u);
	vis[u]=1;

	for(auto e:adj[u]){
		if(disk[e]==-1){
			dfs(e);
			amin(lowLink[u],lowLink[e]);
		}else if(vis[e]){
			amin(lowLink[u],disk[e]);
		}
	}

	int pop=0;
	if(lowLink[u]==disk[u]){
		tmr++;
		while(st.top()!=u){
			pop=st.top();
			mp[pop]=tmr;
			s.insert(tmr);
			vis[pop]=0;
			st.pop();
		}
		pop=st.top();
		mp[pop]=tmr;
		s.insert(tmr);
		vis[pop]=0;
		st.pop();
	}
}





void solve(){
	int n,m;cin>>n>>m;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
	}
ZERO(vis);

for(int i=1;i<=n;i++){
	if(disk[i]==-1)dfs(i);
}

cout<<s.size()<<nl;
for(int i=1;i<=n;i++){
	cout<<mp[i]<<" ";
}


    }
