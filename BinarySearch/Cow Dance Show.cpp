

int n,T;
vector<int>v(2<<17);

bool check(int k){
	
	multiset<int>ms;
	for(int i=0;i<k;i++)ms.insert(v[i]);

	for(int i=k;i<n;i++){
		ms.insert(v[i]+(*ms.begin()));
			ms.erase(ms.find(*ms.begin()));
	}

  return (*(--ms.end())<=T);
}

void solve(){
	cin>>n>>T;
	for(int i=0;i<n;i++)cin>>v[i];
ll ans=0;
		int l=1,hi=n;
	while(l<=hi){
		int k=l+(hi-l)/2;
		if(check(k)){
			ans=k;
			hi=k-1;
		}else l=k+1;
	}

	cout<<ans<<nl;
}
