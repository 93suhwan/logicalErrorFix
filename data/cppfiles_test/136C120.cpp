#include <bits/stdc++.h>
using namespace std;
int b[200005], a[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    long long ans = 0;
    cin >> x;
    for (int i = 1; i <= x; i++) {
      cin >> b[i];
      ans += b[i];
    }
    if (((2 * ans) % (x * (x + 1))) != 0) {
      cout << "NO" << endl;
      continue;
    }
    int ok = 0;
    ans = (ans * 2) / (x * (x + 1));
    for (int i = 1; i <= x; i++) {
      long long l, r;
      if (i == 1)
        l = b[x];
      else
        l = b[i - 1];
      r = b[i];
      a[i] = (ans + l - r) / x;
      if (a[i] < 1 || ((ans + l - r) % x) != 0) {
        ok = 1;
      }
    }
    if (ok == 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= x; i++) cout << a[i] << " ";
    cout << endl;
  }
}
