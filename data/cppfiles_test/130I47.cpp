#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vtll = vector<tll>;
using gr = vector<vll>;
using wgr = vector<vpll>;
void add_edge(gr& g, ll first, ll second) {
  g[first].push_back(second);
  g[second].push_back(first);
}
void add_edge(wgr& g, ll first, ll second, ll z) {
  g[first].emplace_back(second, z);
  g[second].emplace_back(first, z);
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  cerr << ' ' << p.first << ',' << p.second;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
struct d_ {
  template <typename T>
  d_& operator,(const T& first) {
    cerr << ' ' << first;
    return *this;
  }
} d_t;
bool ask(vll v) {
  auto [first, second, z] = tll{v[0], v[1], v[2]};
  cout << "? " << first + 1 << " " << second + 1 << " " << z + 1 << endl;
  bool ret;
  cin >> ret;
  return ret;
}
pll getExamples(vll r, vll b) {
  vll v = r;
  for (auto i : b) v.push_back(i);
  for (ll i(1); i < 4; i++) {
    bool cur = ask({v[i], v[i + 1], v[i + 2]});
    if (cur) return {v[i - 1], v[i + 2]};
  }
}
void solve() {
  ll n;
  cin >> n;
  ll a0 = -1, a1 = -1;
  set<tll> tried;
  vector<vll> v(2, vll(3));
  v[0][0] = v[1][0] = -1;
  vector<bool> vis(n);
  for (; v[0][0] == -1 || v[1][0] == -1;) {
    set<ll> s;
    for (; s.size() != 3;) {
      ll first;
      first = rand() % n;
      if (vis[first]) continue;
      s.insert(first);
      vis[first] = 1;
    }
    auto it = s.begin();
    vll cur = {*it++, *it++, *it++};
    { d_t, "|", 109, "|", ":", s, cur, "\n"; };
    bool val = ask(cur);
    v[val] = cur;
  }
  auto [R, B] = getExamples(v[0], v[1]);
  vll ret(n, -1);
  ret[R] = 0;
  ret[B] = 1;
  ll cnt = 1;
  for (ll i(0); i < n; i++)
    if (!~ret[i]) {
      ret[i] = ask({R, B, i});
      if (ret[i] == 0) cnt++;
    }
  cout << "! ";
  cout << cnt << " ";
  for (ll i(0); i < n; i++)
    if (ret[i] == 0) cout << i + 1 << " ";
  cout << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  ll _T;
  cin >> _T;
  for (ll _(0); _ < _T; _++) solve();
  return 0;
}
