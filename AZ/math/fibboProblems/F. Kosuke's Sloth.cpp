//link-https://codeforces.com/contest/2033/problem/F
void solve(){
	int n,k;cin>>n>>k;n%=mod;
	int a=1,b=1,c=0,id=1;
	while(a%k!=0){
		c=(a+b)%k;id++;
		a=b;
		b=c;
	}
	cout<<mul(id,n)<<nl;

}
