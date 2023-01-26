#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1000000007;
const char nl = '\n';
const long long MX = 100001;
long long powi(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return res;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
vector<long long> second[100005];
bool check(long long p, vector<vector<long long>>& matrix, long long n,
           long long m) {
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (m); j++) {
      if (p <= matrix[j][i]) {
        second[i].push_back(j);
      }
    }
  }
  bool first = 0;
  long long cnt = 0;
  for (long long j = 0; j < (m); j++) {
    for (long long i = 0; i < (n); i++) {
      if (second[i].empty()) break;
      bool f2 = 0;
      for (auto u : second[i]) {
        if (u == j) {
          f2 = 1;
          break;
        }
      }
      if (f2 == 1) {
        cnt++;
      }
    }
    if (cnt > 1) return true;
    cnt = 0;
  }
  return false;
}
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long>> matrix(m, vector<long long>(n));
  for (long long i = 0; i < (m); i++) {
    for (long long j = 0; j < (n); j++) cin >> matrix[i][j];
  }
  if (n - 1 >= m) {
    long long mini = 1;
    long long cmini = 1e18;
    for (long long j = 0; j < (n); j++) {
      mini = 1;
      for (long long i = 0; i < (m); i++) {
        mini = max(mini, matrix[i][j]);
      }
      cmini = min(mini, cmini);
    }
    cout << cmini << "\n";
    return;
  }
  long long st = 1;
  long long end = 1e10;
  long long ans = 1;
  while (st <= end) {
    for (long long i = 0; i < (n + 1); i++) second[i].clear();
    long long mid = st + (end - st) / 2;
    if (check(mid, matrix, n, m)) {
      st = mid + 1;
      ans = max(ans, mid);
    } else {
      end = mid - 1;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
