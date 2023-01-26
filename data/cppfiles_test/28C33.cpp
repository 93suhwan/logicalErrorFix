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
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[(i + n - a[i]) % n]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int k = n - b[i];
      if (k % 2 && (k - 3) / 2 + 2 > m) continue;
      if (k % 2 == 0 && k > 2 * m) continue;
      vector<int> a1(n + 1), v(n + 1);
      for (int j = 1; j <= n; j++) {
        a1[j] = a[j];
        v[j] = (j + n - i) % n;
        if (!v[j]) v[j] = n;
      }
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        while (a1[j] != v[j]) {
          int idx = (a1[j] + i) % n;
          if (!idx) idx = n;
          swap(a1[j], a1[idx]);
          cnt++;
        }
      }
      if (cnt <= m) ans.push_back(i);
    }
    cout << ans.size() << ' ';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }
}
