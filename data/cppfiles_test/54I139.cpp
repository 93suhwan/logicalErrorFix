#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int N = 200005;
int z, n, m, i, a, b, nal[N], num[N], licz[N], c, c2, res, resNP, resP, can;
vector<pair<int, int> > ff;
char t[20];
vector<int> graf[N], graf2[N];
void go(int w) {
  nal[w] = c;
  licz[c]++;
  for (auto& w2 : graf[w])
    if (!nal[w2]) go(w2);
}
void go2(int w) {
  num[w] = c2;
  if (c2 % 2)
    resNP += licz[w];
  else
    resP += licz[w];
  for (auto& w2 : graf2[w])
    if (!num[w2]) {
      c2++;
      go2(w2);
    }
}
int main() {
  scanf("%d", &z);
  while (z--) {
    scanf("%d %d", &n, &m);
    ff.clear();
    for (i = 1; i <= n; i++) {
      graf[i].clear();
      graf2[i].clear();
      nal[i] = 0;
      num[i] = 0;
      licz[i] = 0;
    }
    while (m--) {
      scanf("%d %d %s", &a, &b, t);
      if (t[0] == 'c') {
        graf[a].push_back(b);
        graf[b].push_back(a);
      } else
        ff.push_back(pair<int, int>(a, b));
    }
    c = 0;
    for (i = 1; i <= n; i++)
      if (!nal[i]) {
        c++;
        go(i);
      }
    can = 1;
    for (auto& w : ff) {
      if (nal[w.first] == nal[w.second]) can = 0;
      graf2[nal[w.first]].push_back(nal[w.second]);
      graf2[nal[w.second]].push_back(nal[w.first]);
    }
    if (!can) {
      printf("-1\n");
      continue;
    }
    c2 = 0;
    res = 0;
    for (i = 1; i <= c; i++)
      if (!num[i]) {
        c2++;
        resP = resNP = 0;
        go2(i);
        res += max(resP, resNP);
      }
    for (i = 1; i <= c; i++)
      for (auto& w : graf2[i])
        if (num[i] % 2 == num[w] % 2) {
          can = 0;
        }
    if (!can) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", res);
  }
  return 0;
}
