#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int INF = 0x3f3f3f3f;
int DP[2][maxn];
void Solve() {
  int n;
  scanf("%d", &n);
  memset(DP, 0, sizeof DP);
  while (n--) {
    int now = (n & 1);
    int next = (now ^ 1);
    memset(DP[next], INF, sizeof(int) * maxn);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < maxn; i++)
      if (DP[now][i] < INF) {
        DP[next][i] = min(DP[next][i], max(DP[now][i], num));
        DP[next][max(i, num)] = min(DP[next][max(i, num)], DP[now][i]);
      }
  }
  int ans = INF;
  for (int i = 0; i < maxn; i++) ans = min(ans, i + DP[1][i]);
  cout << ans << endl;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) Solve();
  return 0;
}
