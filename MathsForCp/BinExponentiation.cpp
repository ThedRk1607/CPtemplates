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
//
inline ll gcd(ll a,ll b){
	if(a and b)while((a%=b) and (b%=a));
	return a^b;
}
inline ll exp(ll b, ll p, ll m) {
	ll r=1;
	while(p) {
		if(p&1)
			r=(__int128)r*b%m;
		b=(__int128)b*b%m;
		p/=2;
	}
	return r;
}

inline void add(int &a, int b) {
  a += b;
  if (a >= m) a -= m;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += m;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % m);
}

inline int inv(int a) {
  a %= m;
  if (a < 0) a += m;
  int b = m, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += m;
  return u;
}

    
