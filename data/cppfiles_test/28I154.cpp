#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 987654321;
const long long LINF = 1234567890123456789LL;
const double PI = acos(-1);
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[(i + n - x) % n]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int k = n - a[i];
      if (k & 1) {
        if ((k - 3) / 2 + 2 <= m) ans.push_back(i);
      } else {
        if (k <= 2 * m) ans.push_back(i);
      }
    }
    cout << ans.size() << ' ';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }
}
