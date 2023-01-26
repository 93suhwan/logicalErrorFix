#include <bits/stdc++.h>
using namespace std;
void file() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> point;
  vector<pair<int, int> > seg;
  for (long long i = 0; i < n; i++) {
    int x;
    cin >> x;
    point.push_back(x);
  }
  for (long long i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    seg.push_back({l, r});
  }
  sort(point.begin(), point.end());
  sort(seg.begin(), seg.end(), cmp);
  long long come_back = 0, none = 0;
  int now = 0;
  if (seg[now].second < point[0]) {
    come_back = 2 * (point[0] - seg[now].second);
    none = point[0] - seg[now].second;
    now++;
  }
  for (long long i = 1; i < n; i++) {
    vector<pair<int, int> > tmp;
    while (now < m && seg[now].second < point[i]) {
      if (seg[now].first > point[i - 1]) {
        tmp.push_back(seg[now]);
      }
      now++;
    }
    if (tmp.empty()) {
      come_back = none;
      continue;
    }
    long long t_come_back = none + 2 * (point[i] - tmp[0].second),
              t_none = none + point[i] - tmp[0].second, ri = 0;
    for (long long j = 0; j < tmp.size(); j++) {
      ri = max(ri, (long long)tmp[j].first);
      t_come_back =
          min(t_come_back, ri + come_back + 2 * (point[i] - tmp[j].second));
      t_none = min(t_none, ri + come_back + (point[i] - tmp[j].second));
    }
    come_back = t_come_back;
    none = t_none;
  }
  long long maxn = 0;
  while (now < m) {
    if (seg[now].first > point[n - 1])
      maxn = max(maxn, (long long)seg[now].first - point[n - 1]);
    now++;
  }
  if (maxn != 0) {
    come_back += maxn;
    none = (long long)(1e9 + 5);
  }
  cout << min(come_back, none) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
