#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 5;
const long long mod = 1000000000 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int s, n, k;
    cin >> s >> n >> k;
    if (k > n)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
