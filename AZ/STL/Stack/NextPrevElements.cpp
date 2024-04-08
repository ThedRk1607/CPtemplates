
 void solve(){
   int n;cin>>n;
   vi v(n);repp(x,v)cin>>x;
    int psm[n+1];
    stack<int>st;
    rep(i,0,n){
    	int val=i-1;
    	while(!st.empty() and v[st.top()]>=v[i]){
    		st.pop();
    	}
    	if(!st.empty())val=st.top();
    	else val=-1;
    	psm[i]=val;
    	st.push(i);
    }
    rep(i,0,n)cout<<psm[i]+1<<" ";
    cout<<nl;
 }
//without stack
 void solve(){
   int n;cin>>n;
   vi v(n);repp(x,v)cin>>x;
    int psm[n+1];
    rep(i,0,n){
    	int val=i-1;
    	while(val!=-1 and v[val]>=v[i]){
    		val=psm[val];
    	}
    	psm[i]=val;
    }
    rep(i,0,n)cout<<psm[i]+1<<" ";
    cout<<nl;
 }
   
