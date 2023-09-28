
long long get(long long n)
{
    long long ans = 0;
    for (long long i = 2; i * i * i <= n;++i)
        ans += n / (1ll*i * i * i);
    return ans;
}



void solve(){
    ll m;
	cin>>m;
	


	ll ans=-1;
	ll lo=0,hi=1e18;
	while(lo<=hi){
		ll r=(hi+lo)/2;
		if(get(r)>=m){
			ans=r;
			hi=r-1;
		}else lo=r+1;
	}
	if(get(lo)!=m)ans=-1;
	cout<<ans<<nl;

  
}
 
