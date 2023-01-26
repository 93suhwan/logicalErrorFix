#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> a[i][j];
  }
  bool ok = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      long long first = 0, second = 0, both = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i] == 1 && a[k][j] == 1)
          both++;
        else if (a[k][i] == 1)
          first++;
        else if (a[k][j] == 1)
          second++;
      }
      long long needF = n / 2 - first, needS = n / 2 - second;
      if (needF >= 0 && needS >= 0 && both == needF + needS) {
        ok = 1;
        break;
      }
    }
    if (ok == 1) break;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
