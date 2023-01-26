#include <bits/stdc++.h>
using namespace std;
vector<int> ti;
struct dsu {
  vector<int> e;
  dsu(int N) { e.assign(N + 1, -1); }
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  bool same_set(int a, int b) { return get(a) == get(b); }
  bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    ti[x] = min(ti[x], ti[y]);
    return true;
  }
};
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    ti.assign(n + 1, 0);
    dsu g(n);
    map<int, vector<pair<int, int>>> x, y;
    for (int i = 1; i <= n; i++) {
      int a, b, c;
      cin >> a >> b >> ti[i];
      x[a].push_back({b, i});
      y[b].push_back({a, i});
    }
    for (auto &i : x) {
      sort(i.second.begin(), i.second.end());
      if (i.second.size() > 1) {
        for (int j = 1; j < i.second.size(); j++) {
          if (i.second[j].first - i.second[j - 1].first <= k)
            g.merge(i.second[j].second, i.second[j - 1].second);
        }
      }
    }
    for (auto &i : y) {
      sort(i.second.begin(), i.second.end());
      if (i.second.size() > 1) {
        for (int j = 1; j < i.second.size(); j++) {
          if (i.second[j].first - i.second[j - 1].first <= k)
            g.merge(i.second[j].second, i.second[j - 1].second);
        }
      }
    }
    vector<int> timer;
    for (int i = 1; i <= n; i++) {
      if (g.get(i) == i) {
        timer.push_back(ti[i]);
      }
    }
    sort(timer.rbegin(), timer.rend());
    int ans = -1;
    for (int i = 0; i < timer.size(); i++) {
      if (ans < timer[i])
        ans++;
      else
        continue;
    }
    cout << ans << '\n';
  }
  return 0;
}
