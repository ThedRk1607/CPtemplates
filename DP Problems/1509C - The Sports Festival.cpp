//something Range DP
int n;
ll dp[2005][2005];
    
void solve(){
 cin>>n;
 vl v(n+1);
 FOR(i,1,n+1)cin>>v[i];
 sort(all(v));
 ZERO(dp);
 for(int i=n;i>0;i--){
 	for(int j=1;j<=n;j++){
 		if(j<=i)dp[i][j]=0;
 		else dp[i][j]=(v[j]-v[i])+min(dp[i+1][j],dp[i][j-1]);
 	}
 }

cout<<dp[1][n];
