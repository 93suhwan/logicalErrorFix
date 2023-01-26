#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
int i;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 + (a[0] ? 1 : 0) << "\n";
  } else {
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        if (a[i] == 1) {
          if (a[i - 1] == 0) {
            ans++;
          } else {
            ans += 5;
          }
        } else {
          if (a[i - 1] == 0) {
            ans = -1;
            break;
          }
        }
      } else {
        ans += a[i];
      }
    }
    cout << ans << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
