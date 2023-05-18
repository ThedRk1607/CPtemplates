//for min distance find median and remembre;
ll n;cin>>n;
ll x[n],y[n];
FOR(i,0,n)cin>>x[i]>>y[i];
sort(x,x+n);
sort(y,y+n);

if(n%2==1){
	cout<<1<<nl;
	return;
}

	cout<<(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1)<<nl;

}
 
