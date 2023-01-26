#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;
using vi = vector<int>;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
const ll INF = 2e15;
const int ALP = 26;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, m;
vi c[10];
set<vi> s, vis;
using p = pair<int, vi>;
struct cmp {
  bool operator()(p t, p u) { return t.first < u.first; }
};
void solve() {
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int t;
    cin >> t;
    for (int j = (0); j < (t); ++j) {
      int tt;
      cin >> tt;
      c[i].push_back(tt);
    }
  }
  cin >> m;
  for (int i = (0); i < (m); ++i) {
    vi t;
    for (int j = (0); j < (n); ++j) {
      int tt;
      cin >> tt;
      --tt;
      t.push_back(tt);
    }
    s.insert(t);
  }
  vector<vi> ans;
  priority_queue<p, vector<p>, cmp> q;
  vi st;
  int si = 0;
  for (int i = (0); i < (n); ++i) {
    st.push_back((int)(c[i]).size() - 1);
    si += c[i].back();
  }
  int cnt = 0;
  vis.insert(st);
  q.push(p(si, st));
  int mi = si;
  while (true) {
    auto [sum, v] = q.top();
    if (!s.count(v)) {
      for (auto x : v) cout << x + 1 << ' ';
      cout << '\n';
      break;
    }
    q.pop();
    for (int i = (0); i < (n); ++i) {
      if (v[i] == 0) continue;
      vi t(v);
      t[i]--;
      if (vis.count(t)) continue;
      vis.insert(t);
      int ts = sum - (c[i][v[i]] - c[i][v[i] - 1]);
      q.push(p(ts, t));
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
