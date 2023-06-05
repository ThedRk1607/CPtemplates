

int mon[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,ans;
int day[510],month[15];

void solve(){
	cin>>n;
	int l=0,r=0;

	for(int i=1;i<=12;i++)
		month[i]=month[i-1]+mon[i];

	for(int i=1;i<=n;i++){
		int m,d,p,t;
		cin>>m>>d>>p>>t;
		m--;
		r=month[m]+d+100;
		l=r-t;
		for(int j=l;j<r;j++){
			day[j]+=p;
			amax(ans,day[j]);
		}
	}

	cout<<ans<<nl;


}


	
