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
long long gcd(long long x, long long y) { return (y == 0) ? x : gcd(y, x % y); }
int n, ans;
int minn[100005], ord[100005], siz[100005];
vector<int> g[100005];
bool cmp(int x, int y) {
  int a = minn[x] + siz[x], b = minn[y] + siz[y];
  if (a >= minn[y] && b >= minn[x])
    return minn[x] < minn[y];
  else if (a < minn[y] && b < minn[y])
    return minn[x] < minn[y];
  else if (a >= minn[y] && b < minn[y])
    return true;
  else
    return false;
}
int main() {
  int T = rd();
  while (T--) {
    n = rd();
    for (int i = 1; i <= n; i++) {
      siz[i] = rd(), ord[i] = i, minn[i] = 0;
      for (int j = 1, x; j <= siz[i]; j++)
        x = rd(), g[i].push_back(x), minn[i] = max(minn[i], x - j + 2);
    }
    sort(ord + 1, ord + n + 1, cmp), ans = minn[ord[1]];
    for (int i = 1, tmp = ans; i <= n; i++) {
      if (tmp < minn[ord[i]]) ans += minn[ord[i]] - tmp, tmp = minn[ord[i]];
      tmp += siz[ord[i]];
    }
    printf("%d\n", ans);
  }
  return 0;
}
