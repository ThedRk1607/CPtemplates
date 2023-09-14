
const int N=int(1e7)+5;
int mind[N]; //min prime divisor;


void init() {
    FOR(i,0,N)mind[i]=i;
    for(int p=2;p<N;p++){
    	if(mind[p]!=p)continue;
    	for(int d=2*p;d<N;d+=p)amin(mind[d],p);
    }
}

vector<int> get(int n) { //primeFactors;
	vector<int> ret;
	while(n>1){
		if(ret.empty() or ret.back()!=mind[n])ret.pb(mind[n]);
		n/=mind[n];
	}
	return ret;
}

