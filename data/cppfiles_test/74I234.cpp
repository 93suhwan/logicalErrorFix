#include <bits/stdc++.h>
inline long long int GCD(long long int a, long long int b) {
  return b == 0 ? a : GCD(b, a % b);
}
inline long long int LCM(long long int a, long long int b) {
  return a * b / GCD(a, b);
}
inline long long int ceil(long long int a, long long int b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
const long long int mod = 1e9 + 7;
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int tot = a + b;
  long long int g1 = tot / 2;
  long long int g2 = ceil(tot, 2);
  set<long long int> ans;
  for (long long int i = 0; i <= tot; i++) {
    long long int l = 0, r = i, mid = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((g1 + i - 2 * mid) > b)
        l = mid + 1;
      else if ((g1 + i - 2 * mid) < b)
        r = mid - 1;
      else {
        if ((g2 + 2 * mid - i) == a && (i - mid) <= g2) ans.insert(i);
        break;
      }
    }
    l = 0, r = i, mid = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((g2 + i - 2 * mid) > b)
        l = mid + 1;
      else if ((g2 + i - 2 * mid) < b)
        r = mid - 1;
      else {
        if ((g1 + 2 * mid - i) == a && (i - mid) <= g1) ans.insert(i);
        break;
      }
    }
    l = 0, r = i, mid = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((g2 + i - 2 * mid) > b)
        l = mid + 1;
      else if ((g2 + i - 2 * mid) < b)
        r = mid - 1;
      else {
        if ((g1 + 2 * mid - i) == a && (i - mid) <= g1) ans.insert(i);
        break;
      }
    }
    l = 0, r = i, mid = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if ((g1 + i - 2 * mid) > b)
        l = mid + 1;
      else if ((g1 + i - 2 * mid) < b)
        r = mid - 1;
      else {
        if ((g2 + 2 * mid - i) == a && (i - mid) <= g2) ans.insert(i);
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto &it : ans) cout << it << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
