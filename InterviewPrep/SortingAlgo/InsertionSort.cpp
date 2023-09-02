void solve(){
	int n;cin>>n;
	vi v(n);
	FORR(x,v)cin>>x;
	for(int i=1;i<n;i++){
		int tmp=v[i];
		int j=i-1;
		while(j>=0 and tmp<=v[j]){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=tmp;
	}
	
	
	FORR(x,v)cout<<x<<" ";
}

		
