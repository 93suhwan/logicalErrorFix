#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long dp[N][2];
struct segment {
  int l, r;
};
auto cmp = [](segment& s1, segment& s2) {
  if (s1.r != s2.r)
    return s1.r < s2.r;
  else
    return s1.l > s2.l;
};
void solve() {
  int n, m;
  cin >> n >> m;
  long long p[n + 2];
  for (int i = 1; i <= n; i++) cin >> p[i];
  p[0] = -1e10;
  p[n + 1] = 1e10;
  sort(p, p + n + 2);
  vector<segment> s;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    if (lower_bound(p, p + n + 2, l) != upper_bound(p, p + n + 2, r)) continue;
    s.push_back((segment){l, r});
  }
  sort(s.begin(), s.end(), cmp);
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1].l >= s[i].l || s[i - 1].r == s[i].r)
      s.erase(s.begin() + i), i--;
  }
  long long dp[n + 2][2];
  for (int i = 1; i <= n + 1; i++) dp[i][0] = dp[i][1] = 1e15;
  dp[0][0] = dp[0][1] = 0;
  int now = 0;
  for (int i = 1; i < n + 2; i++) {
    vector<long long> l, r;
    l.push_back(p[i - 1]);
    while (now < s.size() && s[now].r < p[i]) {
      l.push_back(s[now].l);
      r.push_back(s[now].r);
      now++;
    }
    r.push_back(p[i]);
    for (int j = 0; j < l.size(); j++) {
      dp[i][0] =
          min(dp[i][0], dp[i - 1][0] + (l[j] - p[i - 1]) + 2 * (p[i] - r[j]));
      dp[i][1] =
          min(dp[i][1], dp[i - 1][0] + (l[j] - p[i - 1]) + (p[i] - r[j]));
      dp[i][0] = min(dp[i][0],
                     dp[i - 1][1] + 2 * (l[j] - p[i - 1]) + 2 * (p[i] - r[j]));
      dp[i][1] =
          min(dp[i][1], dp[i - 1][1] + 2 * (l[j] - p[i - 1]) + (p[i] - r[j]));
    }
  }
  cout << min(dp[n + 1][0], dp[n + 1][1]) << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
