#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e18 + 123;
const long double EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 2e5 + 123;
const int M = 1e6 + 123;
const double pi = 3.14159265359;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, a[N];
long long k;
void solve() {
  cin >> n >> k;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  long long first = min(k / n, a[1] + 0ll);
  sum -= a[1] - first;
  vector<int> d;
  for (int i = n; sum > k; i--) {
    sum -= a[i] - first;
    d.push_back(a[i]);
  }
  long long ans = INF;
  while (1) {
    ans = min(ans, a[1] - first + (int)d.size());
    if (!d.empty()) {
      long long s = d.back() - first;
      d.pop_back();
      sum += s;
      if (sum > k) {
        long long z = (sum - k + (int)d.size()) / ((int)d.size() + 1);
        first -= z;
        sum -= z * ((int)d.size() + 1);
      }
    } else {
      break;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
