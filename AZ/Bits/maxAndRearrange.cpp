
In general case, it means that we have to solve the following subproblem: check if we can obtain 1 in several bits of the answer; 
let these bits be {𝑥1,𝑥2,…,𝑥𝑘} (𝑥1 to 𝑥𝑘−1 are the bits that we have already checked;
𝑥𝑘 is the new bit we are trying to check). Let 𝑚𝑎𝑠𝑘 be the number that has 1 in every bit 𝑥𝑖 and 0 in every other bit.
The elements should be matched in such a way that (𝑎𝑖&𝑚𝑎𝑠𝑘)⊕(𝑏𝑖&𝑚𝑎𝑠𝑘)=𝑚𝑎𝑠𝑘. 
If we group all numbers from 𝑎 and from 𝑏 according to the value of 𝑎𝑖&𝑚𝑎𝑠𝑘 (or 𝑏𝑖&𝑚𝑎𝑠𝑘), 
then for every group of elements from 𝑎, there is a corresponding group in 𝑏 such that we can match the elements from the first group only with the elements from the second group.
  So, if for every such group, its size in 𝑎 is equal to the size of the corresponding group in 𝑏,
  then we can set all bits from {𝑥1,𝑥2,…,𝑥𝑘} to 1 simultaneously.



#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    
    auto check = [&](int ans) {
      map<int, int> cnt;
      for (int x : a) ++cnt[x & ans];
      for (int x : b) --cnt[~x & ans];
      bool ok = true;
      for (auto it : cnt) ok &= it.second == 0;
      return ok;
    };
    
    int ans = 0;
    for (int bit = 29; bit >= 0; --bit) 
      if (check(ans | (1 << bit)))
        ans |= 1 << bit;
    
    cout << ans << '\n';
  }
}
