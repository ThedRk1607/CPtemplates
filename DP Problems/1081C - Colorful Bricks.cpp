const int N=2005,mod= 998244353;

ll dp[N][N]; //#ways to color i brick having j diff color bricks;

void solve(){
	int n,m,k;cin>>n>>m>>k;
	ZERO(dp);
	dp[1][0]=m;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			(dp[i][j]=dp[i-1][j])%=mod;
			(dp[i][j]+=dp[i-1][j-1]*(m-1))%=mod;
		}
	}

cout<<dp[n][k];


}
