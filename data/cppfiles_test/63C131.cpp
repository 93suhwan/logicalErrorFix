#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 7;
int f1[maxn];
int f2[maxn];
int Find1(int x) {
  if (x == f1[x]) {
    return f1[x];
  }
  f1[x] = Find1(f1[x]);
  return f1[x];
}
int Find2(int x) {
  if (x == f2[x]) {
    return f2[x];
  }
  f2[x] = Find2(f2[x]);
  return f2[x];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f1[i] = i;
    f2[i] = i;
  }
  int m1, m2;
  cin >> m1 >> m2;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    int x = Find1(u);
    int y = Find1(v);
    f1[x] = y;
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    int x = Find2(u);
    int y = Find2(v);
    f2[x] = y;
  }
  vector<pair<int, int> > V;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x1 = Find1(i), y1 = Find1(j);
      int x2 = Find2(i), y2 = Find2(j);
      if ((x1 != y1) && (x2 != y2)) {
        V.push_back(make_pair(i, j));
        f1[x1] = y1;
        f2[x2] = y2;
      }
    }
  }
  cout << V.size() << "\n";
  for (int i = 0; i < V.size(); i++) {
    cout << V[i].first << " " << V[i].second << "\n";
  }
}
int main() { solve(); }
