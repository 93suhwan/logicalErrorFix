#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 200000 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    int ans = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
        ans += 2;
        flag = 0;
      } else if (a[i] == '0' && b[i] == '0') {
        if (flag == 1) {
          ans += 2;
          flag = 0;
          continue;
        }
        if (i + 1 <= n && a[i + 1] == '1' && b[i + 1] == '1') {
          i++;
          ans += 2;
        } else {
          ans += 1;
        }
      } else {
        flag = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
