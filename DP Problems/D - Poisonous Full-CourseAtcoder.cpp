
l dp0=0,dp1=0;

void solve(){
  int n;cin>>n;
  

   for(int i=0;i<n;i++){
   	ll x,y;cin>>x>>y;
   	if(x==0){
   		dp0=max(dp0,max(dp0,dp1)+y);
   	}else {
   		dp1=max(dp1,dp0+y);
   	}
   }
   
   cout<<max(dp0,dp1);
