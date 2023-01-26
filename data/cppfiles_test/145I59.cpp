#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const double eps = 1e-7;
const int N = 2e5 + 5, M = 3e5 + 5;
int r[N], par[N];
int find_set(int a) {
  while (par[a] != a) a = par[a];
  return a;
}
void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b) return;
  par[a] = b;
  r[b] = min(r[b], r[a]);
}
void test() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  vector<pair<int, int> > edg(n);
  map<int, vector<pair<int, int> > > row, col;
  for (int i = 0; i < n; i++) {
    cin >> edg[i].first >> edg[i].second >> r[i];
    row[edg[i].first].push_back({edg[i].second, i});
    col[edg[i].second].push_back({edg[i].first, i});
  }
  for (auto v : row) {
    sort(v.second.begin(), v.second.end());
    for (int i = 1; i < v.second.size(); i++) {
      int c1 = v.second[i].first, c2 = v.second[i - 1].first;
      if (c1 - c2 > k) continue;
      union_set(v.second[i].second, v.second[i - 1].second);
    }
  }
  for (auto c : col) {
    sort(c.second.begin(), c.second.end());
    for (int i = 1; i < c.second.size(); i++) {
      int r1 = c.second[i].first, r2 = c.second[i - 1].first;
      if (r1 - r2 > k) continue;
      union_set(c.second[i].second, c.second[i - 1].second);
    }
  }
  set<int> s2, s;
  for (int i = 0; i < n; i++) {
    s2.insert(find_set(i));
  }
  for (auto a : s2) {
    s.insert(r[a]);
  }
  auto it = s.end();
  it--;
  int sec = 0, timer;
  while (it != s.begin()) {
    timer = *it;
    it--;
    if (sec > timer) break;
    sec++;
  }
  timer = *it;
  if (sec <= timer) sec++;
  cout << sec - 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int cases = 1;
  cin >> cases;
  while (cases--) test();
}
