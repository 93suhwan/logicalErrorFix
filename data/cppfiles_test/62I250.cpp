#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i <= n - 1; i++) cin >> a[i];
  if (*min_element(a.begin(), a.end()) == 1)
    cout << -1;
  else {
    long long k;
    for (long long i = n - 1; i >= 0; i--) {
      if (!a[i]) {
        k = i;
        break;
      }
    }
    for (long long i = 0; i <= k; i++) cout << i + 1 << ' ';
    cout << n + 1 << ' ';
    for (long long i = k + 1; i <= n - 1; i++) cout << i + 1 << ' ';
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
