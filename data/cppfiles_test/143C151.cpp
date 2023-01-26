#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MOD = 998244353;
const int N = 2e5 + 5;
int t, n, a[N], f[N];
vector<int> p;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; ++i) f[i] = 0;
    p.clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      f[a[i]]++;
    }
    long long res = 0;
    int pos = n;
    for (int i = 0; i <= n; ++i) {
      int ans = f[i];
      cout << ans + res << ' ';
      if (f[i] == 0) {
        if (p.empty()) {
          pos = i;
          break;
        } else {
          res += i - p.back();
          p.pop_back();
        }
      }
      for (int j = 1; j <= f[i] - 1; ++j) p.push_back(i);
    }
    for (int i = pos + 1; i <= n; ++i) cout << -1 << ' ';
    cout << '\n';
  }
}
