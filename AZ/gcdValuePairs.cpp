//using inclusion-exclusion principle
void solve(){
	int n;cin>>n;
	vi mp(1e6+1,0);
	int N=0;
	rep(i,0,n){
		int x;cin>>x;mp[x]++;
		amax(N,x);
	}
	vector<int>gcdValues(N,0);//#pairs of gcd value i;
	for(int i=N;i>=1;i--){
		 int c1=0,sub=0;//c1-#pairs of gcd value i; sub-already calculated in i;
		for(int j=i;j<=N;j+=i){
			c1+=mp[j];
			sub+=gcdValues[j];
		}
		gcdValues[i]=1LL*c1*(c1-1)/2-sub;
	}
	cout<<gcdValues[1];

}
