#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
long long maxll(long long x, long long y) { return x > y ? x : y; }
long long minll(long long x, long long y) { return x < y ? x : y; }
long long absll(long long x) { return x > 0ll ? x : -x; }
int t, ans;
int W, H, w, h;
int a1, a2, b1, b2;
double pr;
int main() {
  t = rd();
  while (t--) {
    W = rd(), H = rd(), ans = 0x3f3f3f3f;
    a1 = rd(), b1 = rd(), a2 = rd(), b2 = rd();
    w = rd(), h = rd();
    if ((a2 - a1) + w <= W) {
      ans = min(ans, max(0, a2 - (W - w)));
      ans = min(ans, max(0, w - a1));
    }
    if ((b2 - b1) + h <= H) {
      ans = min(ans, max(0, b2 - (H - h)));
      ans = min(ans, max(0, h - b1));
    }
    if (ans == 0x3f3f3f3f)
      printf("-1\n");
    else
      pr = ans, printf("%.9lf\n", pr);
  }
  return 0;
}
