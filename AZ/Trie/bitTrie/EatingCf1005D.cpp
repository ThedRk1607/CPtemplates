int a[N],p[N];
void solve(){
  int n,q;cin>>n>>q;
   rep(i,1,n+1){
      cin>>a[i];p[i]=(p[i-1]^a[i]);
   }
   vector<vi>nxt(n+2,vi(32,0));//nxt id from i that has >=b bit;
   for(int i=1;i<=n;i++){
      nxt[i]=nxt[i-1];
      int z=log2(a[i]);
      for(int b=z;b>=0;b--)nxt[i][b]=i;
   }
   a[0]=(1LL<<30);
   while(q--){
      int x,s=n+1;cin>>x;
      while(x>=a[s-1]){
         x^=a[s-1];s--;
         int z=nxt[s-1][log2(x)];
         x^=(p[s-1]^p[z]);s=z+1;
      }
      cout<<n-s+1<<" ";
   }cout<<nl;
}

struct trie{
   trie*ch[2];int cnt=0;
   trie(){ch[0]=ch[1]=NULL;cnt=0;}
};
 
void insert(trie*T1,int x){
   trie*T=T1;
   for(int b=30;b>=0;b--){
      int bb=(x>>b&1LL);
      if(T->ch[bb]==NULL){T->ch[bb]=new trie();}
      T=T->ch[bb];T->cnt++;
   }
}
 
void remove(trie*T1,int x){
   trie*T=T1;
   for(int b=30;b>=0;b--){
      int bb=(x>>b&1LL);
      T->ch[bb]->cnt--;
      T=T->ch[bb];
   }
}
 
int findM(trie*T1,int x){
   trie*T=T1;int r=0;
    for(int b=30;b>=0;b--){
      int bb=(x>>b&1LL);
      if(T->ch[bb] and T->ch[bb]->cnt)T=T->ch[bb];
      else{
         r|=(1LL<<b);T=T->ch[!bb];
      }
     
   }
   return r;
}
 
 
void solve(){
   int n,q;cin>>n>>q;
   vi a(n);repp(x,a)cin>>x;
   map<int,int>ans;trie*T=new trie();
   vi Q(q);repp(x,Q)cin>>x,insert(T,x);
   int cur=0,j=0;
   for(int i=n-1;i>=0;i--){
      while(j<q){
         int val=findM(T,cur);
         if(val>=a[i])break;j++;
         int que=val^cur;
         ans[que]=n-i-1;remove(T,que);
      }
      cur^=a[i];
   }
   repp(x,Q){
      if(ans.find(x)!=ans.end())cout<<ans[x]<<" ";
      else cout<<n<<" ";
   }
   cout<<nl;
}
 
