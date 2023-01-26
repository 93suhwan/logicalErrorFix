#include <bits/stdc++.h>
using namespace std;
long long fun(string a) {
  long long x = 0, y = 0, n = a.length(), i;
  for (i = 0; i < n; i++) {
    long long z = (n - i);
    if ((x + z / 2 < y)) return i;
    if (z % 2 == 0) {
      if (y + z / 2 < x) return i;
    } else {
      if (y + z / 2 + 1 < x) return i;
    }
    if (i % 2 == 0) {
      if (a[i] == '1') x++;
    } else {
      if (a[i] == '1') y++;
    }
  }
  return i;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(10);
  long long t = 1;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    long long n = a.length();
    string b = a;
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i] == '?') a[i] = '1';
      } else {
        if (a[i] == '?') a[i] = '0';
      }
    }
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (b[i] == '?') b[i] = '0';
      } else {
        if (b[i] == '?') b[i] = '1';
      }
    }
    cout << min(fun(a), fun(b)) << endl;
  }
  return 0;
}
