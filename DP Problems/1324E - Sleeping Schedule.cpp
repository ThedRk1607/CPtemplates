const int mod=1e2+2,N=5e3+5;
int n,h,l,r;
int add(int t1, int t2){
	int t = t1+t2;
	if(t>=h) t-=h;
	return t;
}

void solve(){
	cin>>n>>h>>l>>r;
	vi a(n);FORR(x,a)cin>>x;
	vector<vector<int>>dp(n+1,vector<int>(h,0));//mx good sleep having sleep i times and for j hours

for (int i=n-1; i>-1; --i){
		for(int t=0; t<h; ++t){
			int t1 = add(t, a[i]);
			int t2 = add(t, a[i]-1);
			int cost1 = (l<=t1 and t1<=r) ? 1 : 0;
			int cost2 = (l<=t2 and t2<=r) ? 1 : 0;
			dp[i][t] = max( cost1+dp[i+1][t1] , cost2+dp[i+1][t2]);
		}
	}
 
	cout<<dp[0][0];

}
