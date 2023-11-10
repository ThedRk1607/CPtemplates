

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
