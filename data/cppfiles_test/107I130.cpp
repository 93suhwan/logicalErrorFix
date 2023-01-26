#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vvc = vector<vc>;
using vd = vector<double>;
using vp = vector<P>;
using vb = vector<bool>;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll inf = 2e18;
const ll MOD = 1000000007;
const ll mod = 998244353;
const double pi = acos(-1);
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) {
    is >> in;
  }
  return is;
}
void scan() {}
template <class Head, class... Tail>
void scan(Head &head, Tail &...tail) {
  cin >> head;
  scan(tail...);
}
template <class T>
void print(const T &t) {
  cout << t << '\n';
}
template <class Head, class... Tail>
void print(const Head &head, const Tail &...tail) {
  cout << head << ' ';
  print(tail...);
}
template <class... T>
void fin(const T &...a) {
  print(a...);
  exit(0);
}
template <typename T>
T sum_(vector<T> a) {
  return accumulate(begin(a), end(a), T(0));
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  ll times = 1;
  cin >> times;
  while (times--) {
    solve();
  }
}
void solve() {
  ll n, a, b;
  scan(n, a, b);
  ll diff = abs(a - b);
  if (diff > 1) {
    print(-1);
    return;
  }
  if (a + b > (n - 1) / 2 * 2) {
    print(-1);
    return;
  }
  set<ll> s;
  for (__typeof(1) i = 1; i < n + 1; i++) s.insert(i);
  ll status = 0;
  if (a < b) status = 1;
  vl ans(n);
  for (__typeof(n - a - b) i = 0; i < n - a - b; i++) {
    if (status)
      ans[i] = n - a - b - i;
    else
      ans[i] = n - (n - a - b - 1) + i;
    s.erase(ans[i]);
  }
  status ^= 1;
  for (__typeof(n - a - b) i = n - a - b; i < n; i++) {
    if (status)
      ans[i] = *(s.begin());
    else
      ans[i] = *(--s.end());
    s.erase(ans[i]);
    status ^= 1;
  }
  print(ans);
}
