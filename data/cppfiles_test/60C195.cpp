#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a[105];
    long long maxx = -2e9;
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > maxx) {
        maxx = a[i];
      }
    }
    long long ans = a[1];
    for (int i = 2; i <= n; i++) ans = ans & a[i];
    cout << ans << endl;
  }
  return 0;
}
