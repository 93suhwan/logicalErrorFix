#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &x : a) cin >> x;
    int64_t sum = accumulate(a.begin(), a.end(), 0LL);
    int64_t c1 = count(a.begin(), a.end(), 1);
    int64_t c0 = count(a.begin(), a.end(), 0);
    if (sum == 0) {
      cout << "0\n";
    } else {
      int64_t ans = c1;
      for (int i = 0; i < c0; ++i) ans *= 2LL;
      cout << ans << '\n';
    }
  }
}
