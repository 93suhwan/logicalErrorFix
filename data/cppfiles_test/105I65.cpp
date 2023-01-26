#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int T, n, a[maxn], b[maxn], m[maxn], ans[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    vector<pair<int, int>> id;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d", &a[i], &b[i], &m[i]);
      id.emplace_back(a[i] + b[i] - m[i], i);
    }
    sort(id.begin(), id.end());
    for (int i = 0, j; i < id.size(); i = j) {
      for (j = i; j < id.size() && id[i].first == id[j].first; j++)
        ;
      vector<array<int, 3>> V;
      for (int k = i; k < j; k++) {
        int p = id[k].second;
        V.push_back({max(0, a[p] - m[p]), a[p], p});
      }
      sort(V.begin(), V.end());
      set<pair<int, int>> S;
      int lst = -1;
      for (int j = 0, k; j < V.size(); j = k) {
        for (k = j; k < V.size() && V[j][0] == V[k][0]; k++)
          ;
        for (int p = j; p < k; p++) S.emplace(V[p][1], V[p][2]);
        while (!S.empty() && lst < V[j][0]) {
          ans[S.begin()->second] = ++lst, S.erase(S.begin());
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", a[i] - ans[i], m[i] - (a[i] - ans[i]));
    }
  }
  return 0;
}
