#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6) + 10;
const int K = 2005;
const long long MOD = int(1e9) + 7;
const int INF = int(1e9) + 5;
const long long INF64 = 2e18;
inline long long add(long long a, long long b, long long m) {
  return (((a % m + b % m) % m + m) % m);
}
inline long long mul(long long a, long long b, long long m) {
  return (((a % m * b % m) % m + m) % m);
}
bool ok(int mid, vector<vector<int>> &prizes) {
  int m = int((prizes).size()) - 1;
  int n = int((prizes[0]).size()) - 1;
  vector<int> satisfied(n + 1, 0);
  bool multi = false;
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (prizes[i][j] >= mid) {
        satisfied[j] = 1;
        cnt++;
      }
    }
    if (cnt > 1) multi = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!satisfied[i]) multi = false;
  }
  return multi;
}
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> prizes(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> prizes[i][j];
    }
  }
  int l = 1, r = int(1e9), ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid, prizes)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
