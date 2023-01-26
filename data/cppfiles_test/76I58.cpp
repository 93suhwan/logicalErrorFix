#include <bits/stdc++.h>
using namespace std;
int n, m;
inline int read() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 100005;
struct node {
  int to, nxt;
} e[N << 1];
int head[N], tot;
inline void add(int u, int v) {
  e[++tot].to = v, e[tot].nxt = head[u], head[u] = tot;
  e[++tot].to = u, e[tot].nxt = head[v], head[v] = tot;
}
int a[6];
inline bool check() {
  bool f1 = 1, f2 = 1;
  int cnt[5];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= 5; ++i) {
    for (int j = head[a[i]]; j; j = e[j].nxt) {
      int v = e[j].to;
      for (int k = 1; k <= 5; ++k) {
        if (v == a[k]) f1 = 0, ++cnt[i];
      }
    }
  }
  for (int i = 1; i <= 5; ++i) {
    if (cnt[i] < 4) f2 = 0;
  }
  return f1 || f2;
}
map<long long, int> ma;
int main() {
  srand(time(0));
  n = read(), m = read();
  for (int i = 1, u, v; i <= m; ++i) {
    u = read(), v = read();
    add(u, v);
  }
  int ti = 1000000, ri = 100000;
  while (ti && ri) {
    for (int i = 1; i <= 5; ++i) {
      a[i] = rand() % min(n, 10) + 1;
      for (int j = 1; j < i; ++j) {
        if (a[j] == a[i]) {
          i--;
          break;
        }
      }
    }
    sort(a + 1, a + 1 + 5);
    long long num = 0;
    for (int i = 1; i <= 5; ++i) {
      num = num * 13331 + a[i];
    }
    --ti;
    if (ma[num]) continue;
    --ri, ma[num] = 1;
    if (check()) {
      for (int i = 1; i <= 5; ++i) {
        printf("%d ", a[i]);
      }
      cout << endl;
      return 0;
    }
  }
  puts("-1");
  return 0;
}
