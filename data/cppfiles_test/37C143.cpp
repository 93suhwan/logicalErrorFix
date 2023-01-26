#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const long long INF = 1e18 + 56;
const long long NINF = -1 * INF;
void solve(long long t) {
  long long n, q;
  cin >> n >> q;
  vector<long long> vis(n + 1, 0);
  long long a, b, c;
  for (long long i = 1; i <= q; i++) {
    cin >> a >> b >> c;
    vis[b] = 1;
  }
  long long indices = 0;
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      indices = i;
      break;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (i != indices) {
      cout << indices << " " << i << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(), cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
