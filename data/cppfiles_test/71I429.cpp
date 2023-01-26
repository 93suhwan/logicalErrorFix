#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  vector<int> x, y;
  int ans = 1e9;
  for (int a = 0; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      for (int d = 1; d <= 10; d++) {
        for (int msk = 0; msk < (1 << d); msk++) {
          int cur = 0;
          for (int i = d - 1; i >= 0; i--) {
            if ((1 << i) & msk) {
              if (a == 0 && cur == 0) {
                goto H;
              }
              cur = cur * 10 + a;
            } else {
              if (b == 0 && cur == 0) {
                goto H;
              }
              cur = cur * 10 + b;
            }
          }
          x.push_back(cur);
          if (a == b) y.push_back(cur);
        }
      H:;
      }
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << *lower_bound(y.begin(), y.end(), n);
    } else {
      cout << *lower_bound(x.begin(), x.end(), n);
    }
    cout << '\n';
  }
  exit(EXIT_SUCCESS);
}
