
const int N=1e5+5;
ll dp[101][N];

void solve(){
	int n,W;cin>>n>>W;
	vl v(n+1),w(n+1);
	FOR(i,1,n+1){
		cin>>w[i]>>v[i];
	}

for(int i=1;i<=n;i++){
	for(int j=0;j<=W;j++){
		dp[i][j]=dp[i-1][j];
		if(j-w[i]>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
	}
}
cout<<dp[n][W];


}


//
const int N=1e5+5;
vector<ll>dp(N);

void solve(){
	int n,W;cin>>n>>W;
	vl v(n+1),w(n+1);
	FOR(i,1,n+1){
		cin>>w[i]>>v[i];
	}

for(int i=1;i<=n;i++){
	for(int j=W;j>=w[i];j--){
		dp[j]=max(dp[j],v[i]+dp[j-w[i]]);
	}
}
cout<<dp[W];


}
	
