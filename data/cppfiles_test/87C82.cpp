#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int c[N], a[N], d[N];
bool cmp(int first, int second) {
  if (a[first] != a[second]) return a[first] < a[second];
  return first > second;
}
inline int lowbit(int first) { return first & -first; }
int query(int first) {
  int res = 0;
  for (int i = first; i; i -= lowbit(i)) res += c[i];
  return res;
}
void modify(int first, int v) {
  for (int i = first; i < N; i += lowbit(i)) c[i] += v;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]), d[i] = i, c[i] = 0;
    sort(d + 1, d + m + 1, cmp);
    long long res = 0;
    for (int i = 1; i <= m; ++i) {
      res += query(d[i]);
      modify(d[i], 1);
    }
    printf("%lld\n", res);
  }
  return 0;
}
