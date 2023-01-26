#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int mod = 1e9 + 7;
int n, m, a[MAXN];
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = a[1];
    for (int i = 1; i <= n; ++i) ans = ans & a[i];
    cout << ans << endl;
  }
  return 0;
}
