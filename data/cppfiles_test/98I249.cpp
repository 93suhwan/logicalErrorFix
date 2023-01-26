#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 55;
char a[maxn];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a;
    int f = 0, e = 0;
    if (n == 1)
      cout << -1 << " " << -1 << "\n";
    else {
      int f = 0, e = 0;
      bool flag = false;
      for (int i = 0; i < n - 1; i++) {
        int na = 0, nb = 0;
        for (int j = i; j < n; j++) {
          if (a[j] == 'a')
            na++;
          else
            nb++;
          if (na == nb && na > 1) {
            f = i + 1;
            e = j + 1;
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
      if (f != 0)
        cout << f << " " << e << "\n";
      else {
        cout << -1 << " " << -1 << "\n";
      }
    }
  }
  return 0;
}
