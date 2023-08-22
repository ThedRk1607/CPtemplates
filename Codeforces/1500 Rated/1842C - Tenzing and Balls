const int N= 200005;
int n,a[N],dp[N],st[N];

void solve(){
	cin>>n;
	vl a(n+1,0);
	FOR(i,1,n+1)cin>>a[i];
	vl dp(n+1,-INF);
	vl mx(n+1,-INF);
	dp[1]=0;
	mx[a[1]]=-1;

	FOR(i,2,n+1){
		dp[i]=dp[i-1];
		dp[i]=max(dp[i],mx[a[i]]+i+1);
		mx[a[i]]=max(mx[a[i]],dp[i-1]-i);
	}
	cout<<dp[n]<<nl;

}
