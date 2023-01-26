#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
int n, m, t, k;
template <class T, class U>
T qpow(T a, U b) {
  T ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    auto check = [&](int d) -> bool {
      auto tv = v;
      for (int i = n - 1; i >= 2; i--) {
        if (tv[i] < d) return 0;
        int dif = tv[i] - d;
        int d = min(v[i] / 3, dif / 3);
        tv[i] -= 3 * d;
        tv[i - 1] += d;
        tv[i - 2] += 2 * d;
      }
      if (tv[0] < d || tv[1] < d) return 0;
      return 1;
    };
    int l = 1, r = *max_element(v.begin(), v.end());
    int ans = 1, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (check(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
