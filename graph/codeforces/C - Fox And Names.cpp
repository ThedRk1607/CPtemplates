
const int N=2<<17;
vector<int>adj[N];
bool vis[N];
int n,m;
vector<int>indeg(N);






void solve(){
	int n;cin>>n;
	vs s(n);
	FORR(x,s)cin>>x;
	int k;
	FOR(i,1,n){
		k=0;
		int m=min(s[i].size(),s[i-1].size());
		for(int j=0;j<m;j++){
			if(s[i-1][j]!=s[i][j]){
				k=1;
				adj[s[i-1][j]-'a'].pb(s[i][j]-'a');
				indeg[s[i][j]-'a']++;
				break;
			}
		}
		if(!k){
			if(s[i].size()<s[i-1].size()){
				cout<<"Impossible\n";
				return;
			}
		}
	}
	vi ans;

	queue<int>q;
	for(int i=0;i<26;i++){
		if(indeg[i]==0)q.push(i);
	}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		ans.pb(v);
		for(auto e:adj[v]){
			indeg[e]--;
			if(indeg[e]==0)q.push(e);
		}
	}
if(ans.size()!=26){
	cout<<"Impossible\n";
	return;
}
FORR(x,ans)cout<<char(x+'a');
cout<<nl;
	

    }


 
