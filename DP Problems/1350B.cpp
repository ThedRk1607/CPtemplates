
void solve(){
  int n;cin>>n;
  vi arr(n+1);
  FOR(i,1,n+1)cin>>arr[i];
vector<int>dp(n+5,1);
 
 for(ll i=2;i<=n;i++){
 	//int mx=0;
 	for(ll j=1;j*j<=i;j++){
 		if(i%j==0){
 			 int d1=j;
 			 int d2=i/j;

 				if(arr[d1]<arr[i])amax(dp[i],dp[d1]+1);
 				if(d1!=d2)
 				if(arr[d2]<arr[i])amax(dp[i],dp[d2]+1);
 		}

 	}

 }
int ans=dp[1];
for(int i=1;i<=n;i++)amax(ans,dp[i]);
	cout<<ans<<nl;
 

}
