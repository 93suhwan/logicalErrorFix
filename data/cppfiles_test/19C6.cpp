#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 1e4 + 10;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const double pi = acos(-1);
template <typename T>
inline void read(T &s) {
  T t = 1;
  char k = getchar();
  s = 0;
  for (; k < '0' || k > '9'; k = getchar())
    if (k == '-') t = -1;
  for (; k >= '0' && k <= '9'; k = getchar())
    s = (s << 1) + (s << 3) + (k ^ 48);
  s *= t;
}
int a[maxn], t[2010], s[2010], n;
bool check(int x) {
  for (int i = 0; i <= x; i++) s[i] = 1;
  for (int i = 1; i <= n; i++) {
    memset(t, 0, sizeof(t));
    ;
    for (int j = a[i]; j <= x; j++) t[j - a[i]] = s[j];
    for (int j = 0; j <= x - a[i]; j++) t[j + a[i]] |= s[j];
    swap(s, t);
  }
  for (int i = 0; i <= x; i++)
    if (s[i] == 1) return true;
  return false;
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = 2000;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
