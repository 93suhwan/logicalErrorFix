#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b + 2 > n)
      cout << -1 << '\n';
    else {
      vector<int> ans(n);
      iota(ans.begin(), ans.end(), 1);
      int i = a > b ? n - 1 : 0;
      int j = a > b ? -2 : 2;
      int k = a > b ? -1 : 1;
      int x = max(a, b);
      while (x--) {
        swap(ans[i], ans[i + k]);
        i += j;
      }
      if (a == b) swap(ans[i], ans[i + k]);
      for (auto &i : ans) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
