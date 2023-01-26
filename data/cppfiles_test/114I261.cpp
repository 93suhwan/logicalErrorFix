#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[200005];
bool f[1000005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0;
    cin >> n;
    memset(f, 0, sizeof(s));
    set<pair<int, int>> se;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] != a[j]) {
          int x = se.size();
          if (f[a[i] % a[j]] == 0) {
            se.insert(make_pair(a[i], a[j]));
            if (se.size() != x) {
              x = se.size();
              cout << a[i] << " " << a[j] << endl;
              s++;
            }
          }
          if (s == n / 2) {
            goto gt;
          }
          if (f[a[j] % a[i]] == 0) {
            se.insert(make_pair(a[j], a[i]));
            if (se.size() != x) {
              x = se.size();
              cout << a[j] << " " << a[i] << endl;
              s++;
            }
          }
          if (s == n / 2) {
            goto gt;
          }
        }
      }
    }
  gt:;
  }
}
