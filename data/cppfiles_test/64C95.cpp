#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
  vector<int> f;
  dsu(int n) : f(n) {
    for (int i = 1; i < n; i++) f[i] = i;
  }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    f[y] = x;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu t1(n + 1), t2(n + 1);
  for (int i = 0; i < m1; i++) {
    int x, y;
    cin >> x >> y;
    t1.merge(x, y);
  }
  for (int i = 0; i < m2; i++) {
    int x, y;
    cin >> x >> y;
    t2.merge(x, y);
  }
  vector<pair<int, int>> miao;
  vector<int> v1, v2;
  for (int i = 2; i <= n; i++) {
    if (t1.find(i) != 1 && t2.find(i) != 1) {
      miao.push_back({1, i});
      t1.merge(1, i);
      t2.merge(1, i);
    }
    if (t1.find(i) != 1) v1.push_back(i);
    if (t2.find(i) != 1) v2.push_back(i);
  }
  while (!v1.empty() && !v2.empty()) {
    if (t1.find(v1.back()) == 1 && t2.find(v1.back()) == 1) {
      v1.pop_back();
      continue;
    }
    if (t1.find(v2.back()) == 1 && t2.find(v2.back()) == 1) {
      v2.pop_back();
      continue;
    }
    miao.push_back({v1.back(), v2.back()});
    t1.merge(v1.back(), v2.back());
    t2.merge(v1.back(), v2.back());
    v1.pop_back();
    v2.pop_back();
  }
  cout << miao.size() << '\n';
  for (auto i : miao) cout << i.first << ' ' << i.second << '\n';
  return ~~(0 - 0);
}
