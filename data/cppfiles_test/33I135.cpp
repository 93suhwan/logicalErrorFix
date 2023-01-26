#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    long long n, ans;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long m = max_element(v.begin(), v.end()) - v.begin();
    if (m != n - 1 && m > 0) ans = v[m] * max(v[m - 1], v[m + 1]);
    if (m == 0) ans = v[m] * v[m + 1];
    if (m == n - 1) ans = v[m] * v[m - 1];
    cout << ans << "\n";
  }
  return 0;
}
