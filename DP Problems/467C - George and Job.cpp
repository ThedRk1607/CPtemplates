const int mod=1e9+7,N=5e3+5;

void solve(){
	ll n,m,k;cin>>n>>m>>k;
	
	vector<ll>sum(N,0);
	vector<vector<ll>>dp(N,vector<ll>(N,0));
	
	for(ll i=1;i<=n;i++){
		 ll a;cin>>a;
		 sum[i]=sum[i-1]+a;
	}
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				//dp[i][j]=dp[i][j-1];
				if(j>0 and j-m>=0)dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+sum[j]-sum[j-m]);
			}
		}

	cout<<dp[k][n];
