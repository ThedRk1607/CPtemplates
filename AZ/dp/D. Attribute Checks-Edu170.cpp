//one approach
const int N = (int) 1e3 + 100;
  int dp[N][N];

 void solve(){
 	int n,m;cin>>n>>m;
 	vi v1,v2;
 	vi v(n);repp(x,v)cin>>x;
 	int t=0;
 	dp[0][0]=0;
 	for(auto x:v){
 		if(x>0)v1.pb(x);
 		if(x<0)v2.pb(-x);
 		if(x==0){
 			sort(all(v1));sort(all(v2));
 			t++;
 			for(int s=0;s<=t;s++){
 				if(s!=0){
 					int in=t-s;
 					auto it1=ub(all(v1),s-1)-v1.begin();
 					auto it2=ub(all(v2),in)-v2.begin();
 					dp[t][s]=max(dp[t][s],dp[t-1][s-1]+it1+it2);
 				}
 				if(s<t){
 					int in=t-s-1;
 					auto it1=ub(all(v1),s)-v1.begin();
 					auto it2=ub(all(v2),in)-v2.begin();
 					dp[t][s]=max(dp[t][s],dp[t-1][s]+it1+it2);
 				}
 			}
 			v1.clear();v2.clear();
 		}
 	}
 	sort(all(v1));sort(all(v2));
 	int ans=0;
 	for(int s=0;s<=m;s++){
 		int in=m-s;
 		auto it1=ub(all(v1),s)-v1.begin();
 		auto it2=ub(all(v2),in)-v2.begin();
 		ans=max(ans,dp[m][s]+it1+it2);
 	}
 	cout<<ans<<nl;

 }
   
