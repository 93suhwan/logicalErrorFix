#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, e = 0, o = 0, ans = 1e15;
    cin >> n;
    long long int a[n + 1];
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        e++;
      else
        o++;
    }
    if (abs(e - o) > 1)
      cout << -1 << endl;
    else {
      if (e == o) {
        long long int x = 1;
        long long int s = 0;
        for (long long int i = 1; i <= n; i++) {
          if (a[i] % 2 == 0) {
            s = s + abs(i - x);
            x = x + 2;
          }
        }
        ans = min(ans, s);
        x = 2;
        s = 0;
        for (long long int i = 1; i <= n; i++) {
          if (a[i] % 2 == 0) {
            s = s + abs(i - x);
            x = x + 2;
          }
        }
        ans = min(ans, s);
      } else if (e > o) {
        long long int x = 1;
        long long int s = 0;
        for (long long int i = 1; i <= n; i++) {
          if (a[i] % 2 == 0) {
            s = s + abs(i - x);
            x = x + 2;
          }
        }
        ans = min(ans, s);
      } else if (o > e) {
        long long int x = 2;
        long long int s = 0;
        for (long long int i = 1; i <= n; i++) {
          if (a[i] % 2 == 0) {
            s = s + abs(i - x);
            x = x + 2;
          }
        }
        ans = min(ans, s);
      }
      cout << ans << endl;
    }
  }
}
