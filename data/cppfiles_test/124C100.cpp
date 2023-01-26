#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003, M = 1000000007;
int n;
char a[N], b[N];
int q[N][N];
int dp[N][N];
int pq[N][N];
int sumq(int x1, int x2, int y1_, int y2) {
  int ans = pq[x2][y2];
  if (x1 - 1 >= 0) ans = (ans - pq[x1 - 1][y2]) % M;
  if (y1_ - 1 >= 0) ans = (ans - pq[x2][y1_ - 1]) % M;
  if (x1 - 1 >= 0 && y1_ - 1 >= 0) ans = (ans + pq[x1 - 1][y1_ - 1]) % M;
  return ans;
}
int pdp[N][N];
int sumdp(int x1, int x2, int y1_, int y2) {
  int ans = pdp[x2][y2];
  if (x1 - 1 >= 0) ans = (ans - pdp[x1 - 1][y2]) % M;
  if (y1_ - 1 >= 0) ans = (ans - pdp[x2][y1_ - 1]) % M;
  if (x1 - 1 >= 0 && y1_ - 1 >= 0) ans = (ans + pdp[x1 - 1][y1_ - 1]) % M;
  return ans;
}
void solv() {
  cin >> n;
  cin >> (a + 1) >> (b + 1);
  for (int i = 2; i <= n; i += 2) {
    if (a[i] == '1')
      a[i] = '0';
    else if (a[i] == '0')
      a[i] = '1';
  }
  for (int i = 2; i <= n; i += 2) {
    if (b[i] == '1')
      b[i] = '0';
    else if (b[i] == '0')
      b[i] = '1';
  }
  vector<pair<int, int> > va;
  va.push_back(make_pair(-1, -1));
  for (int i = 1; i <= n; ++i) {
    if (a[i] == '0') continue;
    if (a[i] == '1')
      va.push_back(make_pair(i, 1));
    else
      va.push_back(make_pair(i, 0));
  }
  vector<pair<int, int> > vb;
  vb.push_back(make_pair(-1, -1));
  for (int i = 1; i <= n; ++i) {
    if (b[i] == '0') continue;
    if (b[i] == '1')
      vb.push_back(make_pair(i, 1));
    else
      vb.push_back(make_pair(i, 0));
  }
  vector<int> ua;
  ua.push_back(0);
  for (int i = 1; i < ((int)(va).size()); ++i) {
    if (va[i - 1].second == 1)
      ua.push_back(i - 1);
    else
      ua.push_back(ua.back());
  }
  vector<int> ub;
  ub.push_back(0);
  for (int i = 1; i < ((int)(vb).size()); ++i) {
    if (vb[i - 1].second == 1)
      ub.push_back(i - 1);
    else
      ub.push_back(ub.back());
  }
  q[0][0] = 1;
  for (int i = 0; i < ((int)(va).size()); ++i) pq[i][0] = 1;
  for (int j = 0; j < ((int)(vb).size()); ++j) pq[0][j] = 1;
  dp[0][0] = 0;
  for (int i = 1; i < ((int)(va).size()); ++i) {
    for (int j = 1; j < ((int)(vb).size()); ++j) {
      q[i][j] = sumq(ua[i], i - 1, ub[j], j - 1);
      dp[i][j] = (sumdp(ua[i], i - 1, ub[j], j - 1) +
                  abs(va[i].first - vb[j].first) * 1LL * q[i][j]) %
                 M;
      pq[i][j] = (pq[i - 1][j] + pq[i][j - 1]) % M;
      pq[i][j] = (pq[i][j] - pq[i - 1][j - 1]) % M;
      pq[i][j] = (pq[i][j] + q[i][j]) % M;
      pdp[i][j] = (pdp[i - 1][j] + pdp[i][j - 1]) % M;
      pdp[i][j] = (pdp[i][j] - pdp[i - 1][j - 1]) % M;
      pdp[i][j] = (pdp[i][j] + dp[i][j]) % M;
    }
  }
  int ans = 0;
  for (int i = ((int)(va).size()) - 1; i >= 1; --i) {
    for (int j = ((int)(vb).size()) - 1; j >= 1; --j) {
      ans = (ans + dp[i][j]) % M;
      if (vb[j].second == 1) break;
    }
    if (va[i].second == 1) break;
  }
  ans = (ans + M) % M;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solv();
  }
  return 0;
}
