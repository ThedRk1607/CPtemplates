int n,m;
struct trie{
   trie*child[12];int cnt;
   trie(){
      rep(i,0,12)child[i]=NULL;cnt=0;
   }
};

void insert(vi &v,trie*root) {
        trie* node = root;
        for (auto idx:v) {
            if (!node->child[idx]) {
                node->child[idx] = new trie();
            }
            node = node->child[idx];
            node->cnt++; // Increment the count of strings passing through this node
        }
    }

int lcp(vi v,trie*root){
   int ans=0;trie*cur=root;
   repp(x,v){
      if(!cur->child[x] or !cur->child[x]->cnt)break;
      ans++;cur=cur->child[x];
   }
   return ans;
}

void solve(){
   cin>>n>>m;
 trie*T=new trie();
 vi P[n+1];
 rep(i,0,n){
   P[i].resize(m);
   rep(j,0,m)cin>>P[i][j];
   vi v=P[i];
   map<int,int>id;
   rep(j,0,m)id[v[j]]=j+1;
   vi tmp;
   rep(i,1,m+1)tmp.pb(id[i]);
   insert(tmp,T);
 }
 rep(i,0,n){
   vi v=P[i];
   int ans=lcp(v,T);
 cout<<ans<<" ";
 }
 cout<<nl;
 

 

}
