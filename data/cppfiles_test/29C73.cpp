#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
int power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n, k, i, m;
  cin >> n;
  vector<long long> v(n);
  long long f = 0, cnt = 0;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> v[i];
    if (v[i] == 0) cnt++;
    if (v[i] == 1) f++;
  }
  long long res = f * powl(2, cnt);
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  long long n, x;
  while (t--) {
    solve();
  }
  return 0;
}
