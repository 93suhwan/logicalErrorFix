#include <bits/stdc++.h>
using namespace std;
void _out() { cerr << '\n'; }
template <typename H, typename... T>
void _out(H h, T... t) {
  cerr << ' ' << h;
  _out(t...);
}
void solve();
void init();
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  long long T = 1;
  cin >> T;
  init();
  while (T--) {
    solve();
  }
  return 0;
}
long long const N = 20;
long long a[N];
long long ten[N];
void init() {
  long long t = 1;
  for (long long i = 0; i < N; i++) {
    ten[i] = t;
    t *= 10;
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  k++;
  for (long long i = 0; i < n; i++) {
    if (i != n - 1 && k >= ten[a[i + 1] - a[i]] - 1) {
      ans += (ten[a[i + 1] - a[i]] - 1) * ten[a[i]];
      k -= ten[a[i + 1] - a[i]] - 1;
    } else {
      ans += k * ten[a[i]];
      break;
    }
  }
  cout << ans << '\n';
}
