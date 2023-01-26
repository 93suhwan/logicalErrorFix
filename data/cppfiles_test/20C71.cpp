#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 405;
const long long MOD = 998244353;
long long N, M;
long long sum[MAX][MAX];
long long getsum(long long y1, long long x1, long long y2, long long x2) {
  if (y1 > y2 || x1 > x2) {
    return 0;
  }
  return sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1];
}
void solve() {
  cin >> N >> M;
  for (int j = 1; j <= N; j++) {
    for (int i = 1; i <= M; i++) {
      sum[j][i] = 0;
    }
  }
  for (int j = 1; j <= N; j++) {
    string s;
    cin >> s;
    for (int i = 1; i <= M; i++) {
      if (s[i - 1] == '1') {
        sum[j][i] = 1;
      }
    }
  }
  for (int j = 1; j <= N; j++) {
    for (int i = 1; i <= M; i++) {
      sum[j][i] += sum[j][i - 1] + sum[j - 1][i] - sum[j - 1][i - 1];
    }
  }
  long long ans = LLINF;
  for (int j = 1; j <= N; j++) {
    for (int i = j + 4; i <= N; i++) {
      long long F[MAX];
      memset(F, 0, sizeof(F));
      for (int k = 4; k <= M; k++) {
        long long x = getsum(j + 1, 1, i - 1, k - 1) + k - 1 -
                      getsum(j, 1, j, k - 1) + k - 1 - getsum(i, 1, i, k - 1) +
                      i - j - 1 - getsum(j + 1, k, i - 1, k);
        F[k] = x;
      }
      for (int k = M; k >= 5; k--) {
        if (F[k] < F[k - 1]) {
          F[k - 1] = F[k];
        }
      }
      for (int k = 1; k <= M - 3; k++) {
        long long x = F[k + 3] - (k - getsum(j, 1, j, k)) -
                      (k - getsum(i, 1, i, k)) - getsum(j + 1, 1, i - 1, k) +
                      (i - j - 1 - getsum(j + 1, k, i - 1, k));
        ans = min(ans, x);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
