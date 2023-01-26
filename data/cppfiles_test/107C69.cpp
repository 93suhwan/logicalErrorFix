#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1000000000000000000;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> ans;
    vector<long long> p;
    for (long long i = 1; i < n + 1; i += 1) p.push_back(i);
    if (abs(a - b) > 1 || (a + b) > (n - 2))
      cout << "-1"
           << "\n";
    else {
      long long x = 0, y = 0;
      if (a > b) {
        while (a != 0) {
          ans.push_back(p[0 + y]);
          ans.push_back(p[n - 1 - x]);
          y++;
          x++;
          a--;
          b--;
        }
        for (long long i = n - 1 - x; i >= y; i--) ans.push_back(p[i]);
      } else if (a < b) {
        while (b != 0) {
          ans.push_back(p[n - 1 - x]);
          ans.push_back(p[0 + y]);
          y++;
          x++;
          a--;
          b--;
        }
        for (long long i = y; i <= n - 1 - x; i++) ans.push_back(p[i]);
      } else {
        ans.push_back(1);
        y++;
        while (a != 0) {
          ans.push_back(p[n - 1 - x]);
          ans.push_back(p[0 + y]);
          y++;
          x++;
          a--;
          b--;
        }
        for (long long i = y; i <= n - 1 - x; i++) ans.push_back(p[i]);
      }
      for (long long i = 0; i < n; i += 1) cout << ans[i] << " ";
      cout << "\n";
    }
  }
}
