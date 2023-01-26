#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long n, x, y, a[200001];
string s;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  cin >> s;
  for (long long i = 1; i <= n; i++) {
    cout << a[i] << " ";
    if (s[i - 1] == 'L') {
      if (x > y + a[i]) {
        y += a[i];
        cout << "R" << endl;
      } else {
        x += a[i];
        cout << "L" << endl;
      }
    } else {
      if (y > x + a[i]) {
        x += a[i];
        cout << "L" << endl;
      } else {
        y += a[i];
        cout << "R" << endl;
      }
    }
  }
  return 0;
}
