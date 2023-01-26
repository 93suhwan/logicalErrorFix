#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int T, N, Ans;
int A[2005], F[2005], G[2005], H[2005];
int main() {
  int i, j;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    memset(F, 0, sizeof(F));
    memset(G, 0, sizeof(G));
    memset(H, 0, sizeof(H));
    for (Ans = 0, i = 1; i <= N; i++) {
      scanf("%d", &A[i]);
      if (!A[i]) F[i] = 1;
      if (A[i] == 1) G[i] = 1;
      for (j = 1; j < i; j++) {
        if (A[j] == A[i] - 1) F[i] = (F[i] + F[j]) % Mod;
        if (A[j] == A[i] - 2) {
          G[i] = (G[i] + F[j]) % Mod;
          G[i] = (G[i] + H[j]) % Mod;
        }
        if (A[j] == A[i] + 2) H[i] = (H[i] + G[j]) % Mod;
        if (A[j] == A[i]) {
          F[i] = (F[i] + F[j]) % Mod;
          G[i] = (G[i] + G[j]) % Mod;
          H[i] = (H[i] + H[j]) % Mod;
        }
      }
      Ans = (Ans + F[i]) % Mod;
      Ans = (Ans + G[i]) % Mod;
      Ans = (Ans + H[i]) % Mod;
    }
    printf("%d\n", Ans);
  }
  return 0;
}
