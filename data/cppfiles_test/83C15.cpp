#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = N * 2 + 10, K = 6, P1 = 998244353, P2 = 1e9 + 7;
long long n;
int ans = 0;
int del[K + 1][M], sum[K + 1][M], tot[K + 1];
void Add(int &first, int second) {
  if ((first += second) >= P2) first -= P2;
}
void Sub(int &first, int second) {
  if ((first -= second) < 0) first += P2;
}
string To_string(int first, int second) {
  string num;
  for (int i = 0; i < second; i++, first /= 10) {
    num.push_back(first % 10);
  }
  reverse(num.begin(), num.end());
  return num;
}
void dfs1(int now, int len, int &rank) {
  if (len > K) return;
  rank++;
  del[len][++tot[len]] = (rank - now + P1) % P1;
  for (int i = 0; i < 10; i++) dfs1(now * 10 + i, len + 1, rank);
  return;
}
void dfs2(long long now, int &rank) {
  if (now > n) return;
  if (now * N * 10 > n && now * N + N - 1 <= n) {
    int p10 = 1, res = rank;
    for (int i = 0; i <= K; i++) {
      int d = (rank - 1ll * now * p10 % P1 + P1) % P1;
      int p = lower_bound(del[i] + 1, del[i] + tot[i] + 1, P1 - d) - del[i];
      Add(ans, 1ll * tot[i] * d % P2);
      Add(ans, sum[i][tot[i]]);
      Sub(ans, 1ll * (tot[i] - p + 1) * P1 % P2);
      (res += p10) %= P1;
      p10 *= 10;
    }
    rank = res;
  } else {
    rank = (rank + 1) % P1;
    Add(ans, (rank - now % P1 + P1) % P1);
    for (int i = 0; i < 10; i++) dfs2(now * 10 + i, rank);
  }
  return;
}
int main() {
  scanf("%lld", &n);
  int cnt = 0;
  dfs1(0, 0, cnt);
  for (int i = 0; i <= K; i++) {
    sort(del[i] + 1, del[i] + tot[i] + 1);
    for (int j = 1; j <= tot[i]; j++)
      sum[i][j] = (sum[i][j - 1] + del[i][j]) % P2;
  }
  cnt = 0;
  for (int i = 1; i < 10; i++) dfs2(i, cnt);
  printf("%d\n", ans);
  return 0;
}
