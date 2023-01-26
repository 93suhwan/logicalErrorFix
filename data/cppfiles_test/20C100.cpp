#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const double eps = 1e-6;
const int N = 4e2 + 7;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
const int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, -1, 1, 1, -1, 1, 1};
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void debug(const string &Name, const T &a) {
  cerr << "# " << Name << ": " << a << endl;
}
template <class A, class... B>
void debug(const string &Name, const A &a, const B &...b) {
  cerr << "# " << Name << ": " << a << endl;
  debug(b...);
}
int a[N][N];
int ans;
int sum[N][N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%1d", &a[i][j]);
      }
    }
    ans = 16;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
      }
    }
    auto querySum = [&](int x1, int y1, int x2, int y2) {
      return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
             sum[x1 - 1][y1 - 1];
    };
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int r = i + 4; r <= n; r++) {
          for (int c = j + 3; c <= m; c++) {
            int op[4] = {
                (c - 1 - j) - querySum(r, j + 1, r, c - 1),
                (r - 1 - i) - querySum(i + 1, c, r - 1, c),
                (c - 1 - j) - querySum(i, j + 1, i, c - 1),
                (r - 1 - i) - querySum(i + 1, j, r - 1, j),
            };
            int tmp = querySum(i + 1, j + 1, r - 1, c - 1);
            if (op[0] + op[2] + op[3] >= ans) break;
            ckmin(ans, accumulate(op, op + 4, 0) + tmp);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
