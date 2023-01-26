#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    set<int> ans;
    {
      int x = (n + 1) / 2;
      int y = n / 2;
      int init = 0;
      if (x > a) {
        int diff = x - a;
        init += diff;
        x -= diff;
        y += diff;
      } else if (a > x) {
        int diff = a - x;
        init += diff;
        x += diff;
        y -= diff;
      }
      ans.insert(init);
      for (int i = 1; i <= min(x, y); ++i) {
        ans.insert(init + 2 * i);
      }
    }
    {
      int y = (n + 1) / 2;
      int x = n / 2;
      int init = 0;
      if (x > a) {
        int diff = x - a;
        init += diff;
        x -= diff;
        y += diff;
      } else if (a > x) {
        int diff = a - x;
        init += diff;
        x += diff;
        y -= diff;
      }
      ans.insert(init);
      for (int i = 1; i <= min(x, y); ++i) {
        ans.insert(init + 2 * i);
      }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }
}
