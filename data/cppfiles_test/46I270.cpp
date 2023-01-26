#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, m, i, j, q;
  long long a, b;
  cin >> n;
  vector<long long> v(n);
  for (i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  for (i = 0; i < n; i += 2) {
    long long l = 1;
    long long r = v[i];
    for (j = i + 1; j < n; j++) {
      if (j % 2 == 0) {
        l += v[j];
        r += v[j];
      }
      if (j % 2) {
        long long l1 = l;
        long long r1 = r;
        r1 -= 1;
        l1 -= v[j];
        if (l1 <= 0 && r1 >= 0) {
          long long sm = l - 1;
          if (sm < 0) {
            ans += min(v[j], max(0ll, v[i] - abs(sm)));
          } else {
            ans += min(v[i], max(0ll, v[j] - abs(sm)));
          }
        }
        l -= v[j];
        r -= v[j];
      }
      if (l < 0 && r < 0) break;
      l = max(l, 0ll);
    }
  }
  cout << ans << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
