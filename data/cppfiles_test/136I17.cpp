#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long s = 0, a[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % ((n + 1) * n / 2) != 0) {
      cout << "NO" << endl;
      continue;
    } else
      s /= ((n + 1) * n / 2);
    long long ans[n + 1];
    ans[n] = 0;
    ans[1] = (a[n] + s - a[1]) / n;
    if (ans[1] == 0) {
      cout << "NO" << endl;
      continue;
    }
    for (long long i = 1; i < n; i++) {
      ans[i + 1] = (a[i] + s - a[i + 1]) / n;
      if (ans[i + 1] == 0) break;
    }
    if (ans[n] == 0) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
