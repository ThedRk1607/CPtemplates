
void solve(){
	ll n,k;cin>>n>>k;
	vi a(n);FORR(x,a)cin>>x;
	vl h(n);FORR(x,h)cin>>x;

		vector<ll>p(n+1),len(n+1);
		p[0]=0;
		FOR(i,0,n)p[i+1]=p[i]+a[i];
		
		len[n-1]=1;
		for(int i=n-2;i>=0;i--){
			if(h[i]%h[i+1]==0){
				len[i]=len[i+1]+1;

			}else len[i]=1;
		}

auto ok=[&](int d){
	bool found=false;
	for(int i=0;i<n-d+1;i++){
		if(len[i]<d)continue;
		int sum=p[i+d]-p[i];
		if(sum<=k){
			found=true;
			break;
		}
	}
	return found;
};


		int ans=0;
		int lo=1,hi=n+5;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			if(ok(mid)){
				ans=mid;
				lo=mid+1;
			}else hi=mid-1;
		}

cout<<ans<<nl;


    }
