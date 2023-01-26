#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void setIO(str second) {
  setIn(second + ".inp");
  setOut(second + ".out");
}
bool check(ll x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  for (int i = (2); i < (sqrt(x) + 1); ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  ll k;
  cin >> k;
  str st;
  cin >> st;
  for (int i = (0); i < (k); ++i) {
    if (st[i] == '1') {
      cout << 1 << endl;
      cout << 1 << endl;
      return;
    }
    if (!check(st[i] - '0')) {
      cout << 1 << endl;
      cout << st[i] << endl;
      return;
    }
  }
  for (int i = (0); i < (k); ++i) {
    for (int j = (i + 1); j < (k); ++j) {
      ll n = (st[i] - '0') * 10 + (st[j] - '0');
      if (!check(n)) {
        cout << 2 << endl << n << endl;
        return;
      }
    }
  }
}
void init() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  init();
  return 0;
}
