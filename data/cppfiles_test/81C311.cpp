#include <bits/stdc++.h>
using namespace std;
const long long MOD2 = 998244353;
const long long MOD = 1e9 + 7;
const long long MAX = 1e5 + 7;
const long long inf = 1e18L + 5;
const double pi = 3.14159265358979323846;
long long fpow(long long n, long long m) {
  long long res = 1;
  while (m > 0) {
    if (m & 1) {
      res *= n;
    }
    m /= 2;
    n *= n;
  }
  return res;
}
long long modInv(long long n) { return fpow(n, MOD - 2); }
const long long nax = 1e5 + 5;
void solve() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  long long sum[n + 1];
  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + pow(-1, i) * (s[i] == '+' ? 1 : -1);
  }
  long long l, r, diff;
  for (long long i = 0; i < q; i++) {
    cin >> l >> r;
    diff = abs(sum[r] - sum[l - 1]);
    if (diff == 0)
      cout << 0 << "\n";
    else if (diff & 1)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
  return 0;
}
