
void solve(){
	int n,m;cin>>n>>m;
	int dp[n+1][m+1];
ZERO(dp);
	dp[0][0]=1; //ways to dont move anywhere;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>1 and j)dp[i][j]=dp[i-2][j-1];
			if(j>1 and i)dp[i][j]+=dp[i-1][j-2];
		}
	}

	cout<<dp[n-1][m-1];
}

//
void solve(){

  ll n=8;
  ll grid[n][n];
  FOR(i,0,n)FOR(j,0,8)cin>>grid[i][j];
  FOR(i,0,n)FOR(j,0,8)dp[i][j]=INF;

dp[7][0]=0;



  for(int i=7;i>=0;i--){
  	for(int j=0;j<8;j++){
  		if(i<n-1)dp[i][j]=min(dp[i][j],grid[i][j]+dp[i+1][j]);
  		if(j)dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j-1]);
  		if(i<n-1 and j)dp[i][j]=min(dp[i][j],grid[i][j]+dp[i+1][j-1]);
  	}
  }
  cout<<dp[0][7];
