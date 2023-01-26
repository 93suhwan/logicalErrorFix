#include <bits/stdc++.h>
using namespace std;
long long get() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long N = 2005;
long long n, m, a[N][N], L[N][N], R[N][N], S[N][N];
char s[N];
struct Vector {
  long long x, y;
  Vector(long long a = 0, long long b = 0) { x = a, y = b; }
  Vector operator-(Vector b) { return Vector(x - b.x, y - b.y); }
  long double slope() { return (long double)1.0 * y / x; }
};
Vector q[N << 1];
long long l, r;
long long pw2(long long x) { return x * x; }
void push(long long x, long long y) {
  while (l < r && (q[r] - q[r - 1]).slope() >= (Vector(x, y) - q[r]).slope())
    r--;
  q[++r] = Vector(x, y);
}
void clear() { l = 1, r = 0; }
void solve(long long nowx) {
  clear();
  for (long long i = 1; i <= n; i++) {
    if (L[i][nowx]) push(i, pw2(nowx - L[i][nowx]) + pw2(i));
    if (R[i][nowx] && (!L[i][nowx] || R[i][nowx] - nowx != nowx - L[i][nowx]))
      push(i, pw2(R[i][nowx] - nowx) + pw2(i));
  }
  for (long long i = 1; i <= n; i++) {
    while (l < r && (long double)2.0 * i > (q[l + 1] - q[l]).slope()) ++l;
    S[i][nowx] = q[l].y - 2ll * i * q[l].x + i * i;
  }
}
signed main() {
  n = get() + 1, m = get() + 1;
  for (long long i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (long long j = 1; j <= m; j++) a[i][j] = s[j] - '0';
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (a[i][j])
        L[i][j] = j;
      else
        L[i][j] = L[i][j - 1];
    }
    for (long long j = m; j >= 1; j--) {
      if (a[i][j])
        R[i][j] = j;
      else
        R[i][j] = R[i][j + 1];
    }
  }
  for (long long i = 1; i <= m; i++) solve(i);
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += S[i][j];
  cout << ans;
  return 0;
}
