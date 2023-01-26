#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5 + 10;
int mp[N];
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> mp[i];
    int pr = 1;
    for (int i = 1; i <= n; i++) {
      int flag = 0;
      for (int j = i; j >= 1; j--) {
        if (mp[i] % (j + 1) > 0) {
          flag = 1;
          break;
        }
      }
      if (flag)
        continue;
      else {
        pr = 0;
        break;
      }
    }
    puts(pr ? "YES" : "NO");
  }
  return 0;
}
