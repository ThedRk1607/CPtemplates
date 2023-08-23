vector<int>ans;

 vector<int>rec(int n,int k){
	if(n==0) {
		
		return {};
	}
	 if(k<n){
	 	ans.resize(n);
	 	
	 	FOR(i,0,n)ans[i]=-1;
	 	if(k)ans[k-1]=200;
	 	ans[k]=-400;
	 
	 }else{
	 	 ans=rec(n-1,k-n);
	 	 ans.pb(1000); //nth element;
	 }
	 return ans;


}

void solve(){
	int n,k;cin>>n>>k;
	vi res;
	res=rec(n,k);
	 FORR(x,res)cout<<x<<" ";
	cout<<nl;

}
