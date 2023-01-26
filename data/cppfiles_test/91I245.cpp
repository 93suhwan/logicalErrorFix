#include <bits/stdc++.h>
using namespace std;
template <class T>
void Rd(T &x) {
  x = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 1) + (x << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
set<pair<int, int>> S[100005];
map<int, int> G[100005];
const int maxl = 7;
struct node {
  pair<int, pair<int, int>> v[maxl];
  long long same_end;
  node operator+(const node &_) const {
    node res;
    res.same_end = min(same_end, _.same_end);
    int L1 = 0, L2 = 0;
    for (int i = 0; i < maxl; ++i) {
      if (v[L1] < _.v[L2])
        res.v[i] = v[L1++];
      else
        res.v[i] = _.v[L2++];
    }
    return res;
  }
} tr[100005 << 2];
bool Is_topthree(int a, int b) {
  int cnt = 0;
  set<pair<int, int>>::iterator it = S[a].begin();
  for (; cnt < 3 && it != S[a].end(); cnt++, it++) {
    if (it->second == b) return 1;
  }
  return 0;
}
void Build(int L, int R, int p) {
  if (L == R) {
    int cnt = 0;
    set<pair<int, int>>::iterator it = S[L].begin();
    long long res = 0;
    int m = 0;
    for (; cnt < 3 && it != S[L].end(); cnt++, it++) {
      int y = it->second, c = it->first;
      if (Is_topthree(y, L) && L < y)
        tr[p].v[m++] = make_pair(c, make_pair(L, y));
      res += it->first;
    }
    tr[p].same_end = ((cnt == 3) ? res : 4000000000);
    for (int i = m; i < maxl; ++i)
      tr[p].v[i] = make_pair(2000000000, make_pair(0, 0));
    return;
  }
  int mid = (L + R) >> 1;
  Build(L, mid, p << 1);
  Build(mid + 1, R, p << 1 | 1);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
void Update(int L, int R, int p, int x) {
  if (L == R) {
    int cnt = 0;
    set<pair<int, int>>::iterator it = S[L].begin();
    long long res = 0;
    int m = 0;
    for (; cnt < 3 && it != S[L].end(); cnt++, it++) {
      int y = it->second, c = it->first;
      if (Is_topthree(y, L) && L < y)
        tr[p].v[m++] = make_pair(c, make_pair(L, y));
      res += it->first;
    }
    tr[p].same_end = ((cnt == 3) ? res : 4000000000);
    for (int i = m; i < maxl; ++i)
      tr[p].v[i] = make_pair(2000000000, make_pair(0, 0));
    return;
  }
  int mid = (L + R) >> 1;
  if (x <= mid)
    Update(L, mid, p << 1, x);
  else
    Update(mid + 1, R, p << 1 | 1, x);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
bool Check(int a0, int b0, int a1, int b1) {
  return a0 != a1 && a0 != b1 && b0 != a1 && b0 != b1;
}
long long Calc() {
  node &e = tr[1];
  long long res = e.same_end;
  int a = e.v[0].second.first, b = e.v[0].second.second, c = e.v[0].first;
  for (int i = 1; i < maxl; ++i) {
    if (!e.v[i].second.first) break;
    if (Check(a, b, e.v[i].second.first, e.v[i].second.second)) {
      res = min(res, (long long)c + e.v[i].first);
      break;
    }
  }
  set<pair<int, int>>::iterator it1 = S[a].begin(), it2;
  int cnt1 = 0, cnt2;
  for (; cnt1 < 3 && it1 != S[a].end(); cnt1++, it1++) {
    int p = it1->second;
    for (cnt2 = 0, it2 = S[b].begin(); cnt2 < 3 && it2 != S[b].end();
         cnt2++, it2++) {
      if (Check(a, p, b, it2->second)) {
        res = min(res, (long long)it1->first + it2->first);
      }
    }
  }
  return res;
}
int main() {
  int n, m;
  Rd(n);
  Rd(m);
  int a, b, c;
  for (int i = 1; i <= m; ++i) {
    Rd(a);
    Rd(b);
    Rd(c);
    S[a].insert(make_pair(c, b));
    S[b].insert(make_pair(c, a));
    G[a][b] = G[b][a] = c;
  }
  Build(1, n, 1);
  printf("%lld\n", Calc());
  int q;
  int op;
  Rd(q);
  while (q--) {
    Rd(op);
    Rd(a);
    Rd(b);
    if (op) {
      Rd(c);
      G[a][b] = G[b][a] = c;
      S[a].insert(make_pair(c, b));
      S[b].insert(make_pair(c, a));
    } else {
      c = G[a][b];
      S[a].erase(S[a].find(make_pair(c, b)));
      S[b].erase(S[b].find(make_pair(c, a)));
    }
    Update(1, n, 1, a);
    Update(1, n, 1, b);
    printf("%lld\n", Calc());
  }
  return 0;
}
