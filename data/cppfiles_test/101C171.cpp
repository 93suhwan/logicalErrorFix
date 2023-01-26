#include <bits/stdc++.h>
using namespace std;
long long int solve(int k, int n, vector<int> &a, vector<vector<int>> &p,
                    int x) {
  map<int, int> mp;
  long long int total, i, j, ans = 0;
  mp.clear();
  total = 0, i = 0, j = 0;
  while (j < k) {
    if (i < n && j < k) {
      if (a[i] <= p[j][x]) {
        mp.clear();
        total = 0;
        while (j < k && p[j][x] == a[i]) j++;
        i++;
      } else {
        ans += total - mp[p[j][!x]];
        total++;
        mp[p[j][!x]]++;
        j++;
      }
      continue;
    }
    if (i >= n) {
      while (j < k) {
        ans += total - mp[p[j][!x]];
        total++;
        mp[p[j][!x]]++;
        j++;
      }
      break;
    }
  }
  return ans;
}
bool comp(vector<int> &x, vector<int> &y) {
  if (x[1] == y[1]) return x[0] < y[0];
  return x[1] < y[1];
}
long long Ynot() {
  long long ans = 0;
  long long n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  vector<vector<int>> p(k, vector<int>(2));
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < k; i++) {
    cin >> p[i][0] >> p[i][1];
  }
  sort(p.begin(), p.end());
  ans += solve(k, n, a, p, 0);
  sort(p.begin(), p.end(), comp);
  ans += solve(k, m, b, p, 1);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long ans = 0;
    ans = Ynot();
    cout << ans << '\n';
  }
}
