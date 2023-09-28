ll n,m,k;

ll get(ll x){
	ll rs=0;
	x--;
	for(int i=1;i<=n;i++)rs+=min((ll)m,x/i);
		return (rs);
}

void solve(){
  cin>>n>>m>>k;
	ll ans=-1;
	ll lo=1,hi=1ll*m*n;
	while(lo<=hi){
		ll r=(hi+lo)/2;
		if(get(r)<k){
			ans=r;
			lo=r+1;
		}else hi=r-1;
	}
	
	cout<<ans<<nl;

  
}
