#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 2 << "\n";
    return;
  }
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0 and a[i + 1] == 1) {
      for (long long j = 1; j <= i + 1; j++) cout << j << " ";
      cout << n + 1 << " ";
      for (long long j = i + 2; j <= n; j++) cout << j << " ";
      cout << "\n";
      return;
    }
  }
  if (a[n - 1] == 0 and a[0] == 1) {
    cout << n << " " << n + 1 << " ";
    for (long long i = 1; i <= n - 1; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  cout << -1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15) << fixed;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
