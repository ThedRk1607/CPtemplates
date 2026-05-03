int p[N],vis[N],pa[N];

void solve(){
 int n;cin>>n;
 rep(i,0,n){cin>>pa[i];pa[i]--;p[pa[i]]++;}
 queue<int>q;rep(i,0,n)if(!p[i])q.push(i);

 int ans=0;vi dp(n+5,1);
 while(!q.empty()){
  auto u=q.front();q.pop();ans+=dp[u];
  int v=pa[u];dp[v]+=dp[u];p[v]--;
  if(p[v]==0)q.push(v);
 }

 for(int i=0;i<n;i++){
   if(!p[i])continue;
   int x=0,u=i,cur=0;
   while(p[u]){x++;cur+=dp[u];p[u]=0;u=pa[u];}
   ans+=x*cur;
 }
 cout<<ans;
}
