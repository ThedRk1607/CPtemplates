const int mod=1e9+7;
const int N=2005;
ll dp[N][N];

void solve(){
 	int n,k;cin>>n>>k;

 	for(int i=1;i<N;i++)dp[1][i]=1;

 	for(int i=1;i<N;i++){
 		for(int j=1;j<N;j++){
 			for(int k=j;k<N;k+=j)dp[i][k]+=dp[i-1][j]%mod;
 		}
 	}
 ll ans=0;
 FOR(i,1,n+1)ans+=dp[k][i]%mod;
 cout<<ans%mod<<nl;

 }
