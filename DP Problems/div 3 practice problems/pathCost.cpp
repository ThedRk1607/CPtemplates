
void solve(){

  
  ll dp[9][9];
  FOR(i,0,8)FOR(j,0,8)cin>>dp[i][j];





  for(int i=7;i>=0;i--){
  	for(int j=0;j<8;j++){
  		if(i==7 and j==0)continue;
  		ll plus=1e18;
  		 if(i+1<8) plus=min(plus,dp[i+1][j]);
  		 if(j>0) plus=min(plus,dp[i][j-1]);
  		 if(j>0 and i+1<8) plus=min(plus,dp[i+1][j-1]);
  		 dp[i][j]+=plus;
  	}
  }
  cout<<dp[0][7];

}
