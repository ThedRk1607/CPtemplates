const int N=1e5+5;
vector<ll>dp(N,1e18);

void solve(){
	ll n,W;cin>>n>>W;
	vl v(n+1),w(n+1);
	FOR(i,1,n+1){
		cin>>w[i]>>v[i];
	}
dp[0]=0;

for(int i=1;i<=n;i++){
	for(int j=1e5;j>=v[i];j--){
		dp[j]=min(dp[j],w[i]+dp[j-v[i]]);
	}
}

int ans=0;
for(int i=1e5;i>0;i--){
	if(dp[i]<=W){
		ans=i;
		break;
	}
}
cout<<ans<<nl;

}
	
