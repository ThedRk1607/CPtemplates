const int N=501;
vector<int>pos,t,dist;

int dp[N][N];


int rec(int i, int k,int n){
	if(i==n)return 0;
	if(dp[i][k]!=-1)return dp[i][k];
	int d = dist[i];
	int time = t[i];
 
	int ans = 1e9+7;
 
	int remove = k;
 
	for(int j = i + 1 ; j <= n && remove >= 0 ; j++)
	{
		int op1 = (time * d) + rec(j , remove , n);
		ans = min(ans , op1);
 
		d += dist[j];
		remove--;
	}
	return dp[i][k]=ans;
}

void solve(){
	int n,k,l;cin>>n>>l>>k;
	t.resize(n);
	pos.resize(n);
	dist.resize(n);
 
	for(int i = 0 ; i < n ; i++)
		cin >> pos[i];
	for(int i = 0 ; i < n ; i++)
		cin >> t[i];
 
	pos.push_back(l);
 
	for(int i = 0 ; i < n ; i++)
		dist[i] = pos[i + 1] - pos[i];
	dist.push_back(0);
 memset(dp,-1,sizeof dp);
 cout<<rec(0,k,n);

 

}
