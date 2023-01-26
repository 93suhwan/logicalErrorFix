#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, q;
char s1[N];
int s[N];
struct node {
  int p, s;
  bool operator<(const node &b) const {
    if (b.s == s) return p < b.p;
    return s < b.s;
  }
} e[N];
vector<int> g[N * 2];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %s", &n, &q, s1 + 1);
    for (int i = N - n; i <= N + n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + (i & 1 ? 1 : -1) * (s1[i] == '+' ? 1 : -1);
      g[N + s[i]].push_back(i);
    }
    int l, r;
    while (q--) {
      scanf("%d %d", &l, &r);
      if (s[r] - s[l - 1] == 0) {
        puts("0");
        continue;
      } else if (r - l + 1 & 1)
        puts("1");
      else {
        puts("2");
        printf("%d ", r);
        r--;
      }
      int x = s[r] - s[l - 1];
      if (x > 0)
        x = x / 2 + 1;
      else
        x = x / 2 - 1;
      x += s[l - 1];
      x += N;
      int pos = lower_bound(g[x].begin(), g[x].end(), l) - g[x].begin();
      printf("%d\n", g[x][pos]);
    }
  }
  return 0;
}
