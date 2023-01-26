#include <bits/stdc++.h>
using namespace std;
int main() {
  int t1;
  cin >> t1;
  while (t1--) {
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      input.push_back(u);
    }
    int t, x, ans;
    t = 1;
    x = 1;
    ans = 0;
    while (x <= n) {
      if (input[x - 1] <= t) {
        x++;
        t++;
        continue;
      }
      ans = ans + input[x - 1] - t;
      t = input[x - 1] + 1;
      x++;
    }
    cout << ans << endl;
  }
  return 0;
}
