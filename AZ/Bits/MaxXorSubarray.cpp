#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
 
        int const max_value = 1 << 8;
        vector<char> has_pref(max_value);
        has_pref[0] = true;
        int cur_xor = 0;
        int ans = 0;
        for (auto i : a) {
            cur_xor ^= i;
            for (int pref = 0; pref < max_value; ++pref) {
                if (has_pref[pref]) {
                    ans = max(ans, pref ^ cur_xor);
                }
            }
            has_pref[cur_xor] = true;
        }
 
        cout << ans << '\n';
    }
}
