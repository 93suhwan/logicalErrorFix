#include <bits/stdc++.h>
using namespace std;
bool sort2(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
long long t, n, m, k;
string s;
vector<pair<int, int>> v;
vector<pair<int, int>> h;
vector<int> pathv;
vector<int> pathh;
vector<bool> ve;
vector<bool> he;
long long cross, ans;
int main() {
  cin >> t;
  for (int xy = 0; xy < t; xy++) {
    cross = 0;
    ans = 0;
    cin >> n >> m >> k;
    ve.assign(1000001, false);
    he.assign(1000001, false);
    v.clear();
    h.clear();
    pathv.resize(n + 2);
    pathh.resize(m + 2);
    for (int i = 0; i < n; i++) {
      cin >> pathv[i];
      ve[pathv[i]] = true;
    }
    pathv[n] = 0;
    pathv[n + 1] = 1000001 - 1;
    ve[0] = true;
    ve[1000001 - 1] = true;
    for (int i = 0; i < m; i++) {
      cin >> pathh[i];
      he[pathh[i]] = true;
    }
    pathh[n] = 0;
    pathh[n + 1] = 1000001 - 1;
    he[0] = true;
    he[1000001 - 1] = true;
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      if (ve[a] && he[b])
        cross++;
      else if (ve[a])
        v.push_back({a, b});
      else
        h.push_back({a, b});
    }
    sort(pathv.begin(), pathv.end());
    sort(pathh.begin(), pathh.end());
    sort(h.begin(), h.end());
    sort(v.begin(), v.end(), sort2);
    long long l = 0, r = 0;
    set<int> group;
    while (l < pathv.size() && r < h.size()) {
      if (pathv[l] < h[r].first) {
        ans += group.size() * (group.size() - 1) / 2;
        group.clear();
        l++;
      } else {
        group.insert(h[r].second);
        r++;
      }
    }
    ans += group.size() * (group.size() - 1) / 2;
    l = 0;
    r = 0;
    group.clear();
    while (l < pathh.size() && r < v.size()) {
      if (pathh[l] < v[r].second) {
        ans += group.size() * (group.size() - 1) / 2;
        group.clear();
        l++;
      } else {
        group.insert(v[r].first);
        r++;
      }
    }
    ans += group.size() * (group.size() - 1) / 2;
    cout << ans << endl;
  }
}
