
void solve(){
 	int n,q;cin>>n>>q;
 	vl a(n);FORR(x,a)cin>>x;
 	vector<ll>dp1(n+1,0),dp2(n+1,0);
 	dp1[0]=-1;
 	dp2[0]=0;
 	for(int i=1;i<=n;i++){
 		dp1[i]=max(dp1[i-1],dp2[i-1]+a[i-1]);
 		dp2[i]=max(dp2[i-1],dp1[i-1]-a[i-1]);
 	}

 	cout<<max(dp1[n],dp2[n])<<nl;
 	
 }
