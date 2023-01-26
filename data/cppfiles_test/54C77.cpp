#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
int p[N], dis[N];
int cou[N][2];
int find(int x) {
  if (x != p[x]) {
    int root = find(p[x]);
    dis[x] ^= dis[p[x]];
    p[x] = root;
  }
  return p[x];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= (n); ++i)
      p[i] = i, dis[i] = 0, cou[i][1] = 0, cou[i][0] = 1;
    bool flag = 1;
    for (int i = 1; i <= (m); ++i) {
      int a, b;
      char c[10];
      scanf("%d %d %s", &a, &b, c);
      bool val = c[0] == 'i' ? 1 : 0;
      int pa = find(a), pb = find(b);
      if (pa == pb) {
        if ((dis[a] ^ dis[b]) != val) flag = 0;
      } else {
        p[pb] = pa;
        dis[pb] = val ^ dis[a] ^ dis[b];
        cou[pa][1] += cou[pb][dis[pb] ^ 1];
        cou[pa][0] += cou[pb][dis[pb]];
      }
    }
    if (!flag) {
      puts("-1");
      continue;
    }
    int res = 0;
    for (int i = 1; i <= (n); ++i)
      if (find(i) == i) res += max(cou[i][0], cou[i][1]);
    printf("%d\n", res);
  }
  return 0;
}
