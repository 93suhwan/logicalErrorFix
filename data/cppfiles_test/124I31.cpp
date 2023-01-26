#include <bits/stdc++.h>
using namespace std;
const int N = 2000 * 2 + 5, D = 1e9 + 7;
char s[N], t[N];
long long C[N][N];
int k[N], b[N];
long long F(int k, int b, int x) {
  x -= b;
  if (x < 0 || x > k) return 0;
  return C[k][x];
}
long long check(int pk, int pb, int sk, int sb) {
  long long ans = 0;
  for (int d = 1;; ++d) {
    long long x = F(pk, pb, d) * F(sk, sb, -d) % D;
    if (!x) break;
    ans += x * d;
  }
  return ans % D;
}
int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % D;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    scanf("%d%s%s", &n, s + 1, t + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      k[i] = k[i - 1];
      b[i] = b[i - 1];
      if (s[i] == '?')
        ++k[i];
      else if ((s[i] == '1') ^ (i % 2))
        ++b[i];
      if (t[i] == '?') {
        --b[i];
        ++k[i];
      } else if ((t[i] == '1') ^ (i % 2))
        --b[i];
    }
    for (int i = 1; i < n; ++i) {
      int pk = k[i], pb = b[i], sk = k[n] - pk, sb = b[n] - pb;
      ans += check(pk, pb, sk, sb) + check(sk, sb, pk, pb);
    }
    cout << ans % D << endl;
  }
}
