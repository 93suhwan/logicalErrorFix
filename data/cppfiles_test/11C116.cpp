#include <bits/stdc++.h>
using namespace std;
bool DEB = 0;
void __start__() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
mt19937_64 rnd(time(0));
using ll = long long;
using vi = vector<long long>;
using ld = long double;
using pii = pair<long long, long long>;
void test_case() {
  long long n;
  cin >> n;
  vector<vi> a(n, vi(5));
  vi c(n);
  for (long long i = 0; i < n; ++i) {
    string s;
    cin >> s;
    c[i] = (long long)s.size();
    for (char j : s) ++a[i][j - 'a'];
  }
  long long ans = 0;
  for (long long col = 0; col < 5; ++col) {
    vi b(n);
    for (long long i = 0; i < n; ++i) {
      b[i] = a[i][col] - (c[i] - a[i][col]);
    }
    sort(b.rbegin(), b.rend());
    if (b[0] < 0) continue;
    long long sum = b[0];
    for (long long i = 1; i < n && sum > 0; ++i) {
      ans = max(ans, i);
      sum += b[i];
    }
    if (sum > 0) ans = n;
  }
  cout << ans << '\n';
}
signed main() {
  __start__();
  long long Q = 1;
  cin >> Q;
  while (Q--) test_case();
}
