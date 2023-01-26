#include <bits/stdc++.h>
using namespace std;
const long long losn = 1e6 + 5;
const long long maxn = 1e5 + 5;
const long long minn = 1e3 + 5;
const long long tiny = 1e2 + 5;
const long long zlosn = 1e6;
const long long zmaxn = 1e5;
const long long zminn = 1e3;
const long long ztiny = 1e2;
const long long inf = 1e9;
const long long binf = 1e18;
const long long mod = 1e9 + 7;
const long long lmod = 998244353;
const long long hashmod = 4698571;
const long long pi = 3.1415926;
const long long myn = 0;
void cl(long long &T, long long x) { T = x; }
void cl(long long &T) {
  scanf("%lld", &T);
  ;
}
void gk() { cout << "---------------" << endl; }
void ck() { cout << 1 << endl; }
void ck(long long a) { printf("%lld\n", a); }
void ck(int a) { printf("%d\n", a); }
void ck(char a) { printf("%c\n", a); }
void ck(string a) { cout << a << endl; }
void ck(long double a) { printf("%Lf\n", a); }
long long n, m, k, t, u, v, len, s, w;
long long dp[maxn][520];
long long arr[maxn];
long long ans[maxn * 5];
long long id = 0;
int main() {
  long long T;
  cl(T, 1);
  while (T--) {
    scanf("%lld", &n);
    ;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &arr[i]);
      ;
    }
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= 511; j++) {
        dp[i][j] = binf;
      }
    }
    dp[1][arr[1]] = arr[1];
    for (long long i = 2; i <= n; i++) {
      dp[i][arr[i]] = min(dp[i][arr[i]], arr[i]);
      for (long long j = 0; j <= 511; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      }
      for (long long j = 0; j <= 511; j++) {
        if (dp[i - 1][j] != binf) {
          if (dp[i - 1][j] <= arr[i]) {
            dp[i][j ^ arr[i]] = min(arr[i], dp[i][j ^ arr[i]]);
          }
        }
      }
    }
    vector<long long> q;
    long long id = 0;
    for (long long j = 0; j <= 511; j++) {
      if (dp[n][j] != binf) {
        ans[++id] = j;
      }
    }
    printf("%lld\n", id);
    for (long long i = 1; i <= id; i++) {
      printf("%lld ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
