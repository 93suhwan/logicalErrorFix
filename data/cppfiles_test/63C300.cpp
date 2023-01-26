#include <bits/stdc++.h>
using namespace std;
int findParent(int i, vector<int> &p) {
  if (p[p[i]] != p[i]) p[i] = findParent(p[i], p);
  return p[i];
}
void merge(int a, int b, vector<int> &p, vector<int> &s) {
  int pa = findParent(a, p), pb = findParent(b, p);
  if (pa == pb) return;
  if (s[pa] >= s[pb]) {
    s[pa] += s[pb];
    p[pb] = pa;
  } else {
    s[pb] += s[pa];
    p[pa] = pb;
  }
  return;
}
int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> p1(n + 1), p2(n + 1), s1(n + 1), s2(n + 1);
    for (int i = 0; i < n; i++) {
      p1[i] = p2[i] = i;
      s1[i] = s2[i] = 1;
    }
    for (int i = 0; i < m1; i++) {
      int u, v;
      cin >> u >> v;
      merge(u, v, p1, s1);
    }
    for (int i = 0; i < m2; i++) {
      int u, v;
      cin >> u >> v;
      merge(u, v, p2, s2);
    }
    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (findParent(i, p1) != findParent(j, p1) &&
            findParent(i, p2) != findParent(j, p2)) {
          ans.push_back({i, j});
          merge(i, j, p1, s1);
          merge(i, j, p2, s2);
        }
      }
    }
    cout << ans.size() << "\n";
    ;
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}
