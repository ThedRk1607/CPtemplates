//atcoder regular contest problem intials
int fact[200100];

void f(){
 fact[0]=fact[1]=1;
 rep(i,2,200005)fact[i]=mul(fact[i-1],i);
}
 
int  nck(int n,int k){
	if(n<k)return 0LL;
	int C=fact[n];
	C=mul(C,inv(fact[k]));
	C=mul(C,inv(fact[n-k]));
	return C;

}
int ways(int x,int y){return nck(x+y-2,x-1);}	

void solve(){
  int h,w,a,b;cin>>h>>w>>a>>b;
  f();
  int ans=0;
  for(int H=0;H<h-a;H++){
  	 ans=add(ans,mul(ways(H+1,b),ways(h-H,w-b)));
  }
 cout<<ans;


}
