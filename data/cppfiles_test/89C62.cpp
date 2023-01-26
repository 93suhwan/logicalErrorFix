#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      bool f = false;
      for (int j = 2; j <= min(100, i + 1); j++) {
        if (a[i] % j != 0) {
          f = true;
          break;
        }
      }
      if (f == false) {
        flag = false;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
