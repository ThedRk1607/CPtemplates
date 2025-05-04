int n,p,k;
vector<pair<int,array<int, 8>>> s(N);
 int dp[N][(1<<8)];
int rec(int i,int mask){
	if(i==n){
		if(mask==(1<<p)-1)return 0;
		return -1e13;
	}
	if(~dp[i][mask])return dp[i][mask];
	int ans=-1e13;
	int cnt=popcount(mask);
	if(i-cnt<k)ans=max(ans,rec(i+1,mask)+s[i].F);
	  ans=max(ans,rec(i+1,mask));

	for(int j=0;j<p;j++){
		if(mask>>j&1LL)continue;
		ans=max(ans,rec(i+1,mask|(1<<j))+s[i].S[j]);
	}

	return dp[i][mask]=ans;
}



void solve(){
  cin>>n>>p>>k;
  rep(i,0,n)cin>>s[i].F;
  rep(i,0,n){
  	rep(j,0,p)cin>>s[i].S[j];
  }
  sort(all(s),[&](pair<int,array<int, 8>>x,pair<int,array<int, 8>>y){
  	return x.F>y.F;
  });
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0);
  
}
	
