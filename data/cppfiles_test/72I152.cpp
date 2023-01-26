#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long n, k, dp[12][(1 << 10)][3], a[12], cnt, res = 0;
bool check(long long msk) {
  long long cnt = 0;
  while (msk) {
    cnt += (msk & 1);
    msk >>= 1;
  }
  return (cnt <= k);
}
void calc(long long i, long long msk, long long c) {
  dp[i][msk][c] = 0;
  if (i == 0) {
    dp[i][msk][c] = check(msk);
    return;
  }
  if (c == 0)
    for (long long j = 0; j <= 9; j++) {
      long long msk2;
      if (msk == 0 && j == 0)
        msk2 = 0;
      else
        msk2 = msk | (1 << j);
      if (dp[i - 1][msk2][c] == -1) calc(i - 1, msk2, c);
      dp[i][msk][c] |= dp[i - 1][msk2][c];
    }
  else
    for (long long j = a[i]; j <= 9; j++) {
      long long msk2;
      if (msk == 0 && j == 0)
        msk2 = 0;
      else
        msk2 = msk | (1 << j);
      if (dp[i - 1][msk2][c & (a[i] == j)] == -1)
        calc(i - 1, msk2, c & (a[i] == j));
      dp[i][msk][c] |= dp[i - 1][msk2][c & (a[i] == j)];
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
      if (dp[i - 1][msk2][c] == 1) {
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
      if (dp[i - 1][msk2][c & (a[i] == j)] == 1) {
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
  calc(j + 1, 0LL, 1LL);
  print_result(j + 1, 0LL, 1LL);
  for (long long i = 1; i <= j + 1; i++)
    for (long long msk = 0; msk <= (1 << 10); msk++)
      for (long long c = 0; c <= 1; c++) dp[i][msk][c] = -1;
  cout << res << "\n";
  res = 0;
}
int main() {
  memset(dp, -1, sizeof(dp));
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "\n" << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}
