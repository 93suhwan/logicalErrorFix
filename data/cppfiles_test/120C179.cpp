#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 50;
const long long maxn = 5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long t, l, r;
long long ps[25][MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  for (int i = 1; i <= MAXN; i++) {
    for (int j = 0; j < 20; j++) {
      if (i >> j & 1) {
        ps[j][i] = ps[j][i - 1] + 1;
      } else {
        ps[j][i] = ps[j][i - 1];
      }
    }
  }
  while (t--) {
    cin >> l >> r;
    long long mx = -1;
    for (int i = 0; i < 20; i++) mx = max(mx, (ps[i][r] - ps[i][l - 1]));
    cout << (r - l + 1) - mx << endl;
  }
  return 0;
}
