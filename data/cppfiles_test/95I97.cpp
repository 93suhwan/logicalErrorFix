#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, N1 = maxn + 7;
const int inf = 0x3f3f3f3f;
template <typename T>
inline void read(T &x) {
  x = 0;
  T k = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= k;
}
struct node {
  int id, mi, ma;
} b[N1];
int cmp(node &s1, node &s2) { return s1.ma < s2.ma; }
int n, m, de;
vector<int> a[N1], fi[N1], fa[N1];
int mi[N1], ma[N1], bmi[N1];
int col[N1];
void out(int I, int J) {
  for (int i = 1; i <= n; i++) col[i] = 0;
  for (int i = 1; i <= I; i++) col[b[i].id] = 1;
  puts("YES");
  for (int i = 1; i <= n; i++) putchar(col[i] ? 'B' : 'R');
  printf(" %d\n", J);
}
void clr() {
  for (int i = 1; i <= n; i++) a[i].clear(), fi[i].clear(), fa[i].clear();
}
void solve() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) ma[i] = 0, mi[i] = inf;
  for (int i = 1; i <= n; i++) {
    a[i].resize(m + 1);
    for (int j = 1; j <= m; j++) read(a[i][j]);
    fi[i].resize(m + 2);
    fa[i].resize(m + 2);
    fi[i][m + 1] = inf;
    fa[i][m + 1] = 0;
    for (int j = m; j >= 1; j--) fi[i][j] = min(fi[i][j + 1], a[i][j]);
    for (int j = m; j >= 1; j--) fa[i][j] = max(fa[i][j + 1], a[i][j]);
  }
  for (int j = 1; j < m; j++) {
    if (j == 3) de = 1;
    for (int i = 1; i <= n; i++)
      ma[i] = max(ma[i], a[i][j]), mi[i] = min(mi[i], a[i][j]);
    for (int i = 1; i <= n; i++) {
      b[i].id = i, b[i].mi = mi[i], b[i].ma = ma[i];
    }
    sort(b + 1, b + n + 1, cmp);
    bmi[n + 1] = inf;
    for (int i = n; i >= 1; i--) bmi[i] = min(bmi[i + 1], b[i].mi);
    multiset<int> sma, smi;
    for (int i = 1; i <= n; i++) sma.insert(fa[i][j + 1]);
    smi.insert(-inf);
    sma.insert(inf);
    for (int i = 1; i < n; i++) {
      int id = b[i].id;
      smi.insert(fi[id][j + 1]);
      multiset<int>::iterator k = sma.find(fa[id][j + 1]);
      sma.erase(k);
      if (b[i].ma < bmi[i + 1]) {
        multiset<int>::iterator k0 = sma.begin();
        multiset<int>::iterator k1 = smi.end();
        k1--;
        if (*(k0) < *(k1)) {
          out(i, j);
          return;
        }
      }
    }
  }
  puts("NO");
}
int main() {
  int Te;
  read(Te);
  while (Te--) {
    solve();
    clr();
  }
  return 0;
}
