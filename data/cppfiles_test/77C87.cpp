#include <bits/stdc++.h>
using namespace std;
int D[4000002];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, MOD;
  cin >> N >> MOD;
  D[N] = 1;
  for (int i = N - 1; i > 0; i--) {
    D[i] = D[i + 1];
    for (int j = 2; i * j <= N; j++) {
      D[i] = D[i] + D[j * i] - D[min(j * (i + 1), N + 1)];
      if (D[i] >= MOD) D[i] -= MOD;
      if (D[i] < 0) D[i] += MOD;
    }
    D[i] += D[i + 1];
    if (D[i] >= MOD) D[i] -= MOD;
  }
  cout << (D[1] + MOD - D[2]) % MOD << '\n';
  return 0;
}
