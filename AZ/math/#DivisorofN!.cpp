void solve(){
	int n;cin>>n;
  int ans=1;vi isp(n+1,1);
//using integer fact-x1^p1,x2^p2...xn^pn then div=(p1+1)*(p2+1)....*(pn+1);_
  for(int i=2;i<=n;i++){
  	if(!isp[i])continue;
  	for(int j=2*i;j<=n;j+=i)isp[j]=false;
  		int sum=0,now=n;
  		while(now>0){
  			sum=add(sum,now/i);
  			now/=i;
  		}
  		ans=mul(ans,(sum+1));
  }
  cout<<ans<<nl;
	  
}
