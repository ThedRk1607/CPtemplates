//valid pts bitween circle r to r+1 in circle pb-1971F - Circle Perimeter
void solve(){
	int r;cin>>r;
	int ht=r;
	int ans=0;
	for(int i=0;i<=r;i++){
		while(i*i+ht*ht>=(r+1)*(r+1))ht--;
		int cop=ht;
		while(i*i+cop*cop>=r*r and cop>0){
			cop--;
			ans++;
		}

	}
	cout<<ans*4<<nl;
}

