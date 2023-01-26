#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1000 * 1000 + 13;
int n;
int p[N], a[N];
int dp[N][2][2];
pair<int, int> pr[N][2][2];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) scanf("%d", &p[i]);
  for (int i = 0; i < int(n); ++i)
    for (int pos = 0; pos < int(2); ++pos)
      for (int sg = 0; sg < int(2); ++sg) dp[i][pos][sg] = INF;
  dp[0][0][0] = dp[0][0][1] = -INF;
  for (int i = 0; i < int(n - 1); ++i)
    for (int pos = 0; pos < int(2); ++pos)
      for (int sg = 0; sg < int(2); ++sg)
        if (dp[i][pos][sg] != INF) {
          for (int nsg = 0; nsg < int(2); ++nsg) {
            int x = sg ? -p[i] : p[i];
            int y = dp[i][pos][sg];
            if (pos) swap(x, y);
            int z = nsg ? -p[i + 1] : p[i + 1];
            if (z > x) {
              if (dp[i + 1][0][nsg] > y) {
                dp[i + 1][0][nsg] = y;
                pr[i + 1][0][nsg] = make_pair(pos, sg);
              }
            } else if (z > y) {
              if (dp[i + 1][1][nsg] > x) {
                dp[i + 1][1][nsg] = x;
                pr[i + 1][1][nsg] = make_pair(pos, sg);
              }
            }
          }
        }
  int pos = -1, sg = -1;
  for (int j = 0; j < int(2); ++j)
    for (int k = 0; k < int(2); ++k)
      if (dp[n - 1][j][k] != INF) pos = j, sg = k;
  if (pos == -1) {
    puts("NO");
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    a[i] = sg ? -p[i] : p[i];
    tie(pos, sg) = pr[i][pos][sg];
  }
  puts("YES");
  for (int i = 0; i < int(n); ++i) printf("%d ", a[i]);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
