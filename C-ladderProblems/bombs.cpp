//sort accrding to manhattan distance;
bool cmp(pll a,pll b){
	return (abs(a.F)+abs(a.S))<=(abs(b.F)+abs(b.S));
}
 	
 void solve(){
 	int n;cin>>n;
 	vector<pll>v(n);
 	ll sz=0;
 	FOR(i,0,n){
 		ll x,y;cin>>x>>y;
 		v[i]={x,y};
 		sz+=2;
 		if(x!=0)sz+=2;
 		if(y!=0)sz+=2;
 	}
 	sort(all(v),cmp);
cout<<sz<<nl;
 	for(int i=0;i<n;i++){
 		auto it=v[i];
 		if(it.F>0)cout<<"1 "<<it.F<<" R\n";
 		if(it.F<0)cout<<"1 "<<-it.F<<" L\n";
 		if(it.S>0)cout<<"1 "<<it.S<<" U\n";
 		if(it.S<0)cout<<"1 "<<-it.S<<" D\n";
 		cout<<"2\n";
 		if(it.F>0)cout<<"1 "<<it.F<<" L\n";
 		if(it.F<0)cout<<"1 "<<-it.F<<" R\n";
 		if(it.S>0)cout<<"1 "<<it.S<<" D\n";
 		if(it.S<0)cout<<"1 "<<-it.S<<" U\n";
 		cout<<"3\n";

}

 	
}
