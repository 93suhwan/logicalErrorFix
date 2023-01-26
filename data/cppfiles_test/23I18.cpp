#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int n, m, first[N];
int cnt, sta[N], c[N][2], siz[N];
long long f[N][N];
inline int read() {
  int x(0), y(1);
  char z(getchar());
  while (!isdigit(z)) {
    if (z == '-') y = -1;
    z = getchar();
  }
  while (isdigit(z)) x = x * 10 + (z ^ 48), z = getchar();
  return x * y;
}
inline void Max(long long &first, long long second) {
  first = first > second ? first : second;
}
inline void Min(long long &first, long long second) {
  first = first < second ? first : second;
}
inline int max(int &first, int &second) {
  return first > second ? first : second;
}
inline int min(int &first, int &second) {
  return first < second ? first : second;
}
inline void swap(int &first, int &second) {
  first ^= second, second ^= first, first ^= second;
}
inline int abs(int &first) { return first >= 0 ? first : -first; }
inline pair<int, int> operator+(const pair<int, int> &first,
                                const pair<int, int> &second) {
  return make_pair(first.first + second.first, first.second + second.second);
}
inline pair<int, int> operator-(const pair<int, int> &first,
                                const pair<int, int> &second) {
  return make_pair(first.first - second.first, first.second - second.second);
}
void Dfs(int x) {
  f[x][1] = 1ll * (m - 1) * first[x], siz[x] = 1;
  if (c[x][1]) {
    Dfs(c[x][1]), siz[x] += siz[c[x][1]];
    for (int i(min(siz[x], m)); i; --i)
      for (int j(min(siz[c[x][1]], i)); j; --j)
        Max(f[x][i],
            f[c[x][1]][j] + f[x][i - j] - 2ll * j * (i - j) * first[x]);
  }
  if (c[x][0]) {
    Dfs(c[x][0]), siz[x] += siz[c[x][0]];
    for (int i(min(siz[x], m)); i; --i)
      for (int j(min(siz[c[x][0]], i)); j; --j)
        Max(f[x][i],
            f[c[x][0]][j] + f[x][i - j] - 2ll * j * (i - j) * first[x]);
  }
}
signed main() {
  memset(f, -0x7f, sizeof f);
  n = read(), m = read();
  for (int i(1); i <= n; ++i) first[i] = read();
  for (int i(1); i <= n; ++i) {
    while (cnt && first[i] < first[sta[cnt]]) cnt--;
    c[i][1] = c[sta[cnt]][0], c[sta[cnt]][0] = i;
    sta[++cnt] = i;
  }
  Dfs(c[0][0]), printf("%lld\n", f[c[0][0]][m]);
}
