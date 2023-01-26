#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("inline")
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-4;
const double PI = acos(-1);
struct inst {
  inline char gc() {
    static const int IN_LEN = 1 << 18 | 1;
    static char buf[IN_LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)),
           s == t ? -1 : *s++;
  }
  template <typename _Tp>
  inline inst& operator>>(_Tp& x) {
    static char ch, sgn;
    ch = gc(), sgn = 0;
    for (; !isdigit(ch); ch = gc()) {
      if (ch == -1) return *this;
      sgn |= ch == '-';
    }
    for (x = 0; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ '0');
    sgn && (x = -x);
    return *this;
  }
} io;
inline void Init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
string a, b;
unordered_set<string> se;
bool dfs(string s) {
  if (s == b) return true;
  if (se.count(s))
    return false;
  else {
    se.insert(s);
    string t1 = s + '0';
    string t2 = s + '1';
    while (t1.back() == '0') t1.pop_back();
    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());
    if (t1.size() <= b.size())
      if (dfs(t1)) return true;
    if (t2.size() <= b.size())
      if (dfs(t2)) return true;
  }
  return false;
}
ll t;
inline void solve() {
  cin >> t;
  a = "";
  b = "";
  while (t > 0) {
    if (t & 1)
      a += '1';
    else
      a += '0';
    t >>= 1;
  }
  int na = 0, nb = 0;
  cin >> t;
  while (t > 0) {
    if (t & 1)
      b += '1';
    else
      b += '0';
    t >>= 1;
  }
  while (a.back() == '0') a.pop_back();
  while (b.back() == '0') b.pop_back();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (auto it : a)
    if (it == '0') na++;
  for (auto it : b)
    if (it == '0') nb++;
  if (nb > na) {
    cout << "NO";
    return;
  }
  if (dfs(a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  Init();
  solve();
}
