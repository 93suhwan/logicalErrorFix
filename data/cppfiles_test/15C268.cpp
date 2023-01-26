#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.second != b.second)
    return (a.second < b.second);
  else
    return (a.first > b.first);
}
bool bysec(const pair<pair<long long int, long long int>, string> &a,
           const pair<pair<long long int, long long int>, string> &b) {
  if (a.first.first == b.first.first) {
    return a.first.second > a.first.second;
  }
  return (a.first.first < b.first.first);
}
long long int tt = 1;
void solve() {
  long long int n, m, d;
  cin >> n >> m >> d;
  string a[n];
  long long int mp[n][m];
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) mp[i][j] = 0;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      long long int l = i, k = j;
      long long int cur1 = -1, cur2 = -1;
      while (l >= 0 && k >= 0 && (a[l][k] == '*')) {
        l--;
        k--;
        cur1++;
      }
      l = i;
      k = j;
      while (l >= 0 && k < m && a[l][k] == '*') {
        l--;
        k++;
        cur2++;
      }
      long long int cur = min({cur1, cur2});
      l = i, k = j;
      long long int t = 0;
      if (cur < d) continue;
      while (t <= cur) {
        mp[l][k] = 1;
        l--;
        k--;
        t++;
      }
      l = i, k = j;
      t = 0;
      while (t <= cur) {
        mp[l][k] = 1;
        l--;
        k++;
        t++;
      }
    }
  }
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++)
      if (mp[i][j] == 0 && a[i][j] == '*') {
        cout << "NO" << '\n';
        return;
      }
  cout << "YES" << '\n';
  ;
}
signed main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cout.tie(0);
  ;
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    tt++;
  }
}
