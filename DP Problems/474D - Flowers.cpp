
int dp[100005];// #valid subseq of length i ;
const int inf=1e9+7;

void solve(){
	int t,k;cin>>t>>k;

	ZERO(dp);
	vector<ll>p(1e5+1,0);
	
	for(int i=1;i<k;i++)dp[i]=1;
		dp[k]=2;
	for(int i=k+1;i<=1e5;i++){
		(dp[i]=dp[i-k]+dp[i-1])%=inf;
		
		}

		for(int i=1;i<=1e5;i++)p[i]=(p[i-1]+dp[i])%inf;
	while(t--){
		int a,b;cin>>a>>b;
		ll ans=p[b]-p[a-1];
		if(ans<0)ans+=inf;
		cout<<ans<<nl;
	}
}
