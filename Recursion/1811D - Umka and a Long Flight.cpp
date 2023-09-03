ll fib[50];

bool check(int n, int x, int y) {
	if (n == 1) return true;
	if (fib[n - 1] <= y && y < fib[n])
		return false;
	if (fib[n] <= y)
		y -= fib[n];
	return check(n - 1, y, x);
}


void solve(){
	ll n,x,y;cin>>n>>x>>y;
	
	fib[0]=1,fib[1]=1;
	for(int i=2;i<=50;i++)fib[i]=fib[i-2]+fib[i-1];

	cout<<(check(n,--x,--y)? "YES":"NO")<<nl;

  



}

		
