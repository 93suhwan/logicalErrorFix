#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long h = 1;
  if (a[0] == 1) {
    h++;
  }
  for (long long i = 1; i < n; i++) {
    if (a[i] == 0 && a[i - 1] == 0) {
      cout << -1 << endl;
      return;
    }
    if (a[i] == 1 && a[i - 1] == 0) {
      h++;
    }
    if (a[i] == 1 && a[i - 1] == 1) {
      h += 5;
    }
  }
  cout << h << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
