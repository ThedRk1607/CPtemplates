
const ll mod=(int)1e9+7;

void solve(){
	int n;cin>>n;
	vi v(n);FORR(x,v)cin>>x;
	vector<int>dp(1e6+1,0); //dp[j] is #ways of good subseq having subseq size j;
	dp[0]=1;
	FORR(x,v){
		set<int, greater<int> >st;
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				st.insert(i);
				st.insert(x/i);
			}

		}

		FORR(x,st){
			(dp[x]+=dp[x-1])%=mod;

		}

	
	}
ll ans=0;
	FOR(i,1,n+1)(ans+=dp[i])%=mod;
if(ans<0)ans+=mod;
	cout<<ans<<nl;
	

}

