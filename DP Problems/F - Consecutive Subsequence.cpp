
map<ll,ll>dp; // dp[x] is length of longest subseq that ending at element x;
int n;

void solve(){
	cin>>n;
	vl v(n);FORR(x,v)cin>>x;

	dp[v[0]]=1;
	int mx=0;
	for(int i=1;i<n;i++){
		dp[v[i]]=dp[v[i]-1]+1;
		

	}
	int pos=0;
	int i=1;
	FORR(x,v){
		if(mx<dp[x]){
			mx=dp[x];
			pos=i;
		}
		i++;
	}
	cout<<mx<<nl;
	vl ans;
    ll cur=v[pos-1];

	for(int i=n-1;i>=0;i--){
		if(v[i]==cur)ans.pb(i+1),cur--;
	}
	reverse(all(ans));
	FORR(x,ans)cout<<x<<" ";
	



}
