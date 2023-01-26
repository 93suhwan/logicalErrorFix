#include <bits/stdc++.h>
const long long N = 2e5 + 5, MOD = 1e9 + 7, INF = LONG_MAX;
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n, m, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &it : a) cin >> it;
    long long ans = -1e9;
    for (long long i = max(0LL, n - 1000); i < n; ++i) {
      for (long long j = i + 1; j < n; ++j)
        ans = max(ans, ((i + 1) * (j + 1)) - m * (a[i] | a[j]));
    }
    cout << ans << '\n';
  }
}
