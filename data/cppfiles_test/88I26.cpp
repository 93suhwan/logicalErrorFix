#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 510;
int a[N];
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0)
      cout << "YES" << '\n';
    else {
      if (n >= 5) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
          if (a[i] <= a[i - 1]) {
            cnt = 1;
            break;
          }
        }
        if (cnt)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
      } else {
        if (n == 3) {
          if (a[1] > a[2] || a[2] > a[3])
            cout << "YES" << '\n';
          else
            cout << "NO" << '\n';
        }
      }
    }
  }
  return 0;
}
