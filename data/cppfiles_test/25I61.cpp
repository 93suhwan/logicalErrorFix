#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    long long n, m, k, i, j, p, ans = 0, ans1 = 0, ans2 = 0;
    string s, t;
    cin >> s;
    cin >> t;
    n = s.size();
    m = t.size();
    for (i = 0; i < n; i++) {
      for (j = i; j < n; j++) {
        k = 0;
        for (p = i; p <= j; p++) {
          if (s[p] == t[k]) {
            k++;
            if (k == m) {
              ans = 1;
              break;
            }
          } else {
            ans1 = 1;
            break;
          }
        }
        if (ans1 == 0) {
          for (p = j - 1; p >= 0; p--) {
            if (s[p] == t[k]) {
              k++;
              if (k == m) {
                ans = 1;
                break;
              }
            }
          }
        } else
          ans1 = 0;
        if (ans == 1) break;
      }
      if (ans == 1) break;
    }
    if (ans == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
