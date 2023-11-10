

const int N=2e6;
const int base=31;
 const int mod=1e9+7;

int add(int a,int b){
	int res=(a+b)%mod;
	if(res<0)
		res+=mod;
	return res;
}

int mul(int a,int b){
	int res=(a*1LL*b)%mod;
	if(res<0)
		res+=mod;
	return res;
}

int power(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a);
		b/=2;
	}
	return res;
}

int pw[N],inv[N],Hash[N];
void precal(){
	pw[0]=1;
	for(int i=1;i<N;i++)
		pw[i]=mul(pw[i-1],base);
	int pw_inv=power(base,mod-2);
	inv[0]=1;
	for(int i=1;i<N;i++){
		inv[i]=mul(inv[i-1],pw_inv);
	}
}

void build(string s){
		int n=s.size();
		for(int i=0;i<n;i++){
			Hash[i]=add((i==0) ? 0 : Hash[i-1],mul(pw[i],s[i]-'a'+1));
			
		}
	}

int get_hash(int x,int y){
	int res=add(Hash[y],(x==0)?0:-Hash[x-1]);
	res=mul(res,(x==0)?1:inv[x-1]);
	return res;
}


///Template other
//Q finding Period of cses;
const int mod=1e9+7;
struct Hash
{
	int n;
	vector<ULL> XP,H;
	void init(const string& s, ULL x)
	{
		n=s.size(),XP.resize(n+1),H.resize(n+1);
		XP[0]=1;
		for(int i=1;i<=n;i++) XP[i]=XP[i-1]*x;
		H[n]=0;
		for(int i=n-1;i>=0;i--) H[i]=(s[i]+x*H[i+1]);
	}
	ULL c_hash(int l,int r) const { return (H[l]-H[r]*XP[r-l]); }
};
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	string s;
	Hash H;
	cin>>s,H.init(s,123);
	int len=s.size();
	for(int i=1;i<=len;i++)
	{
		int c=len/i,l=len%i;
		if(l!=0 && H.c_hash(0,l)!=H.c_hash(c*i,len))
			continue;
		if(c!=1 && H.c_hash(0,i*(c-1))!=H.c_hash(i,i*c))
			continue;
		cout<<i<<" ";
	}
	return 0;
}


