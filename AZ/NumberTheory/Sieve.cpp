
std::vector<int> minp, primes, ps;
//minp[i]=smallest prime factor of i
//ps[i]=count of prime factors counted as multiplicity (36-> 2^2.3^2 then ps[36]=2+2);

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    ps.resize(n + 1);
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        ps[i] = ps[i / minp[i]] + 1;
    }
}
