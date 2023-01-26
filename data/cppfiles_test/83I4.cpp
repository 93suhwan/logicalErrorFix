#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
int lt[100005][3];
pair<int, int> tmp[100005];
pair<int, int> ans[100005];
int sl = 0;
set<int> s;
int cl[100005];
int L;
int Find(int u, int id) {
  if (lt[u][id] == u) return u;
  return lt[u][id] = Find(lt[u][id], id);
}
void run() {
  while (L < n && tmp[L + 1].first == tmp[L].first) {
    L++;
    int x = Find(tmp[L].second, 2);
    cl[x] = L;
    s.insert(x);
  }
  L++;
}
int main() {
  cin >> n;
  cin >> m1 >> m2;
  for (int i = 1; i <= n; ++i) lt[i][1] = lt[i][2] = i;
  for (int i = 1; i <= m1; ++i) {
    int u, v;
    cin >> u >> v;
    int u1 = Find(u, 1);
    int v1 = Find(v, 1);
    if (u1 != v1) lt[u1][1] = v1;
  }
  for (int i = 1; i <= m2; ++i) {
    int u, v;
    cin >> u >> v;
    int u2 = Find(u, 2);
    int v2 = Find(v, 2);
    if (u2 != v2) lt[u2][2] = v2;
  }
  for (int i = 1; i <= n; ++i) tmp[i] = pair<int, int>(Find(i, 1), i);
  sort(tmp + 1, tmp + n + 1);
  L = 1;
  for (int i = 1; i <= n; ++i)
    if (i >= L) {
      if (i > L && tmp[i - 1].first != tmp[i].first) run();
      int x = Find(tmp[i].second, 2);
      if (!s.empty()) {
        auto it = s.begin();
        int y = (*it);
        if (x != y) {
          lt[x][2] = y;
          s.erase(x);
          ans[++sl] = pair<int, int>(i, cl[y]);
          run();
          goto L1;
        }
        it++;
        if (it != s.end()) {
          y = (*it);
          if (x != y) {
            lt[x][2] = y;
            s.erase(x);
            ans[++sl] = pair<int, int>(i, cl[y]);
            run();
            goto L1;
          }
        }
      L1:;
      }
    }
  printf("%d\n", sl);
  for (int i = 1; i <= sl; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}
