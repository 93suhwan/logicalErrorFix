#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long mod = 998244353;
const long double pi = 3.14159265359;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
long long n, k, t, x, y, z, m, p;
long long solve(vector<pair<int, int>> m, vector<int> r) {
  long long ans = 0;
  map<int, int> mm;
  map<int, int> ch;
  for (int i = 0; i < m.size(); i++) {
    int cur = 1, cntr = 0;
    int idx = lower_bound(r.begin(), r.end(), m[i].first) - r.begin();
    if (ch[idx] == 0) {
      ans += mm[idx];
      continue;
    }
    for (int j = i + 1; j < m.size(); j++) {
      if (m[j].second != m[i].second) {
        if (m[j].first > r[idx - 1] && m[j].first < r[idx]) {
          cntr++;
        }
      }
      if (m[j].first > r[idx]) {
        break;
      }
    }
    ch[idx] = 1;
    mm[idx] = cntr;
    ans += cntr;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    vector<int> rx, ry;
    vector<pair<int, int>> vx, vy;
    map<int, int> mx, my;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      rx.push_back(a);
      mx[a] = 1;
    }
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      ry.push_back(a);
      my[a] = 1;
    }
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      if (mx[x] && my[y]) {
        continue;
      }
      if (mx[x]) {
        vx.push_back({y, x});
      }
      if (my[y]) {
        vy.push_back({x, y});
      }
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(rx.begin(), rx.end());
    sort(ry.begin(), ry.end());
    cout << solve(vx, ry) + solve(vy, rx) << endl;
  }
}
