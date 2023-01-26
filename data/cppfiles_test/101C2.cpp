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
    h.clear();
    v.clear();
    pathv.resize(n);
    pathh.resize(m);
    for (int i = 0; i < n; i++) {
      cin >> pathv[i];
      ve[pathv[i]] = true;
    }
    for (int i = 0; i < m; i++) {
      cin >> pathh[i];
      he[pathh[i]] = true;
    }
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
    long long l = 0, r = 0, curr = 1, group = 0;
    vector<pair<int, int>> bl;
    while (l < pathv.size() && r < h.size()) {
      if (pathv[l] < h[r].first) {
        ans += group * (group - 1) / 2;
        group = 0;
        l++;
      } else {
        bl.push_back({l, h[r].second});
        group++;
        r++;
      }
    }
    ans += group * (group - 1) / 2;
    sort(bl.begin(), bl.end());
    for (int i = 1; i < bl.size(); i++) {
      if (bl[i - 1].first == bl[i].first && bl[i - 1].second == bl[i].second)
        curr++;
      else {
        ans -= curr * (curr - 1) / 2;
        curr = 1;
      }
    }
    ans -= curr * (curr - 1) / 2;
    curr = 1;
    l = 0;
    r = 0;
    curr = 1, group = 0;
    bl.clear();
    while (l < pathh.size() && r < v.size()) {
      if (pathh[l] < v[r].second) {
        ans += group * (group - 1) / 2;
        group = 0;
        l++;
      } else {
        bl.push_back({l, v[r].first});
        group++;
        r++;
      }
    }
    ans += group * (group - 1) / 2;
    sort(bl.begin(), bl.end());
    for (int i = 1; i < bl.size(); i++) {
      if (bl[i - 1].first == bl[i].first && bl[i - 1].second == bl[i].second)
        curr++;
      else {
        ans -= curr * (curr - 1) / 2;
        curr = 1;
      }
    }
    ans -= curr * (curr - 1) / 2;
    curr = 1;
    cout << ans << endl;
  }
}
