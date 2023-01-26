#include <bits/stdc++.h>
using namespace std;
const long long xxx = 1e3;
const long long maxn = xxx + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
const double Pi = acos(-1.0);
inline void updmin(long long& a, long long b) { a > b ? a = b : 0; }
inline void updmax(long long& a, long long b) { a < b ? a = b : 0; }
long long dp[maxn][maxn];
long long n, k;
inline long long getmi(long long x, long long k) {
  return (long long)ceil(log(x) / log(k));
}
long long getres(long long x, long long y) {
  if (dp[x][y]) {
    return dp[x][y];
  }
  long long mix = getmi(x, k), miy = getmi(y, k);
  if (miy != mix) {
    return miy;
  }
  long long bas = 1;
  while (bas * k < x) {
    bas *= k;
  }
  if (((x + bas - 1) / bas) == ((y + bas - 1) / bas)) {
    return getres((x - 1) % bas + 1, (y - 1) % bas + 1);
  } else {
    return miy;
  }
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Cases;
  Cases = 1;
  for (int cas = 1; cas <= Cases; cas++) {
    cin >> n >> k;
    cout << (long long)ceil(log((double)n) / log((double)k)) << "\n";
    for (long long i = 1; i <= k; i++) {
      for (long long j = i + 1; j <= k; j++) {
        dp[i][j] = 1;
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        cout << getres(i, j) << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
