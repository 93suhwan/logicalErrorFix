#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 3e5 + 5;
int n, m;
int a[maxn];
char s[maxn];
int main() {
  n = yh();
  for (int i = (1), iss = (n); i <= iss; i++) a[i] = yh();
  int p = 0;
  scanf("%s", s + 1);
  for (int i = (2), iss = (n); i <= iss; i++)
    if (s[i] != s[i - 1]) p++;
  sort(a + 1, a + 1 + n);
  int l = n - p, r = n - p;
  cout << a[l--] << " " << s[1] << '\n';
  char prv = s[1];
  for (int i = (2), iss = (n); i <= iss; i++) {
    if (s[i] == s[i - 1]) {
      cout << a[l--] << " " << (prv = 'L' + 'R' - prv) << '\n';
    } else {
      cout << a[++r] << " " << s[i] << '\n';
    }
  }
  return 0;
}
