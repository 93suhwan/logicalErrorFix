#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int MOD = 1000000007;
double eps = 1e-12;
void solve();
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  string visited = "";
  for (int i = 0; i < n; i++) visited += "f";
  sort(v.begin(), v.end());
  long long int ans = 0;
  for (int i = 0; i < n - 2 * k; i++) ans += v[i];
  for (int i = n - 2 * k; i < n - k; i++) {
    ans += floor(v[i] / v[i + k]);
  }
  cout << ans << endl;
}
