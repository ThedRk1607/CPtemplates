

ll dp[2<<17];

void solve(){
	int n;cin>>n;
	ll ans=1;
	while(n--){
		ll num;cin>>num;
		set<ll>st;
		for(int i=2;i*i<=num;i++){
			if(num%i==0){
				st.insert(i);
				st.insert(num/i);
			}
		}

		if(st.size()==0 and num!=1)st.insert(num);

		ll mx=0;
		FORR(x,st)amax(mx,dp[x]);
		FORR(x,st)dp[x]=mx+1;

		amax(ans,mx+1);
	}
	cout<<ans<<nl;
}
