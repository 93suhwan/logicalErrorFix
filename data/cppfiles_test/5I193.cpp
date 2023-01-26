#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, res;
  string s1, s2;
  cin >> t;
  for (int i = 0; i < t; i++) {
    res = 0;
    cin >> n;
    cin >> s1 >> s2;
    if (s2[0] == 49) {
      res++;
      if (s1[0] == 48)
        s1[0] = 2;
      else
        s1[1] = 2;
    }
    for (int j = 1; j < n - 1; j++) {
      if (s2[j] == 49) {
        if (s1[j - 1] == 49) {
          res++;
          s1[j - 1] = 2;
        } else {
          if (s1[j] == 48) {
            res++;
            s1[j] = 2;
          } else {
            if (s1[j + 1] == 49) {
              res++;
              s1[j + 1] = 2;
            }
          }
        }
      }
    }
    if (s2[n - 1] == 49) {
      if (s1[n - 2] == 49 || s1[n - 1] == 48) res++;
    }
    cout << res << endl;
  }
}
