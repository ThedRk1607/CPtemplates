

const int N=1e5+5;
ll dp[N][3];

void solve(){
	ll n,p,q,r;cin>>n>>p>>q>>r;
	vl b={p,q,r};
	sort(all(b));
	vl a(n);FORR(x,a)cin>>x;
	dp[0][0]=p*a[0];
	dp[0][1]=p*a[0]+q*a[0];
	dp[0][2]=dp[0][1]+r*a[0];
	
	for(int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][0],p*a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i][0]+q*a[i]);
		dp[i][2]=max(dp[i-1][2],dp[i][1]+r*a[i]);

	}
	cout<<dp[n-1][2];


}
