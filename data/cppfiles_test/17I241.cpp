#include <bits/stdc++.h>
using namespace std;
const long long int infinity = 1e18;
long long int toceil(long long int x, long long int y) {
  return (x + y - 1) / y;
}
long long int in() {
  long long int data;
  cin >> data;
  return data;
}
void debug(vector<int>& a) {
  for (auto x : a) cout << x << " ";
  cout << "\n";
  ;
}
long long int n;
vector<vector<int> > dp;
vector<vector<int> > v;
long long int lans = -infinity;
long long int recur(long long int i, long long int take, long long int indi,
                    long long int a, long long int b, long long int ans) {
  if (i == n) return 0;
  if (dp[i][take] != -1) return dp[i][take];
  long long int d = 0;
  long long int k;
  for (k = 0; k < 5; k++) {
    if (k != indi) d += v[i][k];
  }
  long long int x;
  if (a + v[i][indi] >= b + d) {
    ans++;
  }
  lans = max(ans, lans);
  (recur(i + 1, 0, indi, a, b, ans),
   recur(i + 1, 1, indi, a + v[i][indi], b + d, ans));
  return dp[i][take] = ans;
}
void solve() {
  long long int i, j;
  long long int n;
  cin >> n;
  vector<vector<int> > v(n + 1, vector<int>(5));
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) {
      cin >> v[i][j];
    }
  }
  long long int k;
  vector<int> winer;
  for (i = 0; i < 5; i++) {
    vector<pair<int, int> > r;
    for (j = 0; j < n; j++) {
      r.push_back({v[j][i], j});
    }
    sort(r.begin(), r.end());
    ;
    for (j = 0; j < min(10ll, n); j++) {
      winer.push_back(r[n - 1 - j].second);
    }
  }
  map<long long int, bool> check;
  long long int dn = winer.size();
  for (i = 0; i < dn; i++) {
    bool flag = false;
    for (auto j = 0; j < dn; j++) {
      if (winer[j] == winer[i]) continue;
      long long int w = 0;
      for (k = 0; k < 5; k++) {
        if (v[winer[i]][k] < v[winer[j]][k]) w++;
      }
      if (w < 3) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cout << winer[i] + 1 << "\n";
      ;
      return;
    }
  }
  cout << -1 << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(8);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
