#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long inf = 1e9;
const long long MOD = 1e9 + 7;
long long x[maxn], y[maxn];
pair<long long, long long> p[maxn];
bool col(long long u, long long v, long long w) {
  return ((x[v] - x[u]) * (y[w] - y[u]) == (x[w] - x[u]) * (y[v] - y[u]));
}
double dis(long long u, long long v) {
  return sqrt((p[u].first - p[v].first) * (p[u].first - p[v].first) +
              (p[u].second - p[v].second) * (p[u].second - p[v].second));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  k--;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  long long X = x[k], Y = y[k];
  if (n > 3) {
    long long cnt = 0;
    for (long long i = 2; i < n; i++) {
      if (col(0, 1, i)) cnt++;
    }
    if (cnt < n - 3) {
      swap(x[0], x[2]);
      swap(x[1], x[3]);
      swap(y[0], y[2]);
      swap(y[1], y[3]);
    }
  }
  long long key = 0;
  for (long long i = 2; i < n; i++) {
    if (!col(0, 1, i)) {
      key = i;
      break;
    }
  }
  swap(x[0], x[key]);
  swap(y[0], y[key]);
  for (long long i = 0; i < n; i++) {
    p[i].first = x[i];
    p[i].second = y[i];
  }
  sort(p + 1, p + n);
  long long K = 0;
  for (long long i = 1; i <= n; i++) {
    if (p[i].first == X && p[i].second == Y) K = i;
  }
  if (K == 0) {
    cout << min(dis(0, 1), dis(0, n - 1)) + dis(1, n - 1) << endl;
    return 0;
  }
  double ans =
      dis(1, n - 1) + min(dis(1, K) + dis(n - 1, 0), dis(K, n - 1) + dis(1, 0));
  for (long long i = 1; i < K; i++) {
    ans = min(ans, dis(1, i) + dis(i, 0) + dis(i + 1, n - 1) +
                       min(dis(0, i + 1) + dis(K, n - 1),
                           dis(0, n - 1) + dis(K, i + 1)));
  }
  for (long long i = n - 1; i > K; i--) {
    ans =
        min(ans, dis(n - 1, i) + dis(i, 0) + dis(i - 1, 1) +
                     min(dis(0, i - 1) + dis(K, 1), dis(0, 1) + dis(K, i - 1)));
  }
  cout << setprecision(10) << fixed << ans << endl;
  return 0;
}
