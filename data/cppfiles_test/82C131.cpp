#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int inf = 1 << 30;
const long long inff = 1ll << 60;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, q, l, r, f[N], ans;
char s[N];
vector<int> v[N << 2];
int main() {
  int tests = 1;
  tests = read();
  while (tests--) {
    n = read(), q = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      int fl = (i % 2 ? 1 : -1);
      if (s[i] == '+')
        f[i] = f[i - 1] + fl;
      else
        f[i] = f[i - 1] - fl;
      v[f[i - 1] + f[i] + n * 2].push_back(i);
    }
    while (q--) {
      l = read(), r = read();
      if (f[r] - f[l - 1] == 0)
        puts("0");
      else {
        if ((r - l + 1) % 2)
          puts("1");
        else
          printf("2\n%d ", r--);
        int le = 0, ri = v[f[r] + f[l - 1] + n * 2].size() - 1, mid;
        ans = ri;
        while (le <= ri) {
          mid = le + ri >> 1;
          if (v[f[r] + f[l - 1] + n * 2][mid] >= l) {
            ans = min(ans, mid);
            ri = mid - 1;
          } else
            le = mid + 1;
        }
        printf("%d\n", v[f[r] + f[l - 1] + n * 2][ans]);
      }
    }
    for (int i = 0; i <= (n << 2); i++) v[i].clear();
  }
  return 0;
}
