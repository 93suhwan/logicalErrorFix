#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long n, k, dp[12][(1 << 10)][3][12], a[12], cnt, res = 0;
bool check(long long msk, long long cur) {
  long long cnt = 0;
  while (msk) {
    cnt += (msk & 1);
    msk >>= 1;
  }
  return (cnt <= cur);
}
void calc(long long i, long long msk, long long c, long long cur) {
  dp[i][msk][c][cur] = 0;
  if (i == 0) {
    dp[i][msk][c][cur] = check(msk, cur);
    return;
  }
  for (long long j = 0; j <= 9; j++) {
    long long msk2;
    if (msk == 0 && j == 0)
      msk2 = 0;
    else
      msk2 = msk | (1 << j);
    if (dp[i - 1][msk2][c][cur] == -1) calc(i - 1, msk2, c, cur);
    dp[i][msk][c][cur] |= dp[i - 1][msk2][c][cur];
  }
}
void calc2(long long i, long long msk, long long c, long long cur) {
  dp[i][msk][c][cur] = 0;
  if (i == 0) {
    dp[i][msk][c][cur] = check(msk, cur);
    return;
  }
  for (long long j = a[i]; j <= 9; j++) {
    long long msk2;
    if (msk == 0 && j == 0)
      msk2 = 0;
    else
      msk2 = msk | (1 << j);
    if (a[i] == j && dp[i - 1][msk2][c & (a[i] == j)][cur] == -1) {
      calc2(i - 1, msk2, c & (a[i] == j), cur);
    }
    dp[i][msk][c][cur] |= dp[i - 1][msk2][c & (a[i] == j)][cur];
  }
}
void print_result(long long i, long long msk, long long c) {
  if (i == 0) {
    return;
  }
  if (c == 0)
    for (long long j = 0; j <= 9; j++) {
      long long msk2;
      if (msk == 0 && j == 0)
        msk2 = 0;
      else
        msk2 = msk | (1 << j);
      if (dp[i - 1][msk2][c][k] == 1) {
        res *= 10;
        res += j;
        print_result(i - 1, msk2, c);
        break;
      }
    }
  else
    for (long long j = a[i]; j <= 9; j++) {
      long long msk2;
      if (msk == 0 && j == 0)
        msk2 = 0;
      else
        msk2 = msk | (1 << j);
      if (dp[i - 1][msk2][c & (a[i] == j)][k] == 1) {
        res *= 10;
        res += j;
        print_result(i - 1, msk2, c & (a[i] == j));
        break;
      }
    }
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= 10; i++) a[i] = 0;
  long long j = 0;
  while (n > 0) {
    a[++j] = n % 10;
    n /= 10;
  }
  calc2(j + 1, 0LL, 1LL, k);
  print_result(j + 1, 0LL, 1LL);
  cout << res << "\n";
  res = 0;
  for (long long i = 0; i <= j + 1; i++)
    for (long long msk = 0; msk <= (1 << 10); msk++) dp[i][msk][1][k] = -1;
}
int main() {
  memset(dp, -1, sizeof(dp));
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 10; i++) calc(10LL, 0LL, 0LL, i);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "\n" << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}
