#include <cstdio>
#define int long long
int T, n, k;
signed main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &n, &k);
		k--;
		if(n < 62 && k >= (1ll << (n-1))) {
			puts("-1");
			continue;
		}
		for(int i = 1, j = 1; i <= n; i = j+1, j = i) {
			while(j < n && n-j <= 62 && (k & (1ll << (n-j-1)))) j++;
			for(int k = j; k >= i; k--) printf("%lld ", k); 
		}
		puts("");
	}
	return 0;
}
