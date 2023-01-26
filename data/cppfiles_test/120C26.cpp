#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
const int N = (int)1e5 + 1;
void TimeExecution() {
  cout << "\n\n===>> Time Execution: " << clock() / (double)1000 << " sec(s).";
}
inline long long fpow(long long n, long long k) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n;
    n = n * n;
  }
  return r;
}
long long sqr(long long a) { return a * a; }
long long msqr(long long a) { return ((a % MOD) * (a % MOD)) % MOD; }
long long msub(long long a, long long b) { return ((a - b) % MOD + MOD) % MOD; }
long long madd(long long a, long long b) { return (a + b) % MOD; }
long long mmul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
int cal(int x, int s) {
  int cnt = 0;
  int len = (1 << s);
  return (x / len + 1) * (len / 2) -
         max(0, ((x / len) * len + (len / 2) - 1 - x));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = INF;
    int len = floor(log2(r)) + 1;
    while (len) {
      int v1 = cal(r, len);
      int v2 = cal(l - 1, len);
      ans = min(ans, cal(r, len) - cal(l - 1, len));
      len--;
    }
    cout << ans << '\n';
  }
  return 0;
}
