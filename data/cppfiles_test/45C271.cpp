#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long ans = 1;
    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }
    ans += a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] == 0 && a[i - 1] == 0) {
        ans = -1;
        break;
      } else if (a[i] == 1 && a[i - 1] == 0)
        ans += 1;
      else if (a[i] == 1 && a[i - 1] == 1)
        ans += 5;
    }
    cout << ans << endl;
  }
  return 0;
}
