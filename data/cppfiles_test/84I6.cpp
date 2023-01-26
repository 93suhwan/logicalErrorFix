#include <bits/stdc++.h>
using namespace std;
char buf[100000], *p1(buf), *p2(buf);
inline long long read() {
  long long x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  return f ? x : -x;
}
using ll = long long;
const long long N = 1e5 + 10;
const ll INF = 1e18;
long long n, t, k;
ll dp[N][20], p[N];
long long cnt;
ll phi[N], prm[N];
bitset<N> vis;
inline void prep(const long long lim) {
  phi[1] = 1;
  for (long long i = 2; i <= lim; i++) {
    if (!vis[i]) prm[++cnt] = i, phi[i] = i - 1;
    for (long long j = 1; j <= cnt && i * prm[j] <= lim; j++) {
      vis[i * prm[j]] = true;
      if (i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      }
      phi[i * prm[j]] = phi[i] * (prm[j] - 1);
    }
  }
  for (long long i = 1; i <= lim; i++) p[i] = p[i - 1] + phi[i];
  return;
}
inline ll C(const long long lef, const long long rig) {
  if (lef > rig) return INF;
  ll ret = 0;
  for (long long l = lef, r; l <= rig; l = r + 1) {
    r = (rig / (rig / l));
    ret += (r - l + 1) * p[rig / l];
  }
  return ret;
}
void cdq(long long o, long long lef, long long rig, long long oplef,
         long long oprig) {
  if (lef > rig) return;
  long long mid = (lef + rig) >> 1;
  dp[mid][o] = INF;
  ll va = C(min(mid, oprig) + 1, mid);
  long long op = oplef;
  for (long long k = min(mid, oprig); k >= oplef; k--) {
    ll tem = dp[k][o - 1] + va;
    if (tem <= dp[mid][o]) dp[mid][o] = tem, op = k;
    if (k <= mid) {
      if (va == INF)
        va = p[mid / k];
      else
        va += p[mid / k];
    }
  }
  cdq(o, lef, mid - 1, oplef, op);
  cdq(o, mid + 1, rig, op, oprig);
  return;
}
inline void init() {
  prep(N - 1);
  n = 100000;
  for (long long i = 1; i <= n; i++) dp[i][0] = INF;
  for (long long i = 1; i <= n; i++) dp[i][1] = (ll)i * (i + 1) / 2;
  for (long long i = 2; i <= 16; i++) cdq(i, 1, n, 1, n);
  return;
}
inline void input() {
  n = read(), k = read();
  return;
}
inline void work() {
  if (k >= 19 || (1 << k) >= n) return cout << n << '\n', void();
  cout << dp[n][k] << '\n';
  return;
}
inline void solve() {
  init();
  long long t = read();
  while (t--) {
    input();
    work();
  }
  return;
}
int main() {
  solve();
  return 0;
}
