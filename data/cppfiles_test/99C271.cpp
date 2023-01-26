#include <bits/stdc++.h>
using namespace std;
int dt[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const long long N = 1e6 + 6;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long T;
  cin >> T;
  while (T--) {
    long long x, n;
    cin >> x >> n;
    long long ans;
    if (x & 1) {
      long long k = n % 4;
      long long cnt = n / 4;
      if (4 * cnt != n) ++cnt;
      long long num = 4 * cnt - 3;
      if (k == 1)
        ans = x + num;
      else if (k == 2)
        ans = x - 1;
      else if (k == 3)
        ans = x - cnt * 4;
      else if (k == 0)
        ans = x;
    } else {
      long long k = n % 4;
      long long cnt = n / 4;
      if (4 * cnt != n) ++cnt;
      long long num = 4 * cnt - 3;
      if (k == 1)
        ans = x - num;
      else if (k == 2)
        ans = x + 1;
      else if (k == 3)
        ans = x + n + 1;
      else if (k == 0)
        ans = x;
    }
    cout << ans << endl;
  }
}
