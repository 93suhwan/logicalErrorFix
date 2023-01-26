#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long INF = 1e18;
const long double EPS = 1e-8;
const long double Pi = acosl(-1);
const long long P = 31;
const long long dx[4] = {0, 0, 1, -1};
const long long dy[4] = {1, -1, 0, 0};
const long long N = 1e3;
long long qqq = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long n, m, color[N][N], c, dist[N][N], curd[N][N], dp[20][1 << 20];
void solve() {
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (is_sorted(a.begin() + 1, a.end())) {
    cout << 0 << '\n';
    return;
  }
  for (long long i = 1; i <= n; i++) {
    if (i & 1) {
      for (long long j = 1; j <= n - 2; j += 2) {
        if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
      }
    } else {
      for (long long j = 2; j <= n - 1; j += 2) {
        if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
      }
    }
    if (is_sorted(a.begin() + 1, a.end())) {
      cout << i << '\n';
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> qqq;
  while (qqq--) {
    solve();
  }
  return 0;
}
