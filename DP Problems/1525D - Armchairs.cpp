
//
ll n;
vl v1,v2;
ll dp[5005][5005];

ll rec(int i,int j){
  if(i==v1.size())return 0;
//pruning or impossible
  if(j==v2.size())return INF;

if(dp[i][j]!=-1)return dp[i][j];
ll ans=1e9;
		ans=min(rec(i+1,j+1)+abs(v1[i]-v2[j]),rec(i,j+1));	
   
   return dp[i][j]=ans;
	
}
//
