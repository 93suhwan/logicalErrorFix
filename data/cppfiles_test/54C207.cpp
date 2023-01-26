#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long Lnf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T Abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
inline T GetMin(T tmp[], int l, int r) {
  T res = Inf;
  for (int i = l; i <= r; i++) res = min(res, tmp[i]);
  return res;
}
template <typename T>
inline T GetMax(T tmp[], int l, int r) {
  T res = -Inf;
  for (int i = l; i <= r; i++) res = max(res, tmp[i]);
  return res;
}
template <typename T>
inline T GetSum(T tmp[], int l, int r, int mod) {
  long long sum = 0;
  for (int i = l; i <= r; i++)
    if (mod == -1)
      sum += tmp[i];
    else
      sum = (sum + tmp) % mod;
  return sum;
}
template <typename T>
inline void GetFrac(T tmp[], int l, int r, int mod) {
  tmp[l - 1] = 1;
  for (int i = l; i <= r; i++) tmp[i] = (tmp[i - 1] * i) % mod;
}
template <typename T>
void Print(T tmp[], int l, int r, int type) {
  if (type == 1)
    for (int i = l; i <= r; i++) cout << tmp[i] << ' ';
  if (type == 2)
    for (int i = l; i <= r; i++) cout << tmp[i];
  if (type == 3)
    for (int i = l; i <= r; i++) cout << tmp[i] << '\n';
}
template <typename T>
void GetPrime(T prime[], bool vis[], int up, int &top) {
  top = 0;
  for (int i = 2; i <= up; i++) {
    if (!vis[i]) prime[++top] = i;
    for (int j = 1; j <= top && i * prime[j] <= up; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
void checkf(bool flag, string Y, string N) {
  cout << ((flag == true) ? Y : N) << '\n';
}
long long qpow(long long x, long long p, long long mod) {
  long long base = x, res = 1 % mod;
  while (p != 0) {
    if (p & 1) res = (res * base) % mod;
    p >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
const int Mod = 1e9 + 7;
const int base = 131;
const int maxn1 = 5e5 + 5;
const int maxn2 = 5000 + 5;
const int maxn3 = 500 + 5;
const int len = 100 + 5;
long long T, n, m, k;
int a[maxn1];
long long frac[maxn1];
long long sum[maxn1];
long long C(long long x, long long y) {
  if (y > x) return 0;
  long long ans = ((frac[x] * qpow(frac[y], Mod - 2, Mod)) % Mod *
                   qpow(frac[x - y], Mod - 2, Mod) % Mod);
  return ans;
}
long long Lucas(long long x, long long y) {
  if (y == 0)
    return 1;
  else
    return C(x, y) * Lucas(x / Mod, y / Mod) % Mod;
}
void solve() {
  scanf("%lld%lld", &n, &k);
  long long rest = 0, pre = 0, tot = 0;
  for (int i = 0; i < n; i += 2) pre = (pre + Lucas(n, i)) % Mod;
  if (n % 2 != 0) pre++;
  for (int i = 1; i < n; i += 2) tot = (tot + Lucas(n, i)) % Mod;
  for (int i = 1; i <= k; i++)
    rest = (rest + (qpow(pre, i - 1, Mod) * tot % Mod *
                    qpow(2, n * (k - i), Mod) % Mod)) %
           Mod;
  printf("%lld\n", ((qpow(2, n * k, Mod) - rest) + Mod) % Mod);
}
int main() {
  GetFrac(frac, 1, 200000, Mod);
  scanf("%lld", &T);
  while (T--) {
    solve();
  }
  return 0;
}
