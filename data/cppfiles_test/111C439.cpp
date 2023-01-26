#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, maxn = 200030;
int aabs(int x) {
  if (x < 0) return -x;
  return x;
}
long long pow(long long x, long long a) {
  long long now = 1;
  while (a) {
    if (a % 2) now = now * x % mod;
    x = x * x % mod;
    a >>= 1;
  }
  return now;
}
int t;
char s[200];
int n;
int cnt = 0;
void dfs(int l, int r) {
  if (l >= r) {
    printf("%s\n", s);
    cnt++;
    return;
  }
  s[l] = '(';
  s[r] = ')';
  dfs(l + 1, r - 1);
  s[l] = '\0';
  s[r] = '\0';
  if (cnt == n) return;
  if (l + 1 != r) {
    s[l] = '(';
    s[l + 1] = ')';
    dfs(l + 2, r);
    s[l + 1] = '\0';
    s[l] = '\0';
    if (cnt == n) return;
  }
  return;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    cnt = 0;
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    dfs(0, 2 * n - 1);
  }
  return 0;
}
