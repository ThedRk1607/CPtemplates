
struct manacher{
	vector<int>p;
	void run_manacher(string s){
		int n=s.length();
		p.assign(n,1);
		int l=1,r=1;
		for(int i=1;i<n;i++){
			p[i]=max(0ll,min(r-i,p[l+r-i]));
			while(i+p[i]<n and i-p[i]>=0 and s[i+p[i]]==s[i-p[i]])
				p[i]++;
			if(i+p[i]>r){
				l=i-p[i];
				r=i+p[i];
			}

		}
		
	}
	void build(string s){
		string t;
		for(auto v:s)t+=string("#")+v;
			run_manacher(t+'#');
	}
	int getLongest(int cent,bool odd){
		int pos=2*cent+1+(!odd);
		return p[pos]-1;
	}
	bool checkPalind(int l,int r){
		if((r-l+1)<=getLongest((l+r)/2,l%2==r%2))return 1;
		else return 0;
	}
				
}m;

//longest palindromic substring
void solve(){
	string s;cin>>s;
	m.build(s);
	int n=s.length(),len=1,idx=0,odd=1;
	for(int i=0;i<n;i++){
		int t1=m.getLongest(i,1);
		if(t1>len){
			len=t1;
			idx=i;odd=1;
		}
		int t2=m.getLongest(i,0);
		if(t2>len){
			len=t2;
			idx=i;odd=0;
		}
	}
	if(odd){
		int h=(len-1)/2;
		cout<<s.substr(idx-h,len)<<nl;
	}else{
		int h=len/2;
		cout<<s.substr(idx-h+1,len)<<nl;

	}

}
