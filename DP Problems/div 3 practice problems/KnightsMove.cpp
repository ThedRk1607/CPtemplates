
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
