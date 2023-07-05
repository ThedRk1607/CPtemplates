
int dp[10005];
 

void solve(){
	int s,n;cin>>s>>n;
	vi v(n+1);
	FOR(i,1,n+1)cin>>v[i];

	dp[0]=0;
	

	for(int i=1;i<=n;i++){
		for(int j=s;j>=v[i];j--){
			dp[j]=max(dp[j],v[i]+dp[j-v[i]]);
		}
	}
cout<<dp[s];
}
