#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
inline int ind(int a, int b) { return a + b * n; }
class dsu {
 public:
  int fat[N << 1], cnt[N << 1], tot[N << 1];
  bool vis[N << 1];
  inline void init(int n) {
    for (register int i = 1; i <= 2 * n; ++i)
      fat[i] = i, tot[i] = cnt[i] = 1, vis[i] = false;
    for (register int i = 1; i <= n; ++i) cnt[i] = 0;
  }
  inline int find(int a) {
    while (a ^ fat[a]) a = fat[a] = fat[fat[a]];
    return fat[a];
  }
  inline void unionn(int a, int b) {
    a = find(a);
    b = find(b);
    if (a ^ b) cnt[a] += cnt[b], tot[a] += tot[b], fat[b] = a;
  }
  inline int calc() {
    int ans = 0;
    for (register int i = 1; i <= n; ++i) {
      int a = find(ind(i, 0)), b = find(ind(i, 1));
      if (a == b)
        return -1;
      else if (vis[a])
        continue;
      vis[a] = vis[b] = true;
      ans += max(cnt[a], cnt[b]);
    }
    return ans;
  }
} F;
int main() {
  ios::sync_with_stdio(false);
  int qwq;
  cin >> qwq;
  while (qwq--) {
    cin >> n >> m;
    F.init(n);
    for (register int i = 1; i <= m; ++i) {
      int a, b;
      string c;
      cin >> a >> b >> c;
      int d = c[0] == 'i' ? 1 : 0;
      for (register int j = 0; j <= 1; ++j) F.unionn(ind(a, j), ind(b, j ^ d));
    }
    printf("%d\n", F.calc());
  }
  return 0;
}
