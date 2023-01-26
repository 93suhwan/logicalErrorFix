#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long P = 239;
const long long inf = 1e18 * 2LL;
const long double eps = 1e-9;
int b[100001], c[100001], a[100001];
inline void solve(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long ans = 0;
  vector<int> vb, vc;
  for (int i = n - 1; i >= 0; --i) {
    if (i & 1) {
      vb.push_back(a[i]);
      b[a[i]] = 1;
      int lst = a[i];
      for (long long x : vc) {
        long long hm = c[x];
        long long sp = (a[i] + x - 1) / x;
        long long st = a[i] / sp;
        ans = (ans + ((long long)i + 1) * hm * (sp - 1)) % MOD2;
        b[st] += hm;
        if (lst != st) vb.push_back(st), lst = st;
      }
      for (long long val : vc) c[val] = 0;
      vc.clear();
    } else {
      vc.push_back(a[i]);
      c[a[i]] = 1;
      int lst = a[i];
      for (long long x : vb) {
        long long hm = b[x];
        long long sp = (a[i] + x - 1) / x;
        long long st = a[i] / sp;
        ans = (ans + ((long long)i + 1) * hm * (sp - 1)) % MOD2;
        c[st] += hm;
        if (lst != st) vc.push_back(st), lst = st;
      }
      for (long long val : vb) b[val] = 0;
      vb.clear();
    }
  }
  cout << ans << '\n';
  for (int val : vb) b[val] = 0;
  for (int val : vc) c[val] = 0;
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
