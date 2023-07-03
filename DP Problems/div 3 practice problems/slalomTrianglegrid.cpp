

nt dp[101][101];

void solve(){
  int n;cin>>n;
  vector<int>mount[n+1];

   for(int i=0;i<n;i++){
   	  for(int j=0;j<=i;j++){
   	  	int x;cin>>x;
   	  	mount[i].pb(x);

   	  	dp[i][j]=-INF;
   	  }
   }


dp[0][0]=mount[0][0];
for(int i=0;i<n;i++){
	for(int j=0;j<=i;j++){
		if(j<i and i)dp[i][j]=max(dp[i][j]+mount[i][j],dp[i-1][j]);
		if(j and i)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+mount[i][j]);
	}
}
int mx=0;
for(int i=0;i<n;i++)amax(mx,dp[n-1][i]);
	cout<<mx<<nl;

}
