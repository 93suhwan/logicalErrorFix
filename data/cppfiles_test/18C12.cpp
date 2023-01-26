#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
}
long long quick_mod(long long A, long long B) {
  long long ret = 1;
  A %= MOD;
  while (B) {
    if (B & 1) ret = ret * A % MOD;
    B >>= 1;
    A = A * A % MOD;
  }
  return ret;
}
inline void chkmin(long long &x, long long y) { x = min(x, y); }
inline void chkmax(long long &x, long long y) { x = max(x, y); }
inline void add(long long &x, long long y) { x = (x + y) % MOD; }
inline long long rev(long long x) { return quick_mod(x, MOD - 2); }
inline int lowbit(int x) { return x & (-x); }
int N, K;
pair<int, int> P[111];
int hv[222];
void solve() {
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> P[i].first >> P[i].second;
    if (P[i].first > P[i].second) swap(P[i].first, P[i].second);
  }
  memset(hv, 0, sizeof(hv));
  for (int i = 0; i < K; ++i) hv[P[i].first] = hv[P[i].second] = 1;
  for (int i = 1; i <= N * 2; ++i) hv[i] = hv[i - 1] + hv[i];
  int ans = (N - K) * (N - K - 1) / 2;
  for (int i = 0; i < K; ++i)
    for (int j = i + 1; j < K; ++j) {
      int a = P[i].first, b = P[i].second, c = P[j].first, d = P[j].second;
      if ((a < c && c < b && b < d) || (c < a && a < d && d < b)) {
        ans++;
      }
    }
  for (int i = 0; i < K; ++i) {
    int a = P[i].first, b = P[i].second;
    int sum = hv[b - 1] - hv[a];
    int x = b - a - 1 - sum, y = N * 2 - K * 2 - x;
    ans += min(x, y);
  }
  cout << ans << endl;
}
int main(void) {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
