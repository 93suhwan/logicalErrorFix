#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int fr, to;
  long long w;
  bool operator<(const Edge &B) const {
    return w == B.w ? to == B.to ? fr < B.fr : to < B.to : w < B.w;
  }
};
struct ANS {
  long long sum;
  int idx;
  bool operator<(const ANS &B) const {
    return sum == B.sum ? idx < B.idx : sum < B.sum;
  }
};
set<Edge> S[100100], glS;
set<Edge>::iterator it, ta;
set<ANS> San;
map<long long, int> Mp;
long long tmpans[100100];
long long ans = 21000000000;
long long id(int u, int v) {
  if (u > v) swap(u, v);
  return 1ll * u << 22 | v;
}
void insert(Edge ee) {
  int u = ee.fr;
  S[u].insert(ee);
  int i = 1;
  for (i = 1, it = S[u].begin(); i <= 3 && it != S[u].end(); ++i, ++it)
    if ((*it).fr == ee.fr && (*it).to == ee.to) break;
  if (i <= 3 && it != S[u].end()) {
    glS.insert(ee);
    for (; i <= 3 && it != S[u].end(); ++i, ++it)
      ;
    if (it != S[u].end()) glS.erase(*it);
  }
}
void DELETE(Edge ee) {
  int i = 1, u = ee.fr;
  for (i = 1, it = S[u].begin(); i <= 3 && it != S[u].end(); ++i, ++it)
    glS.erase(*it);
  S[u].erase(ee);
  for (i = 1, it = S[u].begin(); i <= 3 && it != S[u].end(); ++i, ++it)
    glS.insert(*it);
}
void calc3(int u) {
  if (tmpans[u] != -1) San.erase((ANS){tmpans[u], u});
  tmpans[u] = -1;
  int i = 1;
  long long sum = 0;
  for (i = 1, it = S[u].begin(); i <= 3 && it != S[u].end(); ++i, ++it)
    sum += (*it).w;
  if (i == 4) San.insert((ANS){tmpans[u] = sum, u});
}
bool judge(Edge E, Edge ee) {
  return E.fr != ee.fr && E.fr != ee.to && E.to != ee.fr && E.to != ee.to;
}
void calc() {
  Edge ee = *glS.begin();
  int cnt = 0;
  for (auto E : glS) {
    ++cnt;
    if (judge(E, ee)) {
      ans = min(ans, E.w + ee.w);
      break;
    }
    if (cnt > 7) break;
  }
  int i = 1, j = 1;
  for (i = 1, it = S[ee.fr].begin(); i <= 3 && it != S[ee.fr].end();
       ++it, ++i) {
    if ((*it).to == ee.to) continue;
    for (j = 1, ta = S[ee.to].begin(); j <= 3 && ta != S[ee.to].end();
         ++ta, ++j) {
      if ((*it).to == ee.fr) continue;
      if (judge(*it, *ta)) ans = min(ans, (*it).w + (*ta).w);
    }
  }
}
int main() {
  int n, m, u, v, w, Q, op;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    S[u].insert(Edge{u, v, w});
    S[v].insert(Edge{v, u, w});
    Mp[id(u, v)] = w;
  }
  for (int i = 1; i <= n; ++i) {
    int j;
    for (j = 1, it = S[i].begin(); j <= 3 && it != S[i].end(); ++j, ++it)
      glS.insert(*it);
  }
  for (int i = 1; i <= n; ++i) tmpans[i] = -1;
  for (int i = 1; i <= n; ++i) calc3(i);
  if (!San.empty()) ans = min(ans * 1ll, (*San.begin()).sum);
  scanf("%d", &Q);
  calc();
  printf("%lld\n", ans);
  while (Q--) {
    scanf("%d", &op);
    if (op) {
      scanf("%d%d%d", &u, &v, &w);
      insert(Edge{u, v, w});
      insert(Edge{v, u, w});
      Mp[id(u, v)] = w;
      calc3(u);
      calc3(v);
      if (!San.empty()) ans = min(ans, (*San.begin()).sum);
      calc();
    } else {
      scanf("%d%d", &u, &v);
      w = Mp[id(u, v)];
      DELETE(Edge{u, v, w});
      DELETE(Edge{v, u, w});
      ans = 21000000000;
      calc3(u);
      calc3(v);
      calc();
      if (!San.empty()) ans = min(ans, (*San.begin()).sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
