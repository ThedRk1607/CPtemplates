
nt n,m;
vector<int>adj[200005];
int ans[200005];
int cnt[200005];


void solve(){
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int x;cin>>x;
		adj[x-1].pb(i);
	}
ZERO(cnt);
ZERO(ans);
	queue<int>q;
	q.push(0);

	while(!q.empty()){
		int v=q.front();
		q.pop();

		for(auto i:adj[v]){
			if(!ans[i]){
				ans[i]=ans[v]+1;
				cnt[ans[i]]++;
				q.push(i);
			}
		}
	}
int res=0;
for(int i=0;i<n;i++){
	if(cnt[i]%2==1)res++;
}
cout<<res+1<<nl;
}

