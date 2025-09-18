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
 
int f(int n) {
    int p = 1;
    while (p <= n) p <<= 1;  // find next power of 2
    return p - 1;
}

int f2(int L, int R) {
    int d = L ^ R;
    if (d == 0) return L; // all numbers same
    int msb = 32 - __builtin_clz(d); // position of highest differing bit
    return R | ((1 << msb) - 1);
}
