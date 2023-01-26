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
  vector<long long> point;
  vector<pair<long long, long long> > seg;
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
  int now = 0, last = 0;
  if (seg[now].second < point[0]) {
    come_back = 2 * (point[0] - seg[now].second);
    none = point[0] - seg[now].second;
    now++;
    last = -1;
  }
  for (long long i = 1; i < n; i++) {
    vector<pair<long long, long long> > tmp;
    while (now < m && seg[now].second < point[i]) {
      if (seg[now].first > point[i - 1]) {
        tmp.push_back(seg[now]);
      }
      now++;
    }
    if (tmp.empty()) {
      come_back = min(come_back, none);
      last = i;
      continue;
    }
    long long t_come_back = none + 2 * (point[i] - tmp[0].second),
              t_none = none + point[i] - tmp[0].second, ri = -(long long)(4e18);
    for (long long j = 0; j < tmp.size() - 1; j++) {
      ri = max(ri, (long long)tmp[j].first);
      t_come_back = min(t_come_back, ri - point[i - 1] + come_back +
                                         2 * (point[i] - tmp[j + 1].second));
      t_come_back = min(t_come_back, 2 * (ri - point[i - 1]) + none +
                                         2 * (point[i] - tmp[j + 1].second));
      t_none = min(t_none, ri - point[i - 1] + come_back +
                               (point[i] - tmp[j + 1].second));
      t_none = min(t_none, 2 * (ri - point[i - 1]) + none +
                               (point[i] - tmp[j + 1].second));
      if (last == i - 1) {
        t_none = min(t_none,
                     ri - point[i - 1] + none + (point[i] - tmp[j + 1].second));
        t_come_back = min(t_come_back, ri - point[i - 1] + none +
                                           2 * (point[i] - tmp[j + 1].second));
      }
    }
    ri = max(ri, tmp[tmp.size() - 1].first);
    long long c = t_come_back, n = t_none;
    bool cc = 0, nn = 0;
    if (last == i - 1) {
      if (t_none == ri - point[i - 1] + none) nn = 1;
      if (t_come_back == ri - point[i - 1] + none) cc = 1;
      t_none = min(t_none, ri - point[i - 1] + none);
      t_come_back = min(t_come_back, ri - point[i - 1] + none);
    }
    if (t_none == come_back + ri - point[i - 1]) nn = 1;
    if (t_none == none + 2 * (ri - point[i - 1])) nn = 1;
    if (t_come_back == come_back + ri - point[i - 1]) cc = 1;
    if (t_come_back == none + 2 * (ri - point[i - 1])) cc = 1;
    t_come_back = min(t_come_back, come_back + ri - point[i - 1]);
    t_come_back = min(t_come_back, none + 2 * (ri - point[i - 1]));
    t_none = min(t_none, come_back + ri - point[i - 1]);
    t_none = min(t_none, none + 2 * (ri - point[i - 1]));
    if (n > t_none) last = i;
    if (n == none && nn) {
      last = i;
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
    come_back = min(2 * maxn + none, maxn + come_back);
    none = (long long)(4e18);
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
