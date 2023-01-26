#include <bits/stdc++.h>
using namespace std;
void aLgOrItHm() {
  long long n, m = 0, ans = 1;
  cin >> n;
  vector<long long> v(n, 0);
  for (size_t i = 0; i < n; ++i) {
    cin >> v[i];
    m = max(m, v[i]);
  }
  long long l = v[n - 1];
  if (l == m) {
    cout << 0 << "\n";
    return;
  }
  for (size_t i = n - 1; i >= 0; --i) {
    if (v[i] == m) {
      break;
    }
    if (v[i] > l and v[i] < m) {
      l = v[i];
      ans++;
    } else {
      continue;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long huehuehue;
  cin >> huehuehue;
  while (huehuehue--) {
    aLgOrItHm();
  }
  return 0;
}
