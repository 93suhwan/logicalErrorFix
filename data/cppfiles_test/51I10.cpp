#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
double start = clock();
const double eps = 1e-6;
struct inout {
  static const int ibufl = 1 << 25;
  char in_buf[ibufl + 5], out_buf[ibufl + 5], *inf, *ouf;
  void init() {
    fread(in_buf, 1, ibufl, stdin);
    inf = in_buf;
    ouf = out_buf;
  }
  inout& operator>>(int& a) {
    int fh = 1;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    a *= fh;
    return *this;
  }
  inout& operator>>(char& a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    a = *inf;
    ++inf;
    return *this;
  }
  inout& operator>>(char* a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    while (!(*inf == ' ' || *inf == '\n')) {
      *a = *inf;
      ++inf;
      ++a;
    }
    *a = '\0';
    return *this;
  }
  inout& operator>>(double& a) {
    int fh = 1;
    double s;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    if (*inf == '.') {
      s = 0.1;
      ++inf;
      while (isdigit(*inf)) {
        a += s * (*inf - '0');
        ++inf;
        s *= 0.1;
      }
    }
    a *= fh;
    return *this;
  }
  void writeint(int x) {
    if (x / 10) writeint(x / 10);
    *ouf = x % 10 + '0';
    ++ouf;
  }
  inout& operator<<(int a) {
    if (a < 0) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint(a);
    return *this;
  }
  static const int sz = 2;
  inout& operator<<(char a) {
    *ouf = a;
    ++ouf;
    return *this;
  }
  inout& operator<<(char* a) {
    while (*a) {
      *ouf = *a;
      ++ouf;
      ++a;
    }
    return *this;
  }
  inout& operator<<(double a) {
    if (a < -eps) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint((int)a);
    a -= (int)a;
    *ouf = '.';
    ++ouf;
    for (int i = 1; i <= sz; i++) {
      a = a * 10;
      *ouf = (int)a + '0';
      ++ouf;
      a -= (int)a;
    }
    return *this;
  }
  void out() { fwrite(out_buf, 1, ouf - out_buf, stdout); }
};
inout io;
int d[55], k, a[55][55], in[55], n;
pair<int, int> p[55], ed[1300];
int fa[55];
int getfa(int x) { return (fa[x] == x) ? x : (fa[x] = getfa(fa[x])); }
void merge(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  fa[x] = y;
}
bool cmp(pair<int, int> x, pair<int, int> y) {
  return a[x.first][x.second] < a[y.first][y.second];
}
int ans = 1e9;
void check() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) fa[i] = i, in[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ed[++cnt] = make_pair(i, j);
  sort(ed + 1, ed + cnt + 1, cmp);
  int len = 0;
  for (int i = 1; i <= cnt; i++) {
    if (getfa(ed[i].first) != getfa(ed[i].second)) {
      p[++len] = ed[i];
      merge(ed[i].first, ed[i].second);
      in[ed[i].first]++;
      in[ed[i].second]++;
    }
  }
  int val = 0;
  for (int i = 1; i <= k; i++) {
    val += max(0, in[i] - d[i]);
  }
  while (val) {
    sort(p + 1, p + len + 1, cmp);
    pair<int, int> era;
    for (int i = len; i >= 1; i--)
      if (in[p[i].first] > d[p[i].first] || in[p[i].second] > d[p[i].second]) {
        if (rand() % 4 != 0) {
          in[p[i].first]--;
          in[p[i].second]--;
          era = p[i];
          len = 0;
          for (int j = 1; j <= n - 1; j++)
            if (j != i) {
              p[++len] = p[j];
            }
          break;
        }
      }
    if (len == n - 1) continue;
    int t = rand() % 8;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= len; i++) merge(p[i].first, p[i].second);
    for (int i = 1; i <= cnt; i++)
      if (getfa(ed[i].first) != getfa(ed[i].second) &&
          (!t || (in[ed[i].first] <= d[ed[i].first] &&
                  in[ed[i].second] <= d[ed[i].second]))) {
        if (rand() % 4 != 0) {
          in[ed[i].first]++;
          in[ed[i].second]++;
          p[++len] = ed[i];
          break;
        }
      }
    if (len < n - 1) p[++len] = era, in[era.first]++, in[era.second]++;
    val = 0;
    for (int i = 1; i <= k; i++) val += max(0, in[i] - d[i]);
  }
  int sum = 0;
  for (int i = 1; i <= n - 1; i++) sum += a[p[i].first][p[i].second];
  ans = min(ans, sum);
}
signed main() {
  srand(time(0));
  io.init();
  io >> n >> k;
  for (int i = 1; i <= k; i++) io >> d[i];
  for (int i = k + 1; i <= n; i++) d[i] = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) io >> a[i][j], a[j][i] = a[i][j];
  }
  check();
  while (clock() < start + CLOCKS_PER_SEC * 5.5) check();
  io << ans;
  io.out();
  return 0;
}
