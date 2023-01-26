#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcountll(nValue);
}
inline int bitnum(long long nValue) { return __builtin_popcountll(nValue); }
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  if (a == 0) return 0;
  return 64 - __builtin_clzll(a);
}
inline int bitmaxl(long long a) {
  if (a == 0) return 0;
  return 64 - __builtin_clzll(a);
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int maxn = 3010;
const int maxk = 110;
const int mod = 998244353;
long long dp[2][maxn][maxn], fac[maxn], invfac[maxn];
int n, k;
int b[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  fac[0] = invfac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = pow(fac[i], mod - 2, mod);
  }
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  int now = 0, nxt = 1;
  dp[now][0][0] = 1;
  int rd = -1;
  for (int i = 0; i < n; i++) {
    int be_rk = max(0, b[i] - k);
    int en_rk = min(i - rd, b[i] + k);
    int rbe_rk = i == 0 ? 0 : max(0, b[i - 1] - k);
    int ren_rk = i == 0 ? 0 : min(i - rd + 1, b[i - 1] + k);
    rd = max(i - en_rk, rd);
    for (int j = 0; j <= i; j++)
      for (int rk = be_rk; rk <= en_rk; rk++)
        if (dp[now][j][rk]) {
          dp[nxt][j][rk] += (rk + j) * dp[now][j][rk];
          dp[nxt][j][rk] %= mod;
          add(dp[nxt][j + 1][rk], dp[now][j][rk], mod);
        }
    for (int j = -1; j <= i + 1; j++) {
      long long sumdp = 0;
      for (int rk = rbe_rk; rk <= min(ren_rk, be_rk - 2); rk++) {
        const int rj = j + be_rk - rk;
        if (rj < 0) break;
        sumdp = (sumdp + dp[now][rj][rk]) * rj;
        sumdp %= mod;
      }
      for (int rk = ren_rk + 1; rk <= be_rk - 2; rk++) {
        sumdp *= j + be_rk - rk;
        sumdp %= mod;
      }
      for (int rk = max(be_rk, 1); rk <= en_rk && j + be_rk - (rk - 1) >= 0;
           rk++) {
        const long long rj = j + be_rk - (rk - 1);
        dp[nxt][rj][rk] += sumdp;
        if (rk - 1 >= rbe_rk && rk - 1 <= ren_rk)
          dp[nxt][rj][rk] += dp[now][rj][rk - 1];
        while (dp[nxt][rj][rk] > mod) dp[nxt][rj][rk] -= mod;
        if ((rk - 1) <= ren_rk && (rk - 1) >= rbe_rk)
          sumdp += dp[now][rj][rk - 1];
        sumdp *= rj;
        sumdp %= mod;
      }
    }
    for (int j = 0; j <= i + 1; j++)
      for (int rk = rbe_rk; rk <= ren_rk; rk++) {
        dp[now][j][rk] = 0;
      }
    swap(now, nxt);
  }
  long long ans = 0;
  for (int j = 0; j <= n; j++)
    for (int rk = 0; rk + j <= n; rk++) {
      if (rk > b[n - 1] + k || rk < b[n - 1] - k) continue;
      ans += dp[now][j][rk] * fac[n - rk] % mod * invfac[n - rk - j] % mod;
      ans %= mod;
    }
  cout << ans << endl;
  return 0;
}
