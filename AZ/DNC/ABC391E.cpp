int n;
string s;

pii dfs(int l,int r){
  if(l==r)return mpp(s[l]-'0',1);
  int len=r-l+1;
  pii a=dfs(l,l+len/3-1);
  pii b=dfs(l+len/3,r-len/3);
  pii c=dfs(r-len/3+1,r);
  if(a.F==b.F and b.F==c.F)return mpp(a.F,a.S+b.S+c.S-max({a.S,b.S,c.S}));
  else if(a.F==b.F)return mpp(a.F,min(a.S,b.S));
  else if(b.F==c.F)return mpp(b.F,min(c.S,b.S));
  else return mpp(a.F,min(a.S,c.S));
}


void solve(){
 cin>>n>>s;
 cout<<dfs(0,s.length()-1).S;
 

}
