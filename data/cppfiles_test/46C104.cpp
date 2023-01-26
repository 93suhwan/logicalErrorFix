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
    long long sm = 0;
    long long minb = 0;
    for (j = i + 1; j < n; j++) {
      if (j % 2 == 0) {
        sm += v[j];
        continue;
      }
      if (j % 2) {
        long long ans1 = ans;
        ans += max(0ll, min(v[i], v[j] - sm) - max(1ll, minb) + 1);
        sm -= v[j];
      }
      if (sm < 0) minb = max(minb, abs(sm));
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
