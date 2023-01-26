#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
void solve() {
  long long n;
  cin >> n;
  long long oo = 0, oz = 0, zo = 0, zz = 0;
  string a, b;
  cin >> a >> b;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '1' && b[i] == '0') {
      oz++;
    }
    if (a[i] == '1' && b[i] == '1') {
      oo++;
    }
    if (a[i] == '0' && b[i] == '1') {
      zo++;
    }
    if (a[i] == '0' && b[i] == '0') {
      zz++;
    }
  }
  long long ans = INF;
  if (oz == zo) {
    ans = min(ans, oz + zo);
  }
  if (oo == zz + 1) {
    ans = min(ans, oo + zz);
  }
  if (ans == INF) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
