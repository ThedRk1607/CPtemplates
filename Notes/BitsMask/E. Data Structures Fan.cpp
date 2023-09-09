void solve(){

 int n;cin>>n;
 vl v(n+1);FOR(i,1,n+1)cin>>v[i];
 string s;cin>>s;


 vl xr(n+1,0);
 FOR(i,1,n+1){
 	
 	xr[i]=xr[i-1]^v[i];
 }

 int q;cin>>q;
int xrzero=0,xrone=0;
FOR(i,1,n+1){
	if(s[i-1]=='0')xrzero^=v[i];
	else xrone^=v[i];
}
 while(q--){
 	int tp;cin>>tp;
 	if(tp==1){
 		int l,r;cin>>l>>r;
 		int xrsum=xr[r]^xr[l-1];
 		xrzero^=xrsum;
 		xrone^=xrsum;
 	}else{
 		int g;cin>>g;
 		if(g==0)cout<<xrzero<<" ";
 		else cout<<xrone<<" ";
 	}
 }

cout<<nl;



}

		
