#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int pow_mod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
long long int inv_mod(long long int a) { return pow_mod(a, mod - 2); }
void solve() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (long long int i = 0; i < n; i++) cin >> a[i + 1];
  long long int mn[512];
  for (long long int i = 0; i < 512; i++) mn[i] = (long long int)1e18;
  mn[0] = 0;
  set<long long int> st;
  for (long long int pos = 1; pos <= n; pos++) {
    for (long long int xr = 0; xr < 512; xr++) {
      long long int rem = xr ^ a[pos];
      if (mn[rem] < a[pos] || (rem == 0 && a[pos] == 0)) {
        st.insert(xr);
        mn[xr] = min(mn[xr], a[pos]);
      }
    }
  }
  vector<long long int> ans;
  for (auto e : st) ans.push_back(e);
  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";
  cout << endl;
}
int main() {
  long long int t;
  t = 1;
  while (t--) solve();
  return 0;
}
