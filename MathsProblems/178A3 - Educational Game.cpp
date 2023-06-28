// f is highest power of 2 less than n;
ll f(int n){
	int x=0;
	for(int i=n;i>=n/2;i--){
		
		if(!(i&(i-1))){
			x=i;
			break;
		}
	}

	return x;
}

void solve(){
	int n;cin>>n;
	vi v(n);

	ll sum=0;
	FORR(x,v){
		cin>>x;
		
	}
	
	ll ans=0;
	for(int i=0;i<n-1;i++){
		v[i+f(n-i-1)]+=v[i];
		ans+=v[i];
		v[i]=0;
		cout<<ans<<nl;

	}



}
