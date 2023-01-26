#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
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
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void setIO(str second) {
  setIn(second + ".inp");
  setOut(second + ".out");
}
const int MOD = 239;
const int MX = 2e5 + 5;
const ll INF = 1e15;
const db PI = acos((db)-1);
const ll MXN = 2e5 + 1;
ll n, m, res, delta = 0;
vpl Edges;
vl cnt;
queue<pl> Q;
void init(void) {
  cin >> n >> m;
  cnt.assign(n + 1, 0);
  res = n;
  for (int i = (0); i < (m); ++i) {
    ll u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    cnt[u]++;
    if (cnt[u] == 1) res--;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  ll q;
  cin >> q;
  while (q--) {
    ll type;
    cin >> type;
    if (type == 1) {
      ll u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      Q.push({u, -1});
      cnt[u]++;
      if (cnt[u] == 1) {
        delta++;
        res--;
      }
      continue;
    }
    if (type == 2) {
      ll u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      Q.push({u, 1});
      cnt[u]--;
      if (cnt[u] == 0) {
        delta--;
        res++;
      }
    }
    if (type == 3) {
      cout << res << '\n';
      res += delta;
      delta = 0;
      while (!Q.empty()) {
        pl _q = Q.front();
        Q.pop();
        cnt[_q.first] += _q.second;
      }
    }
  }
  return 0;
}
