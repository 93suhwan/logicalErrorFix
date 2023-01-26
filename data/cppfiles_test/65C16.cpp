#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, a[200005];
char s[200005];
pair<int, char> ans[200005];
int main() {
  scanf("%d", &n);
  for (int(i) = (1); (i) <= (n); (i)++) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  int w = 1;
  for (int(i) = (2); (i) <= (n); (i)++) w += s[i] != s[i - 1];
  ans[1] = make_pair(a[n - w + 1], s[1]);
  bool d1 = 0, d2 = 0;
  if (s[1] == 'R') d1 = 1, d2 = 1;
  int l = n - w + 1, r = n - w + 1;
  for (int(i) = (2); (i) <= (n); (i)++) {
    if (s[i] == s[i - 1]) {
      l--;
      ans[i] = make_pair(a[l], d1 ? 'L' : 'R');
      d1 ^= 1;
    } else {
      r++;
      ans[i] = make_pair(a[r], d2 ? 'L' : 'R');
      d2 ^= 1;
    }
  }
  for (int(i) = (1); (i) <= (n); (i)++)
    printf("%d %c\n", ans[i].first, ans[i].second);
  return 0;
}
