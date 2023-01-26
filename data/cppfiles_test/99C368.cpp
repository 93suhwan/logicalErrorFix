#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vpii = vector<pii>;
using ll = long long;
using ull = unsigned long long;
inline void read(int &x) {
  int s = 0;
  x = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  x *= s;
}
ll ceil(ll a, ll b) { return (a + b - 1) / b; }
int main() {
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    if (abs(x) & 1) {
      ll r = y % 4;
      if (r == 0)
        cout << x << '\n';
      else if (r == 1)
        cout << (x + y) << '\n';
      else if (r == 2)
        cout << x - 1 << '\n';
      else
        cout << (x - y - 1) << '\n';
    } else {
      ll r = y % 4;
      if (r == 0)
        cout << x << '\n';
      else if (r == 1)
        cout << (x - y) << '\n';
      else if (r == 2)
        cout << (x + 1LL) << '\n';
      else
        cout << (x + y + 1) << '\n';
    }
  }
  return 0;
}
