//link--https://atcoder.jp/contests/abc407/tasks/abc407_d
int A[N][N];
bool dp[1LL<<N];

void solve(){
  int n,m;cin>>n>>m;
  rep(i,0,n){
  	rep(j,0,m){
  		cin>>A[i][j];
  	}
  }
  dp[0]=1;
  for(int bit=0;bit<(1LL<<(n*m));bit++){
  	 if(!dp[bit])continue;
  	 for(int a=0;a<n;a++){
  	 	for(int b=0;b<m;b++){
  	 		if(bit&(1LL<<(a*m+b)))continue;
  	 		if(a+1<n){
  	 			bool ok1=(bit&(1LL<<((a+1)*m+b)));
  	 			if(!ok1)dp[bit|(1LL<<((a+1)*m+b))|(1LL<<(a*m+b))]=true;
  	 		}
  	 		if(b+1<m){
  	 			bool ok1=(bit&(1LL<<((a)*m+b+1)));
  	 			if(!ok1)dp[bit|(1LL<<((a)*m+b+1))|(1LL<<(a*m+b))]=true;
  	 		}
  	 	}
  	 }
  }
  int ans=0;
   for(int bit=0;bit<(1LL<<(n*m));bit++){
   	if(!dp[bit])continue;
   	int c=0;
   	for(int a=0;a<n;a++){
  	 	for(int b=0;b<m;b++){
  	 		if(bit&(1LL<<(a*m+b)))continue;
  	 		else c^=A[a][b];
  	 	}
  	 }
  	 amax(ans,c);
   }
   cout<<ans<<nl;
}
