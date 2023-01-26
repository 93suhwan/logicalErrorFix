#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
const int INF = 0x3f3f3f3f;
const int mo = 1e9 + 7;
inline int read() {
  int data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = getchar();
  return data * w;
}
long long fastpower(long long base, long long power) {
  long long res = 1;
  while (power) {
    if (power & 1) res = res * base % mo;
    power >>= 1;
    base = base * base % mo;
  }
  return res % mo;
}
void solve() {
  int c, d;
  cin >> c >> d;
  if (c == d && c == 0) {
    cout << 0 << endl;
  } else if (c == d) {
    cout << 1 << endl;
  } else if ((c - d) % 2 == 0) {
    cout << 2 << endl;
  } else {
    cout << -1 << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int __;
  cin >> __;
  while (__--) {
    solve();
  }
  return 0;
}
