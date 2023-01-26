#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int MaxN = 5e5 + 5;
int T, N, Ans;
int F[MaxN], G[MaxN], H[MaxN];
int main() {
  int i, x;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 0; i <= N; i++) F[i] = G[i] = H[i] = 0;
    for (Ans = 0, i = 1; i <= N; i++) {
      scanf("%d", &x);
      F[x] = (F[x] << 1) % Mod;
      G[x] = (G[x] << 1) % Mod;
      H[x] = (H[x] << 1) % Mod;
      if (!x) F[0]++;
      if (x == 1) G[1]++;
      if (x) F[x] = (F[x] + F[x - 1]) % Mod;
      if (x > 1) {
        G[x] = (G[x] + F[x - 2]) % Mod;
        G[x] = (G[x] + H[x - 2]) % Mod;
      }
      if (x + 2 <= N) H[x] = (H[x] + G[x + 2]) % Mod;
    }
    for (i = 0; i <= N; i++) {
      Ans = (Ans + F[i]) % Mod;
      Ans = (Ans + G[i]) % Mod;
      Ans = (Ans + H[i]) % Mod;
    }
    printf("%d\n", Ans);
  }
  return 0;
}
