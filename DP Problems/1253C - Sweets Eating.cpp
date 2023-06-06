
int n,m;
	cin>>n>>m;

	vl a(n+1);
	vl pref(N,0);
	vl dp(N,0);

	FOR(i,1,n+1)cin>>a[i];
	sort(all(a));
	
	FOR(i,1,m+1)pref[i]=a[i];

FOR(i,m+1,n+1)pref[i]=pref[i-m]+a[i];

FOR(i,1,n+1){
	dp[i]=dp[i-1]+pref[i];
}

FOR(i,1,n+1)cout<<dp[i]<<" ";
