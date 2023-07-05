
void solve(){
  int n;cin>>n;

	int dp[n+1];
	for(int i=0;i<=n;i++)dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+1;
		for(int j=6;j<=i;j*=6)amin(dp[i],dp[i-j]+1);
		for(int j=9;j<=i;j*=9)amin(dp[i],dp[i-j]+1);
	}

cout<<dp[n];
   
