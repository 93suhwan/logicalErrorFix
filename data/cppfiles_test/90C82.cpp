#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    vector<long long> v;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      v.push_back(a[i]);
    }
    int b[m][2];
    for (int i = 0; i < m; ++i) {
      cin >> b[i][0] >> b[i][1];
      v.push_back(b[i][0]);
      v.push_back(b[i][1]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++i) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for (int i = 0; i < m; ++i) {
      b[i][0] = lower_bound(v.begin(), v.end(), b[i][0]) - v.begin() + 1;
      b[i][1] = lower_bound(v.begin(), v.end(), b[i][1]) - v.begin() + 1;
    }
    sort(a, a + n);
    int pre[v.size() + 5];
    memset(pre, 0, sizeof(pre));
    int p = 0;
    for (int i = 1; i < v.size() + 2; ++i) {
      pre[i] += pre[i - 1];
      if (p < n && i == a[p]) {
        ++pre[i];
        ++p;
      }
    }
    vector<pair<int, int> > seg;
    for (int i = 0; i < m; ++i) {
      if (pre[b[i][0] - 1] == pre[b[i][1]]) {
        seg.push_back(make_pair(b[i][0], b[i][1]));
      }
    }
    sort(seg.begin(), seg.end());
    if (seg.size() == 0) {
      cout << 0 << '\n';
      continue;
    }
    long long dp[seg.size() + 5];
    for (int i = 0; i < seg.size() + 5; ++i) {
      dp[i] = 1e16;
    }
    for (int i = 0; i < n; ++i) {
      int lower = lower_bound(seg.begin(), seg.end(), make_pair(a[i], -1)) -
                  seg.begin() - 1;
      int upper = lower + 1;
      long long low2x = 1e16, lowx = 1e16;
      if (lower == -1) {
        low2x = lowx = 0;
      }
      long long cur = v[a[i] - 1];
      while (lower != -1) {
        low2x = min(low2x, (v[a[i] - 1] - cur) * 2 + dp[lower]);
        lowx = min(lowx, (v[a[i] - 1] - cur) + dp[lower]);
        cur = min(cur, (long long)v[seg[lower].second - 1]);
        if ((i != 0 && seg[lower].first < a[i - 1])) break;
        --lower;
      }
      if (lower == -1) {
        low2x = min(low2x, (v[a[i] - 1] - cur) * 2);
        lowx = min(lowx, (v[a[i] - 1] - cur));
      }
      if (upper != 0) {
        dp[upper - 1] = min(dp[upper - 1], lowx);
      }
      cur = v[a[i] - 1];
      while (upper != seg.size()) {
        if (upper == seg.size() || (i != n - 1 && seg[upper].first > a[i + 1]))
          break;
        cur = max(cur, (long long)v[seg[upper].first - 1]);
        dp[upper] = min(dp[upper], low2x + cur - v[a[i] - 1]);
        dp[upper] = min(dp[upper], lowx + (cur - v[a[i] - 1]) * 2);
        ++upper;
      }
    }
    cout << dp[seg.size() - 1] << '\n';
  }
}
