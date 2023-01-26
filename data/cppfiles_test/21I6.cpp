#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
char ss[1 << 24], *A = ss, *B = ss;
inline char gc() {
  return A == B && (B = (A = ss) + fread(ss, 1, 1 << 24, stdin), A == B) ? EOF
                                                                         : *A++;
}
template <class T>
void maxa(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
void mina(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void read(T &x) {
  int f = 1, c;
  while (c = gc(), c < 48 || c > 57)
    if (c == '-') f = -1;
  x = (c ^ 48);
  while (c = gc(), c > 47 && c < 58) x = x * 10 + (c ^ 48);
  x *= f;
}
const int mo = 1e9 + 7;
long long fsp(int x, int y) {
  if (y == 1) return x;
  long long ans = fsp(x, y / 2);
  ans = ans * ans % mo;
  if (y % 2 == 1) ans = ans * x % mo;
  return ans;
}
struct cp {
  long long x, y;
  cp operator+(cp B) { return (cp){x + B.x, y + B.y}; }
  cp operator-(cp B) { return (cp){x - B.x, y - B.y}; }
  long long operator*(cp B) { return x * B.y - y * B.x; }
  int half() { return y < 0 || (y == 0 && x < 0); }
};
struct re {
  int a, b, c;
};
long long dp[110][110][110];
bool t[110][110][110];
int C[110][110], jc[110];
int n, m, k, p;
long long dfs(int i, int j, int k) {
  if (i <= 1 || t[i][j][k]) return dp[i][j][k];
  if (j + k > i + 1) return 0;
  t[i][j][k] = 1;
  if (j != 1) {
    for (int i1 = 0; i1 <= i - 1; i1++)
      for (int k1 = 0; k1 <= k; k1++) {
        dp[i][j][k] += dfs(i1, j - 1, k1) * dfs(i - i1 - 1, j - 1, k - k1) % p *
                       C[i - 1][i1] % p;
      }
  } else {
    for (int i1 = 0; i1 <= i - 1; i1++)
      for (int k1 = 0; k1 <= k - 1; k1++) {
        dp[i][j][k] += dfs(i1, j - 1, k1) * dfs(i - i1 - 1, j - 1, k - k1 - 1) %
                       p * C[i - 1][i1] % p;
      }
  }
  dp[i][j][k] %= p;
  return dp[i][j][k];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> p;
  for (int i = 0; i <= 100; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  }
  jc[0] = 1;
  for (int i = 1; i <= 100; i++) jc[i] = 1ll * jc[i - 1] * i % p;
  for (int i = 0; i <= n; i++) dp[0][i][0] = 1;
  for (int i = 1; i <= n; i++) dp[i][0][0] = jc[i];
  for (int i = 1; i <= 1; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        if (j != 1) {
          for (int i1 = 0; i1 <= i - 1; i1++)
            for (int k1 = 0; k1 <= k; k1++) {
              dp[i][j][k] += dp[i1][j - 1][k1] * dp[i - i1 - 1][j - 1][k - k1] %
                             p * C[i - 1][i1] % p;
            }
        } else {
          for (int i1 = 0; i1 <= i - 1; i1++)
            for (int k1 = 0; k1 <= k - 1; k1++) {
              dp[i][j][k] += dp[i1][j - 1][k1] *
                             dp[i - i1 - 1][j - 1][k - k1 - 1] % p *
                             C[i - 1][i1] % p;
            }
        }
        dp[i][j][k] %= p;
      }
  cout << dfs(n, m, k) << endl;
  return 0;
}
