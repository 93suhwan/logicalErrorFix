#include <bits/stdc++.h>
using namespace std;
const long long _ = 2e5 + 7;
const double PI = acos(-1);
const long long inf = 0x3f3f3f3f;
const long long INF = (1 << 31) - 1;
template <typename T>
T rd(T& res) {
  res = 0;
  long long f = 1;
  char ch;
  while ((ch = cin.get()) && (ch < '0' || ch > '9')) {
    f = ch == '-';
  }
  res = ch - 48;
  while ((ch = cin.get()) && ch >= '0' && ch <= '9') {
    res = res * 10 + ch - 48;
  }
  return res * f;
}
void work() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a == b && c > 1) {
    cout << "YES\n";
    return;
  }
  if (b == c && a > 1) {
    cout << "YES\n";
    return;
  }
  if (a == c && b > 1) {
    cout << "YES\n";
    return;
  }
  if (a + b == c || a + c == b || b + c == a) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long T;
  rd(T);
  for (long long i = 1; i <= T; ++i) {
    work();
  }
}
