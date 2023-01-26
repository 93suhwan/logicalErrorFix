#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    long long a[200], extra[200];
    for (int i = 0; i < n; i++) cin >> a[i], extra[i] = a[i];
    long long no = 1e4 + 5;
    long long d;
    int ans = 0;
    for (d = 2; d <= no; d++) {
      ans = 0;
      for (int i = 0; i < n; i++) {
        long long g = a[i];
        if (g % d)
          a[i] = 1;
        else
          a[i] = 0;
        if (i >= 1) {
          if (a[i - 1] == a[i]) {
            ans = 1;
            break;
          }
        }
      }
      if (ans == 0) break;
      for (int i = 0; i < n; i++) {
        a[i] = extra[i];
      }
    }
    if (ans == 0)
      cout << d << "\n";
    else
      cout << 0 << "\n";
  }
}
