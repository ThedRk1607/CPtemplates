void solve(){
 int n;cin>>n;
  vi v(n);FORR(x,v)cin>>x;
  int m;cin>>m;
  vi b(m);FORR(x,b)cin>>x;

  int dp[n+2][m+2];
  FOR(i,0,n+1)FOR(j,0,m+1)dp[i][j]=INT_MIN;
  dp[0][0]=0;
  int mx=0;
  for(int i=0;i<=n;i++){
  	for(int j=0;j<=m;j++){
  		if(i<n)dp[i+1][j]=max(dp[i+1][j],dp[i][j]+v[i]);
  		if(j<m)dp[i][j+1]=max(dp[i][j+1],dp[i][j]+b[j]);
  		amax(mx,dp[i][j]);
  	}
  }
  cout<<mx<<nl;

 

 }
