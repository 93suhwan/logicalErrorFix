#include <bits/stdc++.h>
using namespace std;
int inp[3010], a[3010], dp[3010][3010];
int n;
vector<pair<int, pair<int, int> > > v;
void solve() {
  cin >> n;
  v.clear();
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cin >> inp[i];
    if (inp[i] != a[cur]) {
      cur++;
      a[cur] = inp[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) dp[i][j] = 0;
  }
  n = cur;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] == a[j]) v.push_back(make_pair(j - i, make_pair(i, j)));
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    pair<int, pair<int, int> > P = v[i];
    pair<int, int> p = P.second;
    dp[p.first][p.second] = 2;
    for (int j = 0; j < i; j++) {
      pair<int, pair<int, int> > Q = v[j];
      pair<int, int> q = Q.second;
      if (q.first > p.first and q.second < p.second)
        dp[p.first][p.second] =
            max(dp[p.first][p.second], 2 + dp[q.first][q.second]);
    }
    ans = max(ans, dp[p.first][p.second]);
  }
  cout << cur - 1 - ans / 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
