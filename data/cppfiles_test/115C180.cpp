#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<long long> a;
long long n, k;
bool cnt(long long x) {
  long long ans = x;
  for (long long i = 1; i < n; ++i) {
    ans -= max(x - (a[i] - a[i - 1]), (long long)0);
    ans += x;
  }
  return ans >= k;
}
void solve() {
  cin >> n >> k;
  a = vector<long long>(n, 0);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long l = 0;
  long long r = k;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (cnt(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
  return;
}
signed main() {
  fastio();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
