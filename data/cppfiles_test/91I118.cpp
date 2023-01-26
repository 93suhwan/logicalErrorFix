#include <bits/stdc++.h>
using namespace std;
set<pair<int, pair<int, int> > > edge;
map<pair<int, int>, int> wei;
vector<pair<int, pair<int, int> > > alive;
set<pair<int, int> > from[100010];
bool OK2(pair<int, int> a, pair<int, int> b) {
  return a.first != b.first && a.second != b.second && a.first != b.second &&
         a.second != b.first;
}
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.second < b.second;
}
bool OK3(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return a.first != b.first || a.second != c.first || b.second != c.second;
}
long long Solve() {
  alive.clear();
  for (auto it : edge) {
    alive.push_back(it);
    if (alive.size() == 10) break;
  }
  sort(alive.begin(), alive.end(), cmp);
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < alive.size(); i++) {
    pair<int, pair<int, int> > it = alive[i];
    for (int j = i + 1; j < alive.size(); j++) {
      pair<int, pair<int, int> > jt = alive[j];
      if (OK2(it.second, jt.second))
        ans = min(ans, (long long)it.first + jt.first);
      for (int k = j + 1; k < alive.size(); k++) {
        pair<int, pair<int, int> > kt = alive[k];
        if (OK3(it.second, jt.second, kt.second))
          ans = min(ans, (long long)it.first + jt.first + kt.first);
      }
    }
  }
  return ans;
}
void ERA(int x, int y, int w) {
  if (x > y) swap(x, y);
  edge.erase(make_pair(w, make_pair(x, y)));
}
void INS(int x, int y, int w) {
  if (x > y) swap(x, y);
  edge.insert(make_pair(w, make_pair(x, y)));
}
void Era(int x) {
  int k = 3;
  for (auto it : from[x]) {
    k--;
    ERA(it.first, x, it.second);
    if (!k) break;
  }
}
void Ins(int x) {
  int k = 3;
  for (auto it : from[x]) {
    k--;
    INS(it.first, x, it.second);
    if (!k) break;
  }
}
void InsEdge(int x, int y, int w) {
  Era(x), Era(y), from[x].insert(make_pair(y, w)),
      from[y].insert(make_pair(x, w)), Ins(x), Ins(y);
}
void EraEdge(int x, int y, int w) {
  Era(x), Era(y), from[x].erase(make_pair(y, w)),
      from[y].erase(make_pair(x, w)), Ins(x), Ins(y);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    if (x > y) swap(x, y);
    InsEdge(x, y, w), wei[make_pair(x, y)] = w;
  }
  printf("%lld\n", Solve());
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y, w;
    scanf("%d%d%d", &op, &x, &y);
    if (x > y) swap(x, y);
    if (op == 1)
      scanf("%d", &w), InsEdge(x, y, w), wei[make_pair(x, y)] = w;
    else
      w = wei[make_pair(x, y)], EraEdge(x, y, w);
    printf("%lld\n", Solve());
  }
  return 0;
}
