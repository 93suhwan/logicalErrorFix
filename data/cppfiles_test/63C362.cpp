#include <bits/stdc++.h>
using namespace std;
int n, m1, m2, x, y, p1[1005], p2[1005];
vector<pair<int, int> > v;
int par1(int x) {
  if (p1[x] == x)
    return x;
  else
    return p1[x] = par1(p1[x]);
}
int par2(int x) {
  if (p2[x] == x)
    return x;
  else
    return p2[x] = par2(p2[x]);
}
void connect1(int x, int y) {
  x = par1(x);
  y = par1(y);
  if (x == y) return;
  if (x < y) {
    p1[y] = x;
  } else {
    p1[x] = y;
  }
}
void connect2(int x, int y) {
  x = par2(x);
  y = par2(y);
  if (x == y) return;
  if (x < y) {
    p2[y] = x;
  } else {
    p2[x] = y;
  }
}
signed main() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    p1[i] = i;
    p2[i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    cin >> x >> y;
    connect1(x, y);
  }
  for (int i = 1; i <= m2; i++) {
    cin >> x >> y;
    connect2(x, y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (par1(i) == par1(j)) continue;
      if (par2(i) == par2(j)) continue;
      v.push_back({i, j});
      connect1(par1(i), par1(j));
      connect2(par2(i), par2(j));
    }
  }
  cout << v.size() << endl;
  for (auto g : v) {
    cout << g.first << " " << g.second << endl;
  }
}
