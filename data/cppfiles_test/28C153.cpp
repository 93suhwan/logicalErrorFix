#include <bits/stdc++.h>
using namespace std;
const long long nax = 2002;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int q = n - 2 * m;
    vector<int> vote(n), a(n), may, ans, b;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i]--;
      int k = i - a[i];
      if (k < 0) k += n;
      vote[k]++;
    }
    for (int i = 0; i < n; ++i) {
      if (vote[i] >= q) may.push_back(i);
    }
    for (auto& x : may) {
      b = a;
      for (auto& y : b) {
        y += x;
        if (y >= n) y -= n;
      }
      int cnt = n;
      vector<int> used(n);
      for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        cnt--;
        int j = b[i];
        while (j != i) {
          used[j] = 1;
          j = b[j];
        }
      }
      if (cnt <= m) {
        ans.push_back(x);
      }
    }
    cout << ans.size() << ' ';
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
  }
}
