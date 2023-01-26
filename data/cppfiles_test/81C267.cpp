#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long N = 1000007, M = 1e3, SZ = 1e5 + 5, md = 1e9 + 7,
                mds = 998244353, inf = 1e9 + 5, linf = 2e18 + 5, lgN = 21,
                MX = 3e5, aA = 'a' - 'A';
stack<int> stk;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long a[N], b[N], d[N], w, h, x, qry, y, z, l, r, cnt, res, tmp, num, n, m,
    k, T;
string s;
vector<int> g[N];
bool c[N];
long long t[2 * N];
void update(int x, int v) {
  for (x += n; x; x >>= 1) t[x] += v;
}
long long sum(int x, int y) {
  x += n, y += n;
  long long ret = 0;
  while (x <= y) {
    if (x & 1) ret += t[x++];
    if (~y & 1) ret += t[y--];
    x >>= 1, y >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    cin >> s;
    for (long long i = 1; i <= 2 * n; i++) t[i] = 0;
    for (long long i = 0; i < n; i++) {
      update(i + 1, (s[i] == '+' ? 1 : -1) * (i % 2 ? -1 : 1));
    }
    for (long long i = 0; i < m; i++) {
      cin >> x >> y;
      k = sum(x, y);
      if (k == 0)
        cout << 0 << '\n';
      else {
        w = 0;
        l = x, r = y;
        while (l < r) {
          long long m = l + r >> 1;
          z = sum(x, m - 1) - sum(m + 1, y);
          if (z == 0) {
            w = 1;
            break;
          } else {
            if (z * k < 0)
              l = m + 1;
            else
              r = m;
          }
        }
        if (sum(x + 1, y) == 0 || sum(x, y - 1) == 0) w = 1;
        if (w || x == y)
          cout << 1 << '\n';
        else
          cout << 2 << '\n';
      }
    }
  }
}
