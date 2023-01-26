#include <bits/stdc++.h>
using namespace std;
namespace hjt {
template <typename A, typename B>
std::ostream &operator<<(std::ostream &o, const std::pair<A, B> &x) {
  return o << '(' << x.first << ',' << x.second << ')';
}
}  // namespace hjt
using namespace hjt;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 7;
int n;
int a[N];
int ans[N];
int query(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  cin >> a;
  return a;
}
void answer() {
  int k = 0;
  for (int i = 1; i <= n; ++i) k += ans[i] == 0;
  cout << "! " << k;
  for (int i = 1; i <= n; ++i)
    if (ans[i] == 0) {
      cout << ' ' << i;
    }
  cout << endl;
}
int spj(int chk01, int chk12, int p, int v) {
  int p0 = 0;
  if (chk01 == v && chk12 == v) {
    ans[p] = ans[p + 1] = ans[p + 2] = v;
    p0 = p;
  } else if (chk01 != v && chk12 != v) {
    ans[p] = ans[p + 2] = v;
    ans[p + 1] = v ^ 1;
    p0 = p;
  } else if (chk01 != v && chk12 == v) {
    ans[p + 1] = ans[p + 2] = v;
    ans[p] = v ^ 1;
    p0 = p + 1;
  } else if (chk01 == v && chk12 != v) {
    ans[p] = ans[p + 1] = v;
    ans[p + 2] = v ^ 1;
    p0 = p;
  }
  return p0;
}
inline void solve() {
  cin >> n;
  memset(ans + 1, -1, sizeof(int) * n);
  int p[2] = {0, 0};
  for (int i = 1; i <= n; i += 3) {
    a[i] = query(i, i + 1, i + 2);
    p[a[i]] = i;
  }
  int chk01 = 0, chk12 = 0, v[2];
  for (int i = 0; i < 3; ++i) {
    chk01 |= query(p[0], p[0] + 1, p[1] + i);
    chk12 |= query(p[0] + 1, p[0] + 2, p[1] + i);
  }
  v[0] = spj(chk01, chk12, p[0], 0);
  chk01 = query(p[1], p[1] + 1, v[0]);
  chk12 = query(p[1] + 1, p[1] + 2, v[0]);
  v[1] = spj(chk01, chk12, p[1], 1);
  for (int i = 1; i <= n; i += 3)
    if (i != p[0] && i != p[1]) {
      chk01 = query(i, i + 1, v[a[i] ^ 1]);
      chk12 = query(i + 1, i + 2, v[a[i] ^ 1]);
      spj(chk01, chk12, i, a[i]);
    }
  answer();
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
