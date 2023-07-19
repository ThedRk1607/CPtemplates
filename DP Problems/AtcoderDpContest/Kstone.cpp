
int dp[100005];
vi a(105);
int n;
int rec(int k){
	 if(k==0)return 0;
	 if(dp[k]!=-1)return dp[k];

	 int ans=0;
	 for(int j=0;j<n;j++){
	 	if(k>=a[j] and rec(k-a[j])==0){
	 		ans=1;
	 		break;
	 	}
	 }
return dp[k]=ans;
}

void solve(){
	int k;cin>>n>>k;
	FOR(i,0,n)cin>>a[i];
	memset(dp,-1,sizeof(dp));
	if(rec(k))cout<<"First\n";
	else cout<<"Second\n";
}
