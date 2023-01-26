#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int N = 300 + 10;
int n, m, k, T, ans, cnt, sum;
struct Node {
  int x, y, st;
  bool operator<(const Node X) const {
    if (X.st ^ st) return X.st < st;
    return X.y > y;
  }
};
long long tre[N][N];
priority_queue<Node> p_q[N * N];
vector<int> V;
int w[N * N];
int d(int x) { return lower_bound(V.begin(), V.end(), x) - V.begin() + 1; }
void update(long long *tre, int x) {
  for (int i = x; i <= m; i += i & -i) tre[i]++;
}
long long get(long long *tre, int x) {
  long long res = 0;
  for (int i = x; i >= 1; i -= i & -i) res += tre[i];
  return res;
}
int main(void) {
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) tre[i][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cnt++;
        scanf("%d", &w[cnt]);
      }
    V.assign(w + 1, w + cnt + 1);
    sort(V.begin(), V.end());
    for (int i = 1, x = 1, y = 0, z; i <= cnt; i++) {
      y++;
      if (y == m + 1) y = 1, x++;
      if (y == 1) z = d(V[i + m - 2]);
      int v = d(V[i - 1]);
      if (v ^ z)
        p_q[v].push(Node({x, y, 1}));
      else
        p_q[v].push(Node({x, y, 0}));
    }
    for (int i = 1; i <= cnt; i++) {
      int v = d(w[i]);
      Node p = p_q[v].top();
      p_q[v].pop();
      ans += get(tre[p.x], p.y);
      update(tre[p.x], p.y);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
