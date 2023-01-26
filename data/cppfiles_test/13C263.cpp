#include <bits/stdc++.h>
using namespace std;
int check(int K, int K1) {
  if (K < 0 || K1 < 0) return 0;
  if (K & 1) return 0;
  return 1;
}
void solve(int n, int m, int K, int K1) {
  int tn = n, tm = m;
  char ans[n + 1][m + 1];
  memset(ans, '0', sizeof(ans));
  int cnt = 0;
  if (n & 1 && !(m & 1)) {
    for (int i = 1; i <= m && K > 0; i += 2, K--) {
      ans[n][i] = ans[n][i + 1] = 'a' + (cnt++ % 2);
    }
    n--;
  }
  if (m & 1 && !(n & 1)) {
    cnt = 0;
    for (int i = 1; i <= n && K1 > 0; i += 2, K1--) {
      ans[i][m] = ans[i + 1][m] = 'a' + (cnt++ % 2);
    }
    m--;
  }
  cnt = 0;
  for (int i = 1; i <= n && K > 0; i += 2) {
    for (int j = 1; j <= m && K > 0; j += 2) {
      ans[i][j] = ans[i][j + 1] = 'c' + (cnt++ % 4);
      ans[i + 1][j] = ans[i + 1][j + 1] = 'c' + (cnt++ % 4);
      K -= 2;
    }
  }
  cnt = 0;
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      if (ans[i][j] != '0') continue;
      while (ans[i - 1][j] == 'g' + (cnt % 4) ||
             ans[i][j - 1] == 'g' + (cnt % 4))
        cnt++;
      ans[i][j] = ans[i + 1][j] = 'g' + (cnt++ % 4);
      ans[i][j + 1] = ans[i + 1][j + 1] = 'g' + (cnt++ % 4);
    }
  }
  for (int i = 1; i <= tn; i++) {
    for (int j = 1; j <= tm; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
int main() {
  int T, n, m, K;
  cin >> T;
  while (T--) {
    cin >> n >> m >> K;
    int K1 = n * m / 2 - K;
    int tn = n, tm = m, tK = K, tK1 = K1;
    if (n & 1 && !(m & 1)) K -= m / 2, n--;
    if (m & 1 && !(n & 1)) K1 -= n / 2, m--;
    if (check(K, K1)) {
      puts("YES");
      solve(tn, tm, tK, tK1);
    } else
      puts("NO");
  }
  return 0;
}
