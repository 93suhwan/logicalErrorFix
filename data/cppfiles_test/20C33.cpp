#include <bits/stdc++.h>
using namespace std;
namespace debug {
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
char elo(...);
template <class c>
auto elo(c* a) -> decltype(cerr << *a, 0);
struct stream {
  ~stream() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof elo<c>(0) != 1, stream&>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof elo<c>(0) == 1, stream&>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class a, class b>
  stream& operator<<(pair<a, b> p) {
    return *this << "(" << p.first << ", " << p.second << ")";
  }
  template <class c>
  stream& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; it++) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
  stream& _dbg(const string& s, int i, int b) { return *this; }
  template <class c, class... cs>
  stream& _dbg(const string& s, int i, int b, c arg, cs... args) {
    if (i == s.size()) return (*this << ": " << arg << "");
    b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{');
    b -= (s[i] == ')') + (s[i] == ']') + (s[i] == '}');
    if (s[i] == ',' && b == 0)
      return (*this << ": " << arg << "     ")._dbg(s, i + 1, b, args...);
    return (s[i] == ' ' ? *this : *this << s[i])
        ._dbg(s, i + 1, b, arg, args...);
  }
};
}  // namespace debug
template <class p, class q>
pair<p, q> operator-(pair<p, q> a, pair<p, q> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <class p, class q>
pair<p, q> operator+(pair<p, q> a, pair<p, q> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <class p, class q>
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int N = 1000005;
int t[N];
int last[N];
bool done[N];
int cnt[N];
pair<int, int> out[N];
void solve() {
  int n, i, j, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int> > vec;
  for (i = 1; i <= n * k; i++) {
    scanf("%d", &t[i]);
    if (last[t[i]] != 0) vec.push_back({i, last[t[i]]});
    last[t[i]] = i;
  }
  int lim = (n + k - 2) / (k - 1);
  sort(vec.begin(), vec.end());
  for (pair<int, int> p : vec) {
    int a = p.second;
    int b = p.first;
    int col = t[a];
    assert(t[a] == t[b]);
    if (done[col] == true) continue;
    for (i = a; i <= b; i++)
      if (cnt[i] == lim) break;
    if (i <= b) continue;
    for (i = a; i <= b; i++) cnt[i] += 1;
    out[col] = {a, b};
    done[col] = true;
  }
  for (i = 1; i <= n; i++) printf("%d %d\n", out[i].first, out[i].second);
}
int main() {
  int q = 1;
  while (q--) solve();
  return 0;
}
