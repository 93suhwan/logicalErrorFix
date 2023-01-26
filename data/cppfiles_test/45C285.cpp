#include <bits/stdc++.h>
using namespace std;
long long a[1003];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 1;
    for (long long i = 1; i <= n; i++) {
      if (i == 1) {
        ans += a[i];
        continue;
      }
      if (a[i] == 0 && a[i - 1] == 0) {
        ans = -1;
        break;
      }
      if (a[i] == 1 && a[i - 1] == 1) {
        ans += 5;
      } else {
        ans += a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
