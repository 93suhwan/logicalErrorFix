#include <bits/stdc++.h>
using namespace std;
const int N = 2000007;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
int n, m, k, t, p;
int a[100007], b[100007];
queue<pair<int, int> > q[100007];
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) return a.second < b.second;
  return a.first > b.first;
}
vector<pair<int, int> > vv[100007];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n * m; i++) {
      cin >> a[i];
      v.push_back(a[i]);
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n * m);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n * m; i++) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
      b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
    }
    int res = 0;
    for (int i = 1; i <= n * m; i++) {
      int first = i / m;
      if (i % m == 0) {
        first--;
      }
      int second = i - first * m;
      first++;
      vv[b[i]].push_back({second, first});
    }
    int len = v.size();
    for (int i = 1; i <= len; i++) {
      sort(vv[i].begin(), vv[i].end(), cmp);
      for (auto j : vv[i]) {
        q[i].push(j);
      }
      vv[i].clear();
    }
    vector<int> cun[307];
    for (int i = 1; i <= n; i++) cun[i].clear();
    for (int i = 1; i <= n * m; i++) {
      int now = a[i];
      auto cl = q[now].front();
      q[now].pop();
      int posx = cl.second, posy = cl.first;
      for (auto j : cun[posx]) {
        if (j < now) res++;
      }
      cun[posx].push_back(now);
    }
    cout << res << "\n";
  }
  return 0;
}
