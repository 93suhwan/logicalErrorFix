#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> p(n);
    for (int i = 1; i <= n; i++) {
      int tmp = (2 * n + i - a[i]) % n;
      p[tmp]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (n - p[i] <= 2 * m) ans.emplace_back(i);
    }
    cout << ans.size() << " ";
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
  }
  return 0;
}
