#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
int n, ans;
int minn[200005];
struct Data {
  int val, ord;
} a[200005];
bool cmp(Data x, Data y) { return x.val < y.val; }
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) a[i].val = rd(), a[i].ord = i - a[i].val + 1;
  sort(a + 1, a + n + 1, cmp);
  memset(minn, 0x3f3f3f3f, sizeof(minn)), minn[0] = 0;
  for (int i = 1, nl, nr, ret; i <= n; i++) {
    if (a[i].ord <= 0) continue;
    if (a[i].ord >= minn[ans])
      minn[++ans] = a[i].ord;
    else {
      ret = nl = 0, nr = ans;
      while (nl <= nr) {
        int mid = (nl + nr) >> 1;
        if (minn[mid] < a[i].ord)
          nl = mid + 1;
        else
          ret = mid, nr = mid - 1;
      }
      minn[ret] = min(minn[ret], a[i].ord);
    }
  }
  printf("%d\n", ans);
  return 0;
}
