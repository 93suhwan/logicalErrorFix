#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int a[3], m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a, a + 3);
    bool f = (m <= a[0] + a[1] + a[2] - 3);
    f &= (m >= max(0, (max(0, a[2] - a[1] - 1) - a[0])));
    cout << (f ? "YES\n" : "NO\n");
  }
}
