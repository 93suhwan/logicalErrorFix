#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
inline void solve() {
  string u, v;
  long long n;
  cin >> n;
  cin >> u >> v;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (u[i] != v[i])
      ans += 2;
    else {
      if ((u[i] + u[i + 1] == v[i] + v[i + 1]) && i + 1 < n) {
        ans += 2;
        i++;
      } else {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
