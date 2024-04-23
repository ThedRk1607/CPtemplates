
int freq[1000005];
void solve(){
	int n,k;cin>>n>>k;
	vi v(n);repp(x,v)cin>>x;
		ZERO(freq);
	int tail=0,head=-1; //zero window subarray
	int ans=0, d=0;

	while(tail<n){
		while(head+1<n and (((freq[v[head+1]]==0)+d)<=k || freq[v[head+1]]>=1)){ //check can we eat next elemetn
			head++;
			if(freq[v[head]]==0)d++;
			freq[v[head]]++;
			
		}
		ans+=(head-tail+1);
		if(tail<=head){
			if(freq[v[tail]]==1)d--;
			freq[v[tail]]--;
			tail++;

		}else{
			tail++;
			head=tail-1; //make zero window subarray 
		}
	}
	
	cout<<ans<<nl;


	
  }
  
