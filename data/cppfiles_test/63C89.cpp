#include <bits/stdc++.h>
using namespace std;
struct unionFindSet {
  int fa[1005];
  void makeSet(int up) {
    for (int i = 0; i <= up; ++i) fa[i] = i;
  }
  int findSet(int x) {
    if (x == fa[x]) return x;
    return fa[x] = findSet(fa[x]);
  }
  void unionSet(int x, int y) {
    int xx = findSet(x), yy = findSet(y);
    if (xx == yy) return;
    fa[xx] = yy;
  }
} ufs1, ufs2;
int n, m1, m2;
int main() {
  scanf("%d %d %d", &n, &m1, &m2);
  ufs1.makeSet(n);
  ufs2.makeSet(n);
  for (int i = 1; i <= m1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    ufs1.unionSet(u, v);
  }
  for (int i = 1; i <= m2; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    ufs2.unionSet(u, v);
  }
  vector<pair<int, int>> Ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (ufs1.findSet(i) != ufs1.findSet(j) &&
          ufs2.findSet(i) != ufs2.findSet(j)) {
        ufs1.unionSet(i, j);
        ufs2.unionSet(i, j);
        Ans.push_back(make_pair(i, j));
      }
    }
  }
  printf("%d\n", int(Ans.size()));
  for (auto st : Ans) printf("%d %d\n", st.first, st.second);
  return 0;
}
