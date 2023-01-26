#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
}
const int N = 1e5 + 10;
const int INF = 0x7fffffff;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
int a[N];
inline int tr(int x) { return ((x + 1) >> 1) - 1; }
int main() {
  int t;
  read(t);
  while (t--) {
    int n, cur = 1, ans = 0;
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++, cur++) {
      if (a[i] == cur) continue;
      if (tr(a[i]) >= cur)
        ans++;
      else {
        ans = -1;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
