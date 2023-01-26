#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int p[N], sz[N];
void init(int n) {
  for (int i = 0; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}
int find(int x) {
  if (x == p[x]) return x;
  return find(p[x]);
}
void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (sz[b] > sz[a]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}
void test_case() {
  int n, k;
  cin >> n >> k;
  init(n);
  map<int, set<int>> line;
  map<int, set<int>> col;
  map<pair<int, int>, int> mp;
  vector<int> T(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    auto it = line[x].lower_bound(y);
    if (it != line[x].end()) {
      if (abs(*it - y) <= k) unite(mp[{x, *it}], i);
    }
    if (it != line[x].begin()) {
      it--;
      if (abs(*it - y) <= k) unite(mp[{x, *it}], i);
    }
    it = col[y].lower_bound(x);
    if (it != col[y].end()) {
      if (abs(*it - x) <= k) unite(mp[{*it, y}], i);
    }
    if (it != col[y].begin()) {
      it--;
      if (abs(*it - x) <= k) unite(mp[{*it, y}], i);
    }
    line[x].insert(y);
    col[y].insert(x);
    mp[{x, y}] = i;
    T[i] = t;
  }
  set<int> comp;
  for (int i = 1; i <= n; i++) {
    int x = find(i);
    comp.insert(x);
    T[x] = min(T[x], T[i]);
  }
  vector<int> V;
  for (int i : comp) V.push_back(i);
  sort(V.begin(), V.end(), [&](int a, int b) { return T[a] > T[b]; });
  int m = V.size();
  int tempo = -1;
  int boom = -1;
  for (int i = 0; i < m; i++) {
    if (T[V[i]] > tempo) {
      boom++;
      tempo++;
    }
  }
  cout << max(0, boom) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) test_case();
  return 0;
}
