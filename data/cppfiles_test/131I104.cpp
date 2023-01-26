#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn];
vector<set<int>> g(maxn * 22 + 5);
map<int, int> v2n, n2i;
int hsb(int i) {
  i |= (i >> 1);
  i |= (i >> 2);
  i |= (i >> 4);
  i |= (i >> 8);
  i |= (i >> 16);
  return i - (i >> 1);
}
pair<pair<int, int>, pair<int, int>> diam(int i) {
  int b = 0, b2 = 0, bi = i, b2i = -1;
  for (int j : g[i]) {
    pair<pair<int, int>, pair<int, int>> dfs = diam(j);
    if (dfs.first.first > b) {
      b2i = bi;
      b2 = b;
      bi = dfs.second.first;
      b = dfs.first.first;
    } else if (dfs.first.first > b2) {
      b2i = dfs.second.first;
      b2 = dfs.first.first;
    }
  }
  return make_pair(make_pair(1 + b, b + 1 + b2), make_pair(bi, b2i));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int node = 0;
  for (int i = 0; i < n; ++i) {
    int last = a[i];
    if (v2n.find(last) == v2n.end()) v2n[last] = node++;
    n2i[v2n[last]] = i + 1;
    while (last) {
      int powk = hsb(last);
      if (powk < last) powk <<= 1;
      int next = powk - last;
      if (v2n.find(next) == v2n.end()) v2n[next] = node++;
      int u = v2n[last], v = v2n[next];
      if (g[v].find(u) != g[v].end()) break;
      g[v].insert(u);
      last = next;
    }
  }
  pair<pair<int, int>, pair<int, int>> ans = diam(v2n[0]);
  cout << n2i[ans.second.first] << ' ' << n2i[ans.second.second] << ' '
       << (ans.first.second - 1) << endl;
}
