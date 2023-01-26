#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      int ans = INT_MAX;
      for (int d = 1; d <= 9; d++) {
        int cur = 0;
        while (cur < n) {
          cur = cur * 10 + d;
        }
        ans = min(ans, cur);
      }
      cout << ans << '\n';
    } else {
      string s = to_string(n);
      vector<int> v{s[0] - '0'};
      for (int i = 1; i < s.size(); i++) {
        if (v.back() != s[i] - '0') {
          v.push_back(s[i] - '0');
          if (s[i] - '0' != 9) v.push_back(s[i] - '0' + 1);
          break;
        }
      }
      int d = s.size();
      int ans = INT_MAX;
      for (int a : v) {
        for (int b : v) {
          for (int msk = 0; msk < (1 << d); msk++) {
            int cur = 0;
            for (int i = d - 1; i >= 0; i--) {
              if ((1 << i) & msk) {
                if (cur == 0) {
                  if (a == 0) {
                    cur = INT_MIN;
                    break;
                  }
                }
                cur = cur * 10 + a;
              } else {
                if (cur == 0) {
                  if (b == 0) {
                    cur = INT_MIN;
                    break;
                  }
                }
                cur = cur * 10 + b;
              }
            }
            if (cur >= n) {
              ans = min(ans, cur);
            }
          }
        }
      }
      cout << ans << '\n';
    }
  }
  exit(EXIT_SUCCESS);
}
