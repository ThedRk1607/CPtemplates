int gcd(int a,int b){return b==0?a:gcd(b,a%b);}


void solve(){
	
int n;cin>>n;
vector<int>bits(32,0);
 for(int i=0;i<n;i++){
 	ll a;cin>>a;
 	for(int j=0;j<31;j++)bits[j]+=(1&(a>>j));
 }
int k=bits[0];
for(int j=0;j<31;j++)k=gcd(k,bits[j]);

if(k==0){
	for(int i=1;i<=n;i++)cout<<i<<" ";
}else {
	for(int i=1;i<=k;i++){
		if(k%i==0)cout<<i<<" ";
	}
}
cout<<nl;

}

