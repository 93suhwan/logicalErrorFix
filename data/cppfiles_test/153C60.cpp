#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c;
  int sign = 1;
  do {
    c = getchar();
    if (c == '-') sign = -1;
  } while (!isdigit(c));
  do {
    x = x * 10 + c - '0', c = getchar();
  } while (isdigit(c));
  x *= sign;
}
const int mod = 998244353;
int n, m;
void FWT_OR(int *a, int sign) {
  for (int k = n, len = 1 << (n - 1); k >= 1; --k, len >>= 1)
    for (int i = 0; i < m; i += 1 << k)
      for (int j = i; j < i + len; ++j)
        a[j + len] = (a[j + len] + a[j] * sign) % mod;
}
int F[26][30], G[1 << 24];
char str[20005];
int ans[1 << 24];
int main() {
  read(n);
  m = 1 << n;
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    int len = strlen(str);
    for (int j = 0; j < len; ++j) F[str[j] - 'a'][i]++;
    for (int j = 0; j < 26; ++j) F[j][i]++;
  }
  for (int i = 1; i < m; ++i) ans[i] = 1;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < n; ++j) G[1 << j] = F[i][j];
    for (int k = 1; k < m; ++k) {
      int p = k & (-k);
      if (p != k) G[k] = min(G[p], G[p ^ k]);
      ans[k] = 1LL * ans[k] * G[k] % mod;
    }
  }
  for (int i = 1; i < m; ++i) {
    int cnt = 0;
    for (int j = i; j; j >>= 1)
      if (j & 1) cnt++;
    if (cnt % 2 == 0) ans[i] = mod - ans[i];
  }
  FWT_OR(ans, 1);
  long long ANS = 0;
  for (int i = 1; i < m; ++i) {
    int k = 0, sum = 0;
    for (int j = i, t = 1; j; j >>= 1, ++t)
      if (j & 1) k++, sum += t;
    k *= sum;
    ANS ^= 1LL * ans[i] * k;
  }
  cout << ANS;
  return 0;
}
