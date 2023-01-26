#include <bits/stdc++.h>
using namespace std;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int32_t main() {
  fastio();
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t s, n, k;
    cin >> s >> n >> k;
    if (s == k or s < (n / k) * k + n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
