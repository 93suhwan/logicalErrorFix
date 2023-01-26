#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
pair<int, int> p[500000];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1))
    scanf("%d%d", &p[i].first, &p[i].second);
  sort(p, p + n, [&](pair<int, int> p1, pair<int, int> p2) {
    if (p1.first + p1.second != p2.first + p2.second)
      return p1.first + p1.second < p2.first + p2.second;
    return p1.second < p2.second;
  });
  int ans = 0;
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (p[i].first >= d) {
      ans++;
      d = max(d, p[i].second);
    }
  }
  printf("%d\n", ans);
}
