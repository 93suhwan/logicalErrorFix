#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = (long long int)1e9;
const double eps = 1e-9;
const long long int mxm = 1e5 + 5;
const long long int N = 50005;
long long int r[N][5];
long long int better(long long int i, long long int j) {
  long long int cnt = 0;
  for (long long int k = 0; k < 5; k++) {
    cnt += (r[i][k] < r[j][k]);
  }
  return (cnt >= 3);
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 5; j++) {
      cin >> r[i][j];
    }
  }
  long long int best = 0;
  for (long long int i = 1; i < n; i++) {
    if (better(i, best)) {
      best = i;
    }
  }
  bool ok = 1;
  for (long long int i = 0; i < n; i++) {
    if (i == best) continue;
    ok &= (better(best, i));
  }
  if (!ok) {
    best = -2;
  }
  cout << best + 1 << "\n";
}
signed main() {
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
