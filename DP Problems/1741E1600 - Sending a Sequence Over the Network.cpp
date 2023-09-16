
void solve(){
	int n;cin>>n;
	vl b(n+1);FOR(i,1,n+1)cin>>b[i];
	vb dp(n+1,false); //dp[i] is true means pref of i valid
	dp[0]=true;
	FOR(i,1,n+1){
		if(i+b[i]<=n and dp[i-1])dp[i+b[i]]=true;
		if(i-b[i]-1>=0 and dp[i-b[i]-1])dp[i]=true;

	}
	if(dp[n])cout<<"YES\n";
	else cout<<"NO\n";
}
