//link-https://codeforces.com/contest/1180/problem/D 
void solve(){
  int n,m;cin>>n>>m;
  int x=0,y=n*m-1;
  bool p=1;
  for(int i=0;i<n*m;i++){
  	if(p){
  		cout<<(x/m+1)<<" "<<(x%m+1)<<nl;
  		x++;
  	}else{
  		cout<<(y/m+1)<<" "<<(y%m+1)<<nl;
  		y--;
  	}
  	p^=1;
  }
  

}
