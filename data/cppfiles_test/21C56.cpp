#include <bits/stdc++.h>
using namespace std;
const int NMAX = 105;
long long Count[NMAX][NMAX][NMAX], comb[NMAX][NMAX], fact[NMAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, K, M, P, i, j, n, k, m, L, R, k1, k2, sum = 0;
  cin >> N >> M >> K >> P;
  Count[0][1][1] = 1;
  fact[0] = 1;
  for (i = 1; i <= N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % P;
  }
  comb[0][0] = 1;
  for (i = 1; i <= N; i++) {
    comb[i][i] = comb[i][0] = 1;
    for (j = 1; j < i; j++)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % P;
  }
  for (i = 0; i <= N; i++) {
    for (j = i + 1; j <= M; j++) {
      Count[i][j][0] = fact[i];
    }
  }
  for (n = 1; n <= N; n++) {
    Count[n][1][1] = fact[n];
    for (m = 2; m <= min(n, M); m++) {
      for (k = 0; k <= min(n, K); k++) {
        for (L = 0; L < (n + 1) / 2; L++) {
          sum = 0;
          for (k1 = max(0, k + L - n + 1); k1 <= min(k, L); k1++) {
            R = n - L - 1;
            k2 = k - k1;
            if (!Count[L][m - 1][k1] || !Count[R][m - 1][k2]) continue;
            int aux = (1LL * (1LL * Count[L][m - 1][k1] * Count[R][m - 1][k2]) %
                       P * comb[n - 1][L]) %
                      P;
            Count[n][m][k] += aux;
            if (L < n / 2) {
              sum += aux;
              if (sum >= P) sum -= P;
            }
            Count[n][m][k] %= P;
          }
          Count[n][m][k] += sum;
          Count[n][m][k] %= P;
        }
      }
    }
  }
  cout << Count[N][M][K];
  return 0;
}
