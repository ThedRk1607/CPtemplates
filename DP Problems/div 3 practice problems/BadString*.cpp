

unordered_map<char,vi>dp;
//dp[c][n] is #strings consisting a,b,c without substr "ab" ;
//:-having last char c of length n;

void solve(){
	
	int n;cin>>n;
	if(!n){
		cout<<1<<nl;
		return;
	}
  //important notice
	for(char c='a';c<='c';c++){
		dp[c].resize(n);
		dp[c][0]=1;
	}

	for(int i=1;i<=n;i++){
		dp['a'][i]=dp['a'][i-1]+dp['b'][i-1]+dp['c'][i-1];
		dp['b'][i]=dp['b'][i-1]+dp['c'][i-1];
		dp['c'][i]=dp['a'][i-1]+dp['b'][i-1]+dp['c'][i-1];
	}

	 ll ans=dp['a'][n-1]+dp['b'][n-1]+dp['c'][n-1];
	 cout<<ans;
}

