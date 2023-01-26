#include <bits/stdc++.h>
using namespace std;
int _lg2(long long n) { return floor(log2(n)); }
int _lg(long long n) { return floor(log(n)); }
int _rt(long long n) { return (n < 4 * 1e18 ? floor(sqrt(n)) : -1); }
bool check(int n, int m, vector<vector<int>> &p, int x) {
  bool chk1 = 1, chk2 = 0;
  vector<bool> chk(m);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++)
      if (p[i][j] >= x) {
        chk[j] = 1;
        cnt++;
      }
    if (cnt >= 2) chk2 = 1;
  }
  for (int i = 0; i < m; i++)
    if (!chk[i]) chk1 = 0;
  return bool(chk1 && chk2);
}
int solve(int n, int m, int mx, vector<vector<int>> &p) {
  if (n <= 0 || m < 2) return -1;
  int s = 0, e = mx, ans = 0;
  while (s <= e) {
    int mid = (s + e) / 2;
    bool chk = check(n, m, p, mid);
    if (chk) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, mx;
    cin >> n >> m;
    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> p[i][j];
        mx = max(mx, p[i][j]);
      }
    cout << solve(n, m, mx, p) << "\n";
  }
  return 0;
}
