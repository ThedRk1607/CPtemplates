const int mod=1e9+7,N=2e5+5;

ll dp[N][3];

 void solve(){
 	int n,l,r;cin>>n>>l>>r;
 	
 	ll num=r-l+1;
 	ll cnt0,cnt1,cnt2;
 	ll y=num%3;
 	num/=3;
 	cnt0=cnt1=cnt2=num;
 	if(l%3==0){
 		if(y==1)cnt0++;
 		if(y==2)cnt0++,cnt1++;
 	}else if(l%3==1){
 		if(y==1)cnt1++;
 		else if(y==2)cnt1++,cnt2++;
 	}else{
 		if(y==1)cnt2++;
 		else if(y==2)cnt2++,cnt0++;
 	}



 	dp[1][0]=cnt0;
 	dp[1][1]=cnt1;
 	dp[1][2]=cnt2;

 	for(int i=2;i<=n;i++){
 		(dp[i][0]=dp[i-1][0]*cnt0+dp[i-1][1]*cnt2+dp[i-1][2]*cnt1)%=mod;
 		(dp[i][1]=dp[i-1][0]*cnt1+dp[i-1][1]*cnt0+dp[i-1][2]*cnt2)%=mod;
 		(dp[i][2]=dp[i-1][0]*cnt2+dp[i-1][1]*cnt1+dp[i-1][2]*cnt0)%=mod;
 	}

 	cout<<dp[n][0];


 }
