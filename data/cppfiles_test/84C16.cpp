#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int maxn = 100000;
long long phi[maxn + 1];
long long cp[maxn + 1];
long long dp[21][maxn + 1];
int ceil(int a, int b) {
  if (!a) return 0;
  return (a - 1) / b + 1;
}
long long f(int L, int R) {
  int k = 1;
  int r = R;
  long long ans = 0;
  while (k * k <= R && r > L) {
    int nr = R / (k + 1);
    uax(nr, L);
    ans += cp[k] * (r - nr);
    r = nr;
    ++k;
  }
  for (int i = (int)(L); i <= (int)(r); ++i) ans += cp[R / i];
  return ans;
}
void dnc(int k, int L, int R, int l, int r) {
  if (L >= R) return;
  int M = (L + R) / 2;
  int bestp = -1;
  int ptr = min(M, r);
  long long ff = f(ptr + 1, M);
  while (ptr >= l) {
    if (uin(dp[k][M], dp[k - 1][ptr] + ff)) {
      bestp = ptr;
    }
    if (ptr) ff += cp[M / ptr];
    --ptr;
  }
  dnc(k, L, M, l, bestp);
  dnc(k, M + 1, R, bestp, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  for (int i = 1; i <= (int)(maxn); ++i) phi[i] = i;
  for (int i = 1; i <= (int)(maxn); ++i)
    for (int j = (int)(2); j <= (int)(maxn / i); ++j) phi[i * j] -= phi[i];
  cp[1] = 1;
  for (int i = (int)(2); i <= (int)(maxn); ++i) cp[i] = cp[i - 1] + phi[i];
  for (int j = 0; j < (int)(21); ++j)
    for (int i = 0; i < (int)(maxn + 1); ++i) dp[j][i] = 1e18;
  dp[0][0] = 0;
  for (int k = (int)(1); k <= (int)(20); ++k) {
    dnc(k, 0, maxn + 1, 0, maxn + 1);
  }
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k > 20)
      cout << n << '\n';
    else
      cout << dp[k][n] << '\n';
  }
  return 0;
}
