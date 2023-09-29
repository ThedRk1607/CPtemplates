const int N=1000;
vector<bool> is_prime(N, true);
vector<int>lp(N),hp(N);//leastPrimefctor,highestPrimeFactor;

void sieve(){
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <N; i++) {
    if (is_prime[i]) {
    	lp[i]=hp[i]=i;
        for (int j = 2 * i; j <N; j += i)
           {
           	 is_prime[j] = false;
           	 hp[j]=i;
           	 if(lp[j]==0)lp[j]=i;
           }
    }
}
}
