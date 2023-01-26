#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long INF = 2147483647;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const long long pi = 3.1415926;
long long n;
long long st[N];
void solve() {
  cin >> n;
  memset(st, 0, sizeof st);
  long long k = sqrt(n), q = 0;
  for (long long i = 1; i <= n / i; i++) {
    if (i * i * i <= n) st[q++] = i * i * i;
  }
  for (long long i = 0; i < q; i++) {
    long long t = sqrt(st[i]);
    if (t * t == st[i]) k--;
  }
  cout << k + q << '\n';
}
signed main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return ~~(0 ^ 0 ^ 0);
}
