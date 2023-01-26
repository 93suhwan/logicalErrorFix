#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const long long INF = (long long)1e8;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
const int N = (int)1e5 + 10;
void TimeExecution() {
  cout << "\n\n===>> Time Execution: " << clock() / (double)1000 << " sec(s).";
}
long long sqr(long long a) { return ((a % MOD) * (a % MOD)) % MOD; }
long long msub(long long a, long long b) { return ((a - b) % MOD + MOD) % MOD; }
long long madd(long long a, long long b) { return (a + b) % MOD; }
long long mmul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    pair<long long, long long> a[n + 1];
    long long ans = -LINF;
    for (int i = (1); i <= (n); i++) {
      long long val;
      cin >> val;
      a[i].first = val;
      a[i].second = i;
    }
    for (int i = (1); i <= (n - 1); i++)
      ans = max(ans, i * (i + 1) - k * (a[i].first | a[i + 1].first));
    sort(a + 1, a + 1 + n);
    for (int i = (1); i <= (n - 1); i++)
      ans = max(ans, i * (i + 1) - k * (a[i].first | a[i + 1].first));
    cout << ans;
    cout << '\n';
  }
  return 0;
}
