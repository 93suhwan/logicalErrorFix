#include <bits/stdc++.h>
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
inline int read() {
  static int ans, f;
  static char ch;
  for (f = 1, ch = getchar(); !isdigit(ch); f ^= ch == '-', ch = getchar())
    ;
  for (ans = 0; isdigit(ch);
       ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = getchar())
    ;
  return f ? ans : -ans;
}
inline long long readl() {
  static long long ans;
  static int f;
  static char ch;
  for (f = 1, ch = getchar(); !isdigit(ch); f ^= ch == '-', ch = getchar())
    ;
  for (ans = 0; isdigit(ch);
       ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = getchar())
    ;
  return f ? ans : -ans;
}
namespace modular {
const int mod = 1e9 + 7;
inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
inline void Mul(int &a, int b) { a = (long long)a * b % mod; }
inline int ksm(int a, int p) {
  static int ret;
  for (ret = 1; p; p >>= 1, Mul(a, a))
    if (p & 1) Mul(ret, a);
  return ret;
}
inline int Inv(int a) { return ksm(a, mod - 2); }
}  // namespace modular
using namespace modular;
const int N = 2e5 + 5;
int n, m, X, Y, p;
map<pair<pair<int, int>, pair<int, int> >, bool> vs;
vector<pair<pair<int, int>, pair<int, int> > > q;
vector<int> pre;
int main() {
  for (int tt = read(); tt; --tt) {
    n = read(), m = read();
    q.resize(0);
    pre.resize(0);
    vs.clear();
    int x_0 = read(), y_0 = read(), dx = 1, dy = 1;
    X = read(), Y = read();
    x_0 += dx;
    y_0 += dy;
    if (x_0 > n || !x_0) {
      dx = -dx;
      x_0 += 2 * dx;
    }
    if (y_0 > m || !y_0) {
      dy = -dy;
      y_0 += 2 * dy;
    }
    x_0 -= dx;
    y_0 -= dy;
    p = mul(read(), Inv(100));
    q.push_back(make_pair(pair<int, int>(0, 0), pair<int, int>(0, 0)));
    q.push_back(make_pair(pair<int, int>(x_0, y_0), pair<int, int>(dx, dy)));
    vs[make_pair(pair<int, int>(x_0, y_0), pair<int, int>(dx, dy))] = 1;
    while (1) {
      x_0 += dx;
      y_0 += dy;
      x_0 += dx;
      y_0 += dy;
      if (x_0 > n || !x_0) {
        dx = -dx;
        x_0 += 2 * dx;
      }
      if (y_0 > m || !y_0) {
        dy = -dy;
        y_0 += 2 * dy;
      }
      x_0 -= dx;
      y_0 -= dy;
      pair<pair<int, int>, pair<int, int> > t =
          make_pair(pair<int, int>(x_0, y_0), pair<int, int>(dx, dy));
      if (vs.count(t)) break;
      vs[t] = 1;
      q.push_back(t);
    }
    int len = (int)q.size() - 1;
    pre.resize(q.size());
    pre[0] = 1;
    for (int i = 1; i < q.size(); ++i) {
      int x = q[i].first.first, y = q[i].first.second;
      if (x == X || y == Y)
        pre[i] = mul(pre[i - 1], dec(1, p));
      else
        pre[i] = pre[i - 1];
    }
    int P = Inv(dec(1, pre.back())), coe = mul(mul(pre.back(), len), mul(P, P));
    int res = 0;
    for (int i = 1; i < q.size(); ++i) {
      int x = q[i].first.first, y = q[i].first.second;
      if (x == X || y == Y) {
        Add(res, mul(coe, mul(pre[i - 1], p)));
        Add(res, mul(i - 1, mul(P, mul(pre[i - 1], p))));
      }
    }
    cout << res << '\n';
  }
  return 0;
}
