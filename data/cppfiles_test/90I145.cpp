#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> p(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    int k = 1;
    for (int i = 1; i < m; i++)
      if (p[i].first != p[i - 1].first) p[k++] = p[i];
    p.resize(k);
    m = k;
    vector<tuple<int, int, int>> points;
    for (int i = 0; i < m; i++) {
      points.emplace_back(p[i].first, 0, i);
      points.emplace_back(p[i].second, 2, i);
    }
    for (int i = 0; i < n; i++) points.emplace_back(a[i], 1, i);
    sort(points.begin(), points.end());
    vector<pair<int, int>> segs;
    set<pair<int, int>> S;
    for (auto pt : points) {
      int i = get<2>(pt);
      if (get<1>(pt) == 0) {
        auto it = S.lower_bound(make_pair(p[i].second, -1));
        while (it != S.end()) S.erase(it++);
        S.insert(make_pair(p[i].second, i));
      } else if (get<1>(pt) == 1) {
        S.clear();
      } else {
        auto it = S.find(make_pair(p[i].second, i));
        if (it != S.end()) segs.push_back(p[i]);
      }
    }
    long long f1, f2;
    if (segs.size() > 0 && segs[0].first < a[0]) {
      f1 = a[0] - segs[0].second;
      f2 = 2 * (a[0] - segs[0].second);
    } else {
      f1 = f2 = 0;
    }
    for (int i = 1; i < n; i++) {
      long long new_f1 = 1e18, new_f2 = 1e18;
      int l =
          lower_bound(segs.begin(), segs.end(), make_pair(a[i - 1], a[i - 1])) -
          segs.begin();
      int r = lower_bound(segs.begin(), segs.end(), make_pair(a[i], a[i])) -
              segs.begin();
      for (int j = l; j <= r; j++) {
        int x, y;
        if (j == l)
          x = 0;
        else
          x = segs[j - 1].first - a[i - 1];
        if (j == r)
          y = 0;
        else
          y = a[i] - segs[j].second;
        new_f1 = min(new_f1, f1 + 2 * x + 1 * y);
        new_f1 = min(new_f1, f2 + 1 * x + 1 * y);
        new_f2 = min(new_f2, f1 + 2 * x + 2 * y);
        new_f2 = min(new_f2, f2 + 1 * x + 2 * y);
      }
      f1 = new_f1;
      f2 = new_f2;
    }
    long long ans;
    if (!segs.empty() && segs.back().first > a.back()) {
      int x = segs.back().first - a.back();
      ans = min(f1 + 2 * x, f2 + 1 * x);
    } else {
      ans = min(f1, f2);
    }
    cout << ans << '\n';
  }
}
