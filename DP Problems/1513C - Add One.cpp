
void solve(){
	ll n,m;cin>>n>>m;

//dp[i][j]=length of the number starting with digit i, after j operations
vector<vl>dp(10,vl(200005,1));
FOR(j,1,2e5+1){
	FOR(i,0,10){
		if(i<9){
			(dp[i][j]=dp[i+1][j-1])%=INF;

		}else (dp[i][j]=dp[1][j-1]%INF+dp[0][j-1]%INF)%=INF;

			}
}
  

ll ans=0;
while(n>0){
	ll d=n%10;
	n/=10;
	ans+=dp[d][m];
	ans%=INF;
}

cout<<ans<<nl;
}

	
