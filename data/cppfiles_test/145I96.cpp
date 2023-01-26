#include <bits/stdc++.h>
using namespace std;
vector<int> ti;
struct dsu {
  vector<int> e;
  dsu(int N) { e.assign(N + 1, -INT_MAX); }
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int min_time(int x) { return -e[get(x)]; }
  bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    e[x] = max(e[x], e[y]);
    e[y] = x;
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
    ti.assign(n, 0);
    dsu g(n);
    map<int, vector<pair<int, int>>> x, y;
    for (int i = 1; i <= n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      g.e[i] = -c;
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
      if (g.e[i] <= 0) {
        timer.push_back(g.min_time(i));
      }
    }
    sort(timer.begin(), timer.end());
    int i = 0, j = timer.size() - 1;
    int ans = 0;
    while (i < j) {
      ans++;
      j--;
      while (timer[i] <= ans) i++;
    }
    cout << ans << '\n';
  }
  return 0;
}
