int f(int m,int n){
	int ans=0;
	for(int bit=61;bit>=0;bit--){
		if((m&(1LL<<bit))!=(n&(1LL<<bit)))break;
		else {
			ans|=(m&(1LL<<bit));
		}
	}
	return ans;
}
 
