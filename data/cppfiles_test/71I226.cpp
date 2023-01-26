#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 200000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
struct P {
  ll x, y;
  P() : x(0), y(0) {}
  P(ll a, ll b) : x(a), y(b) {}
  void in() { scanf("%lld%lld", &x, &y); }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  P operator*(const db &a) const { return P(x * a, y * a); }
  P operator/(const db &a) const { return P(x / a, y / a); }
  db len() { return sqrt(x * x + y * y); }
  db len2() { return x * x + y * y; }
  P unit() { return *this / len(); }
  db dot(const P b) { return x * b.x + y * b.y; }
  db cross(const P b) { return x * b.y - y * b.x; }
  db unitdot(P b) { return unit().dot(b.unit()); }
  db unitcross(P b) { return unit().cross(b.unit()); }
};
P a[maxn + 5], b[maxn + 5];
bool colinear(P a, P b, P c) { return (a - b).cross(b - c) == 0; }
bool check(int n, P p, P q) {
  int cnt = 0;
  for (auto i = 1; i <= n; i++) cnt += colinear(a[i], p, q);
  return cnt >= n - 1;
}
int id[maxn + 5];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (auto i = 1; i <= n; i++) a[i].in();
  P p, q;
  if (check(n, a[1], a[2]))
    p = a[1], q = a[2];
  else if (check(n, a[1], a[3]))
    p = a[1], q = a[3];
  else
    p = a[2], q = a[3];
  int no = -1;
  for (auto i = 1; i <= n; i++)
    if (colinear(a[i], p, q) == 0) {
      no = i;
      break;
    }
  swap(a[no], a[n]);
  if (k == no)
    k = n;
  else if (k == n)
    k = no;
  for (auto i = 1; i <= n - 1; i++) id[i] = i;
  sort(id + 1, id + n, [&](int i, int j) {
    return (q - p).dot(a[i] - p) < (q - p).dot(a[j] - p);
  });
  for (auto i = 1; i <= n - 1; i++)
    if (id[i] == k) {
      k = i;
      break;
    }
  for (auto i = 1; i <= n - 1; i++) b[i] = a[id[i]];
  b[n] = a[n];
  if (k == n) {
    db ans = 1e100;
    chmin(ans, (b[n] - b[1]).len());
    chmin(ans, (b[n] - b[n - 1]).len());
    ans += (b[n - 1] - b[1]).len();
    printf("%.10f\n", ans);
  } else {
    db ans = 1e100;
    chmin(ans,
          (b[k] - b[n]).len() + (b[n] - b[1]).len() + (b[1] - b[n - 1]).len());
    chmin(ans, (b[k] - b[n]).len() + (b[n] - b[n - 1]).len() +
                   (b[1] - b[n - 1]).len());
    chmin(ans, (b[k] - b[1]).len() + (b[1] - b[n - 1]).len() +
                   (b[n - 1] - b[n]).len());
    for (auto i = 2; i <= n - 1; i++) {
      chmin(ans, (b[k] - b[i]).len() + (b[i] - b[n - 1]).len() +
                     (b[n - 1] - b[n]).len() + (b[n] - b[i - 1]).len() +
                     (b[1] - b[i - 1]).len());
      chmin(ans, (b[k] - b[i]).len() + (b[i] - b[n - 1]).len() +
                     (b[n - 1] - b[n]).len() + (b[n] - b[1]).len() +
                     (b[1] - b[i - 1]).len());
    }
    chmin(ans, (b[k] - b[n - 1]).len() + (b[1] - b[n - 1]).len() +
                   (b[1] - b[n]).len());
    for (auto i = 1; i <= n - 2; i++) {
      chmin(ans, (b[k] - b[i]).len() + (b[i] - b[1]).len() +
                     (b[1] - b[n]).len() + (b[n] - b[i + 1]).len() +
                     (b[n - 1] - b[i + 1]).len());
      chmin(ans, (b[k] - b[i]).len() + (b[i] - b[1]).len() +
                     (b[1] - b[n]).len() + (b[n] - b[n - 1]).len() +
                     (b[n - 1] - b[i + 1]).len());
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
