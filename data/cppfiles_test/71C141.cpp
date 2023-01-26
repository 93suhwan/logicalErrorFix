#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 500005;
const long long Mod = 1e9 + 7;
int main() {
  int t, k;
  string n;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string ans;
    for (char a = '0'; a <= '9'; a++) {
      string t(n.length(), a);
      if (t >= n) {
        ans = t;
        break;
      }
    }
    if (k == 1) {
      cout << ans << endl;
    } else {
      for (char a = '0'; a <= '9'; a++) {
        for (char b = a + 1; b <= '9'; b++) {
          bool ok = true;
          for (int i = 0; i < n.length(); i++) {
            if (n[i] < b) {
              string t = n;
              if (n[i] < a)
                t[i] = a;
              else
                t[i] = b;
              for (int j = i + 1; j < n.length(); j++) {
                t[j] = a;
              }
              if (ans > t) ans = t;
            }
            if (n[i] != a && n[i] != b) {
              ok = false;
              break;
            }
          }
          if (ok) ans = n;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
