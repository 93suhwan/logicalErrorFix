#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T MAX(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
inline T MIN(T a, T b) {
  if (a < b) return a;
  return b;
}
template <class T>
inline T ABS(T x) {
  if (x < 0) return -x;
  return x;
}
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const static int INF = 2123123123;
int tc;
long long n, k;
long long a[12];
long long powI(long long a, long long b) {
  long long result = 1;
  for (int(i) = (0); (i) < (b); ++(i)) {
    result *= a;
  }
  return result;
}
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%I64d%I64d", &n, &k);
    for (int(i) = (0); (i) < (n); ++(i)) {
      scanf("%I64d", &a[i]);
    }
    long long result = 0;
    long long sisaK = k;
    for (int i = 0; i < n; i++) {
      if (i + 1 < n) {
        long long maxTime = powI(10, a[i + 1] - a[i]) - 1;
        long long times = min(maxTime, sisaK);
        sisaK -= times;
        result += powI(10, a[i]) * times;
        if (sisaK == 0) {
          result += powI(10, a[i]);
        }
      } else {
        if (sisaK > 0) {
          result += powI(10, a[i]) * (sisaK + 1);
        }
      }
    }
    printf("%I64d\n", result);
  }
  return 0;
}
