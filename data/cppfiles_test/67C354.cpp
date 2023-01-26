#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int trans = b - a, tot = 2 * (b - (a - 1) - 1);
    if (a > tot || b > tot || c > tot)
      cout << -1 << '\n';
    else {
      int d = c + trans;
      if (d > tot) d -= tot;
      cout << d << '\n';
    }
  }
  return 0;
}
