void solve(){

ll n,x;cin>>n>>x;
bitset<64>b1(n),b2(x);
ll l=n,r=5e18;

for(int i=63;i>=0;i--){
	if(b1[i]==0 and b2[i]==0)continue;
	else if(b1[i]==0 and b2[i]==1){
		cout<<"-1\n";
		return;
	}else if(b1[i]==1 and b2[i]==1){
		r=min(r,(n/(1ll<<i)+1)*(1ll<<i)-1);
	}else{
		l=max(l,(n/(1ll<<i)+1)*(1ll<<i));
	}
}

if(l<=r)cout<<l<<nl;
else cout<<-1<<nl;


}

		
