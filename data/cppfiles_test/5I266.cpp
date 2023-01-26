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
    for (int j = 0; j < n; j++) {
      if (s1[j] == 48 && s2[j] == 49) {
        res++;
        s1[j] = 0;
        s2[j] = 0;
      }
    }
    if (s1[0] != 48) {
      if (s2[1] == 49) {
        res++;
        s2[1] = 0;
      }
    }
    for (int j = 1; j < n - 1; j++) {
      if (s1[j] == 49) {
        if (s2[j - 1] != 48) {
          res++;
          s2[j - 1] = 0;
        } else if (s2[j + 1] != 48) {
          res++;
          s2[j + 1] = 0;
        }
      }
    }
    if (s1[n - 1] != 48) {
      if (s2[n - 2] == 49) {
        res++;
        s2[n - 2] = 0;
      }
    }
    cout << res << endl;
  }
}
