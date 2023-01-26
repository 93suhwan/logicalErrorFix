#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<long long int>> &p, long long int mid, long long int n,
           long long int m) {
  vector<long long int> visited(n);
  bool once = false;
  bool twice = false;
  for (long long int i = 0; i < m; i++) {
    once = false;
    for (long long int j = 0; j < n; j++) {
      if (p[i][j] >= mid) {
        if (once) {
          twice = true;
        }
        once = true;
        visited[j] = true;
      }
    }
  }
  if (twice == false) return false;
  for (long long int i = 0; i < n; i++) {
    if (visited[i] == false) return false;
  }
  return true;
}
void solve() {
  long long int m, n;
  cin >> m >> n;
  vector<vector<long long int>> p(m, vector<long long int>(n));
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  long long int st = 1;
  long long int e = 1e9;
  long long int mid = (st + e) / 2;
  long long int ans = mid;
  while (st < e) {
    long long int mid = (st + e) / 2;
    if (check(p, mid, n, m)) {
      ans = mid;
      st = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  if (check(p, ans + 1, n, m)) ans++;
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
