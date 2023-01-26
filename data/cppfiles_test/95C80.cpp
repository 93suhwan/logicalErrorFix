#include <bits/stdc++.h>
using namespace std;
inline int read(void) {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 500005;
vector<int> a[maxn], b[2][2][maxn];
struct Node {
  int value, id;
} node[maxn];
inline bool operator<(Node p, Node q) { return p.value > q.value; }
int c[maxn], d[maxn], e[maxn];
char as[maxn];
int main(void) {
  int t = read();
  while (t--) {
    int n = read(), m = read();
    bool flag = 0;
    for (int i = 0; i <= n - 1; ++i) {
      for (int j = 0; j <= m - 1; ++j) {
        a[i].push_back(read());
        if (!j)
          b[0][0][i].push_back(a[i][j]);
        else
          b[0][0][i].push_back(max(a[i][j], b[0][0][i][j - 1]));
        if (!j)
          b[0][1][i].push_back(a[i][j]);
        else
          b[0][1][i].push_back(min(a[i][j], b[0][1][i][j - 1]));
      }
      for (int j = m - 1; j >= 0; --j)
        c[j] = (j != m - 1) ? max(c[j + 1], a[i][j]) : a[i][j];
      for (int j = 0; j <= m - 1; ++j) b[1][0][i].push_back(c[j]);
      for (int j = m - 1; j >= 0; --j)
        c[j] = (j != m - 1) ? min(c[j + 1], a[i][j]) : a[i][j];
      for (int j = 0; j <= m - 1; ++j) b[1][1][i].push_back(c[j]);
    }
    for (int j = 0; j <= m - 2; ++j) {
      for (int i = 0; i <= n - 1; ++i) node[i] = (Node){b[0][1][i][j], i};
      sort(node, node + n);
      for (int i = n - 1; i >= 0; --i)
        c[i] = (i != n - 1) ? (max(c[i + 1], b[0][0][node[i].id][j]))
                            : (b[0][0][node[i].id][j]);
      for (int i = 0; i <= n - 1; ++i)
        d[i] = i ? (max(d[i - 1], b[1][0][node[i].id][j + 1]))
                 : (b[1][0][node[i].id][j + 1]);
      for (int i = n - 1; i >= 0; --i)
        e[i] = (i != n - 1) ? (min(e[i + 1], b[1][1][node[i].id][j + 1]))
                            : (b[1][1][node[i].id][j + 1]);
      for (int i = 0; i <= n - 2; ++i)
        if (node[i].value > c[i + 1] && d[i] < e[i + 1]) {
          printf("YES\n");
          for (int k = 0; k <= i; ++k) as[node[k].id] = 'R';
          for (int k = i + 1; k <= n - 1; ++k) as[node[k].id] = 'B';
          for (int k = 0; k <= n - 1; ++k) putchar(as[k]);
          printf(" %d\n", j + 1);
          flag = 1;
          break;
        }
      if (flag) break;
    }
    if (!flag) printf("NO\n");
    for (int i = 0; i <= n - 1; ++i) {
      a[i].clear();
      b[0][0][i].clear();
      b[0][1][i].clear();
      b[1][0][i].clear();
      b[1][1][i].clear();
    }
  }
  return 0;
}
