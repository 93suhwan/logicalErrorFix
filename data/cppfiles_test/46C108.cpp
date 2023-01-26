#include <bits/stdc++.h>
using namespace std;
const signed long long MOD = 1e9 + 7;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
signed long long n;
signed long long c[1001];
pair<signed long long, signed long long> intersect(
    pair<signed long long, signed long long> a,
    pair<signed long long, signed long long> b) {
  if (a.first > b.second || b.first > a.second) return {1, 0};
  return {max(a.first, b.first), min(a.second, b.second)};
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (signed long long i = 1; i <= n; i++) cin >> c[i];
  signed long long ans = 0;
  signed long long open;
  signed long long close = 0;
  for (signed long long i = 1; i <= n; i += 2) {
    open = close = 0;
    signed long long ok = 1;
    for (signed long long j = i + 1; j <= n; j++) {
      if (j & 1)
        open += c[j];
      else {
        signed long long d = open - close;
        pair<signed long long, signed long long> use =
            intersect({1, c[j]}, {d + ok, d + c[i]});
        if (use.second >= use.first) ans += use.second - use.first + 1;
        close += c[j];
        ok = max(ok, close - open);
        if (ok > c[i]) break;
      }
    }
  }
  cout << ans << "\n";
}
