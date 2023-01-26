#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int kase;
  cin >> kase;
  while (kase--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long l = 1, r = 1e18, ans = 0;
    auto check = [&](long long mid) {
      long long tmp = 0, lst = 0;
      for (auto &x : a) {
        if (x <= lst) {
          tmp -= lst - x + 1;
          tmp += mid;
          lst = x + mid - 1;
        } else {
          tmp += mid;
          lst = x + mid - 1;
        }
      }
      return tmp >= m;
    };
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
