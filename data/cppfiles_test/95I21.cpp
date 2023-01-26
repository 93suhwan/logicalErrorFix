#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct NODE {
  int wn, ws, en, es;
};
int col[N];
vector<int> Map[N];
vector<NODE> Max[N], Min[N];
int n, m;
int read() {
  int s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s;
}
void cle(int x) {
  vector<NODE> a, b;
  vector<int> c;
  swap(Max[x], a);
  swap(Min[x], b);
  swap(Map[x], c);
}
int qwq(int i, int j) {
  Max[i][j].wn = Max[i][j].ws = Max[i][j].en = Max[i][j].es = 0;
  Min[i][j].wn = Min[i][j].ws = Min[i][j].en = Min[i][j].es = 0x3f3f3f3f;
}
void into() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    cle(i);
    Map[i].resize(m + 10);
    Max[i].resize(m + 10);
    Min[i].resize(m + 10);
    Map[i][0] = i;
    qwq(i, 0);
    for (int j = 1; j <= m; ++j) {
      Map[i][j] = read();
      qwq(i, j);
    }
    qwq(i, m + 1);
  }
  Map[0].resize(m + 10);
  Max[0].resize(m + 10);
  Min[0].resize(m + 10);
  Map[n + 1].resize(m + 10);
  Max[n + 1].resize(m + 10);
  Min[n + 1].resize(m + 10);
  for (int j = 0; j <= m + 1; ++j) qwq(n + 1, j), qwq(0, j);
}
bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
int mmax(int x, int y) { return x > y ? x : y; }
int mmin(int x, int y) { return x < y ? x : y; }
void init() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      Max[i][j].wn = mmax(mmax(Max[i - 1][j].wn, Max[i][j - 1].wn), Map[i][j]);
      Min[i][j].wn = mmin(mmin(Min[i - 1][j].wn, Min[i][j - 1].wn), Map[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 1; --j) {
      Max[i][j].en = mmax(mmax(Max[i - 1][j].en, Max[i][j + 1].en), Map[i][j]);
      Min[i][j].en = mmin(mmin(Min[i - 1][j].en, Min[i][j + 1].en), Map[i][j]);
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      Max[i][j].ws = mmax(mmax(Max[i + 1][j].ws, Max[i][j - 1].ws), Map[i][j]);
      Min[i][j].ws = mmin(mmin(Min[i + 1][j].ws, Min[i][j - 1].ws), Map[i][j]);
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 0; --j) {
      Max[i][j].es = mmax(mmax(Max[i + 1][j].es, Max[i][j + 1].es), Map[i][j]);
      Min[i][j].es = mmin(mmin(Min[i + 1][j].es, Min[i][j + 1].es), Map[i][j]);
    }
  }
}
bool check(int x, int y) {
  int wn = Max[x][y].wn;
  int ws = Min[x + 1][y].ws;
  int en = Min[x][y + 1].en;
  int es = Max[x + 1][y + 1].es;
  return ws > wn && en > es;
}
void output(int x, int y) {
  puts("YES");
  for (int i = 1; i <= x; ++i) col[Map[i][0]] = 1;
  for (int i = x + 1; i <= n; ++i) col[Map[i][0]] = 0;
  for (int i = 1; i <= n; ++i)
    if (col[i])
      putchar('B');
    else
      putchar('R');
  printf(" %d\n", y);
}
void debug() {
  puts("");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", Map[i][j]);
    puts("");
  }
  puts("");
}
void solve() {
  sort(Map + 1, Map + n + 1, cmp);
  init();
  debug();
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) {
      if (check(i, j)) {
        output(i, j);
        return;
      }
    }
  puts("NO");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    into();
    solve();
  }
  return 0;
}
