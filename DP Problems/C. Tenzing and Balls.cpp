
void solve(){
	int n;cin>>n;
	vi v(n);
	ll arr[n+5];
	vl dp(n+5,0);
	vl mx(n+5,-INF);
        FOR(i,0,n+2) mx[i]=-INF;
        FOR(i,1,n+1) cin>>arr[i];
        dp[0]=0;
        for(int i=1; i<=n; i++){
            dp[i]=max(dp[i-1],i+mx[arr[i]]);
            mx[arr[i]]=max(mx[arr[i]],dp[i-1]-(i-1));
        }
        cout<<dp[n]<<nl;
}
