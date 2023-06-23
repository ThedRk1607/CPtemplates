
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int d, g;
  cin >> d >> g;
  g /= 100;
  vector<int> p(d), c(d);
  for (int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
    c[i] /= 100;
  }
  int ans = 1e9;
  for (int i = 0; i < 1 << d; i++) {
    int cnt = 0;
    int score = 0;
    for (int j = 0; j < d; j++) {
      if (i >> j & 1) {
        cnt += p[j];
        score += p[j] * (j + 1);
        score += c[j];
      }
    }
    for (int j = d - 1; j >= 0; j--) {
      if (~i >> j & 1) {
        for (int k = 0; k < p[j] && score < g; k++) {
          score += j + 1;
          cnt++;
        }
      }
    }
    if (score >= g) {
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}
