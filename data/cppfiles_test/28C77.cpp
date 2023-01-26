#include <bits/stdc++.h>
#pragma GCC target("sse4.2")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = int(1e9) + 7;
const int INF = 1e9;
const long long LINF = 2e18;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << setprecision(18) << fixed;
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    auto reduce = [&](long long &k) {
      if (k >= 2) {
        k = (k - 3) % 2 + 3;
      }
    };
    reduce(a);
    reduce(b);
    reduce(c);
    vector<int> t;
    for (int i = 0; i < a; i++) t.push_back(1);
    for (int i = 0; i < b; i++) t.push_back(2);
    for (int i = 0; i < c; i++) t.push_back(3);
    if ((int)(t).size() == 0) {
      cout << 0 << "\n";
      continue;
    }
    int res = INT_MAX;
    for (int bit = 0; bit < (1 << (int)(t).size()); bit++) {
      int t1 = 0, t2 = 0;
      for (int i = 0; i < (int)(t).size(); i++) {
        if (bit & (1 << i)) {
          t1 += t[i];
        } else
          t2 += t[i];
      }
      res = min(abs(t1 - t2), res);
    }
    cout << res << "\n";
  }
  return 0;
}
