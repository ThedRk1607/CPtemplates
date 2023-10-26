
ll dp[2222],umb[2222];
bool rain[2222];

void solve(){
	int a,n,m;cin>>a>>n>>m;
	
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		for(int j=l;j<r;j++)rain[j]=1;
	}
		
for(int i=0;i<=a;i++) umb[i]=dp[i]=inf;

for(int i=0;i<m;i++){
	ll idx,k;cin>>idx>>k;
	umb[idx]=min(umb[idx],k);
}

dp[0]=0;
ll i,j;
 for(i=1;i<=a;i++){
        if(rain[i-1]==false) dp[i]=dp[i-1];
        else{
            for(j=i-1;j>=0;j--){
                if(umb[j]!=inf){
                    dp[i]=min(dp[i],dp[j]+(i-j)*umb[j]);
                }
            }
        }
    }

if(dp[a]==inf)dp[a]=-1;
cout<<dp[a]<<nl;

	
}
