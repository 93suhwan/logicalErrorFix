#include <bits/stdc++.h>
using namespace std;
inline int lowbit(int x) { return x & -x; }
const int N = 1e5 + 5;
long long bit[N], n;
void add(int x, int val) {
  for (int i = x; i <= n; i += lowbit(i)) bit[i] += val;
}
long long sum(int x) {
  long long ret = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ret += bit[i];
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> a(n);
    fill(bit, bit + n + 1, 0);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      add(i + 1, a[i]);
    }
    int maxk = sqrt(n * 2) + 1;
    vector<vector<long long>> dp(n, vector<long long>(maxk + 1, -1));
    dp[n - 1][1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      dp[i][1] = max(dp[i + 1][1], (long long)(a[i]));
      for (int j = 2; j <= maxk && i + j < n; j++) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        long long s = sum(i + j) - sum(i);
        if (s < dp[i + j][j - 1]) {
          dp[i][j] = max(dp[i][j], s);
        }
      }
    }
    for (int k = maxk; k >= 1; k--) {
      if (dp[0][k] != -1) {
        printf("%d\n", k);
        break;
      }
    }
  }
  return 0;
}
