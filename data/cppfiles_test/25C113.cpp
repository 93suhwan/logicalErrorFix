#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string s, k;
    cin >> s >> k;
    int n = s.size();
    int m = k.size();
    string a, b;
    bool ans = 0;
    for (int i = 0; i < m; i++) {
      a = "";
      b = "";
      for (int j = 0; j <= i; j++) {
        a += k[j];
      }
      for (int z = i; z < m; z++) {
        b += k[z];
      }
      int pt;
      for (int h = 0; h < n; h++) {
        bool f = 1;
        if (s[h] == k[0]) {
          pt = h;
          for (int p = 0; p < a.size(); p++) {
            if (a[p] == s[pt]) {
              pt++;
            } else {
              f = 0;
              break;
            }
          }
          pt--;
          if (f == 0) {
            continue;
          }
          for (int q = 0; q < b.size(); q++) {
            if (b[q] == s[pt]) {
              pt--;
            } else {
              f = 0;
              break;
            }
          }
          if (f == 0) {
            continue;
          } else if (f == 1) {
            cout << "YES\n";
            ans = 1;
            break;
          }
        }
      }
      if (ans == 1) {
        break;
      }
    }
    if (ans == 0) {
      cout << "NO\n";
    }
    cout << "\n";
  }
}
