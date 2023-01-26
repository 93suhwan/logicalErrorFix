#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int ck(long long int a[], long long int n) {
  for (long long int i = 1; i < n; i++)
    if (a[i] < a[i - 1]) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int ans = 0, p = 0;
    while (!ck(a, n)) {
      if (p == 0) {
        for (long long int j = 0; j < n - 1; j += 2) {
          if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
      } else {
        for (long long int j = 1; j < n - 1; j += 2) {
          if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
      }
      p ^= 1;
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
