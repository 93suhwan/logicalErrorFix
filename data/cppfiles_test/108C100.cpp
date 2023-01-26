#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(int n, T &v) {
  v.resize(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
}
template <class T>
inline void mineq(T &a, T b) {
  a = min(a, b);
}
template <class T>
inline void maxeq(T &a, T b) {
  a = max(a, b);
}
int n;
vector<int> a, b;
set<pair<int, int> > sa, sb;
void solve() {
  cin >> n;
  read(n, a);
  read(n, b);
  sa.clear();
  sb.clear();
  for (int i = 0; i < n; ++i) {
    sa.insert(make_pair(a[i], i));
    sb.insert(make_pair(b[i], i));
  }
  queue<int> q;
  auto pta = sa.end();
  pta--;
  auto ptb = sb.end();
  ptb--;
  pair<int, int> ma = *pta;
  pair<int, int> mb = *ptb;
  sa.erase(pta);
  sb.erase(ptb);
  q.push(ma.second);
  q.push(mb.second);
  vector<bool> can(n);
  while (!q.empty()) {
    int node = q.front();
    can[node] = true;
    q.pop();
    auto start_a = sa.lower_bound(make_pair(a[node], node));
    for (auto it = start_a; it != sa.end(); it++) {
      int nb = it->second;
      q.push(nb);
    }
    sa.erase(start_a, sa.end());
    auto start_b = sb.lower_bound(make_pair(b[node], node));
    for (auto it = start_b; it != sb.end(); it++) {
      int nb = it->second;
      q.push(nb);
    }
    sb.erase(start_b, sb.end());
  }
  string s;
  for (int i = 0; i < n; ++i) {
    s += can[i] ? "1" : "0";
  }
  cout << s << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
