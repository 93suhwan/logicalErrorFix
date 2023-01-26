#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long P = 239;
const long long inf = 1e18 * 2LL;
const long double eps = 1e-9;
vector<long long> b(100001, 0), c(100001, 0);
inline void solve(void) {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long ans = 0;
  vector<long long> vb, vc;
  for (int i = n - 1; i >= 0; --i) {
    swap(b, c);
    swap(vc, vb);
    vb.push_back(a[i]);
    b[a[i]] = 1;
    for (long long x : vc) {
      long long hm = c[x];
      long long sp = (a[i] + x - 1) / x;
      long long st = a[i] / sp;
      ans = (ans + (i + 1) * hm * (sp - 1)) % MOD2;
      b[st] += hm;
      if (a[i] != st) vb.push_back(st);
    }
    for (long long val : vc) c[val] = 0;
    vc.clear();
  }
  cout << ans << '\n';
  for (long long val : vb) b[val] = 0;
}
int main(void) {
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  srand(time(NULL));
  cin >> t;
  while (t--) solve();
  return 0;
}
