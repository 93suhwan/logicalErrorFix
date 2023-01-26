#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
const int inf = 1e9;
int a[nax];
int n;
map<tuple<int, int, int>, pair<pair<int, int>, int> > pop;
set<pair<int, int> > alive;
set<pair<int, int> > nxt;
void go(int id, int val) {
  for (pair<int, int> was : alive) {
    if (val < was.first && val < was.second) continue;
    if (val < was.first) {
      nxt.insert(make_pair(was.first, val));
      pop[make_tuple(id, was.first, val)] = make_pair(was, val);
    } else {
      nxt.insert(make_pair(val, was.second));
      pop[make_tuple(id, val, was.second)] = make_pair(was, val);
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  pop.clear();
  alive.clear();
  nxt.clear();
  alive.insert(make_pair(-a[1], -inf));
  pop[make_tuple(1, -a[1], -inf)] = make_pair(make_pair(0, 0), -a[1]);
  for (int i = 2; i <= n; i++) {
    int val = a[i];
    nxt.clear();
    go(i, val);
    go(i, -val);
    while (1) {
      vector<pair<int, int> > out;
      for (pair<int, int> cur : nxt) {
        bool ex = false;
        for (pair<int, int> dom : nxt) {
          if (dom.first < cur.first && dom.second < cur.second) ex = true;
          if (dom.first == cur.first && dom.second < cur.second) ex = true;
          if (dom.first < cur.first && dom.second == cur.second) ex = true;
        }
        if (ex) out.push_back(cur);
      }
      if (out.empty()) break;
      for (pair<int, int> cur : out) nxt.erase(cur);
    }
    alive = nxt;
  }
  if (alive.empty()) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
    vector<int> ans;
    int id = n;
    pair<int, int> cur = (*alive.begin());
    while (id >= 1) {
      auto go = pop[make_tuple(id, cur.first, cur.second)];
      ans.push_back(go.second);
      cur = go.first;
      id -= 1;
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
