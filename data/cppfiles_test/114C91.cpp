#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n, m;
int ed[20];
vector<int> v[20], ans;
set<pair<int, vector<int>>> s;
map<vector<int>, int> mp, st;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int x;
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    mp[v] = 1;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) ans.push_back(v[i].size());
  queue<vector<int>> q;
  q.push(ans);
  int now = 0;
  st[ans] = 1;
  while (q.size()) {
    auto x = q.front();
    q.pop();
    if (!mp.count(x)) {
      int all = 0;
      for (int i = 1; i <= n; i++) all += v[i][x[i - 1] - 1];
      if (all > sum) sum = all, ans = x;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (x[i - 1] > 1) {
        x[i - 1]--;
        if (st.count(x)) {
          x[i - 1]++;
          continue;
        }
        q.push(x);
        st[x] = 1;
        x[i - 1]++;
      }
    }
  }
  for (auto x : ans) cout << x << ' ';
  puts("");
  return 0;
}
