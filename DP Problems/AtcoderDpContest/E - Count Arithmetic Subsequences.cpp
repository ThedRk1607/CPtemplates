#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b)for(int i=a;i<b;i++)
#define repp(x,arr) for(auto& x:arr)

#define ll              long long
#define ull              unsigned long long 
#define int ll
#define db              double
#define pb              push_back
#define all(v)             v.begin(),v.end()
#define F               first
#define S               second
#define mod             998244353
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define nl              "\n"
#define PI              3.1415926536
#define eps 0.00000001
#define mpp             make_pair
#define lb              lower_bound
#define ub              upper_bound
#define PQ              priority_queue<int> 
#define RS              set <ll, greater <ll> >
#define PQS             priority_queue<pll,vector<pll>,greater<pll>> 
#define ZERO(a)         memset(a,0,sizeof(a))
#define inf             0x3f3f3f3f

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;

template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
template <typename A, typename B> A mod1 (A &a, B b){ a=(a%b+b)%b ; return a; }

int dp[81][81][81];
vi v;

int add(int a, int b) {
    return (a % mod + b % mod) % mod;
}

int countProgressions(int i, int j, int l, int n) {
    // Base case: if the length is exactly 2, return 1 because we can form a progression of length 2
    if (l == 2) {
        return 1;
    }

    // Memoization: return already calculated value
    if (dp[i][j][l] != -1) {
        return dp[i][j][l];
    }

    // Initialize the current state
    dp[i][j][l] = 0;

    // Try to extend the progression by finding a valid next element `k`
    for (int k = j + 1; k < n; ++k) {
        if (v[k] - v[j] == v[j] - v[i]) {
            dp[i][j][l] = add(dp[i][j][l], countProgressions(j, k, l - 1, n));
        }
    }

    return dp[i][j][l];
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    repp(x, v) cin >> x;

    // Initialize dp array with -1 (to indicate uncomputed states)
    memset(dp, -1, sizeof(dp));

    vi res(n + 1, 0);
    res[1] = n; // Every element itself forms a sequence of length 1

    // Calculate results using recursive DP
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = 2; l <= n - i; ++l) {
                res[l] = add(res[l], countProgressions(i, j, l, n));
            }
        }
    }

    rep(i, 1, n + 1) cout << res[i] << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1; //cin >> T;
    while (T--) solve();

    return 0;
}
