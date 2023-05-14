//Recursive ;
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
//iterative;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//inverse storing;

int inv(int i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}

inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = m - (long long)(m/i) * inv[m%i] % m;
    
    
