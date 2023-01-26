#include <bits/stdc++.h>
using namespace std;
int N, f[61][6];
int main() {
  cin >> N;
  for (int i = 0; i <= 5; i++) f[1][i] = 1;
  for (int i = 2; i <= N; i++)
    for (int j = 0; j <= 5; j++)
      for (int k = 0; k <= 5; k++)
        if (j != k && ((j ^ k) != 1))
          for (int l = 0; l <= 5; l++)
            if (j != l && ((j ^ l) != 1))
              f[i][j] =
                  (f[i][j] + 1ll * f[i - 1][k] * f[i - 1][l]) % 1000000007;
  int ans = 0;
  for (int i = 0; i <= 5; i++) ans = (ans + f[N][i]) % 1000000007;
  cout << ans << '\n';
  return 0;
}
