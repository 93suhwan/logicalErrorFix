#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
int a[100010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0, x = 0;
    for (int i = 0; i < n; i++) {
      a[i] = 0;
      int x = 0;
      if (s1[i] == '0' || s2[i] == '0') x++;
      if ((s1[i] == '1' || s2[i] == '1') && x == 1) x++;
      a[i] = x;
      if (a[i - 1] == 0 && a[i] == 1) a[i] = 2;
      if (a[i - 1] == 1 && a[i] == 0) {
        a[i] = 2;
        a[i - 1] = 0;
      }
    }
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans << endl;
  }
}
