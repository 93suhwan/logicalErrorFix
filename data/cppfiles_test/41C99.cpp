#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  int cur = 1, ans = 0;
  while (cur < n) ++ans, cur *= k;
  cout << ans << endl;
  for (int al = 1; al <= n; al++)
    for (int be = al + 1; be <= n; be++) {
      cur = 1, ans = 0;
      while ((al - 1) / cur != (be - 1) / cur) cur *= k, ++ans;
      cout << ans << " ";
    }
  cout << endl;
  return 0;
}
