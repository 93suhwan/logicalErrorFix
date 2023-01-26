#include <bits/stdc++.h>
using namespace std;
struct unionFindSet {
  int fa[150005];
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
} ufs;
int n, q, a[150005], lst[1000005], pb[25];
int main() {
  scanf("%d %d", &n, &q);
  ufs.makeSet(n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    int tmp = a[i];
    for (int j = 2; j * j <= tmp; ++j) {
      if (tmp % j == 0) {
        if (lst[j]) ufs.unionSet(lst[j], i);
        lst[j] = i;
        while (tmp % j == 0) tmp /= j;
      }
    }
    if (tmp != 1) {
      if (lst[tmp]) ufs.unionSet(lst[tmp], i);
      lst[tmp] = i;
      tmp = 1;
    }
  }
  vector<pair<int, int>> Ret;
  for (int i = 1; i <= n; ++i) {
    int tmp = a[i] + 1, cnt = 0;
    for (int j = 2; j * j <= tmp; ++j) {
      if (tmp % j == 0) {
        if (lst[j]) pb[++cnt] = ufs.findSet(lst[j]);
        while (tmp % j == 0) tmp /= j;
      }
    }
    if (tmp != 1) {
      if (lst[tmp]) pb[++cnt] = ufs.findSet(lst[tmp]);
      tmp = 1;
    }
    pb[++cnt] = ufs.findSet(i);
    sort(pb + 1, pb + 1 + cnt);
    cnt = unique(pb + 1, pb + 1 + cnt) - pb - 1;
    for (int j = 1; j <= cnt; ++j)
      for (int k = j + 1; k <= cnt; ++k)
        Ret.push_back(make_pair(min(pb[j], pb[k]), max(pb[j], pb[k])));
  }
  sort(Ret.begin(), Ret.end());
  Ret.erase(unique(Ret.begin(), Ret.end()), Ret.end());
  while (q-- > 0) {
    int s, t;
    scanf("%d %d", &s, &t);
    s = ufs.findSet(s), t = ufs.findSet(t);
    if (s > t) swap(s, t);
    if (s == t)
      puts("0");
    else if (lower_bound(Ret.begin(), Ret.end(), make_pair(s, t)) !=
                 Ret.end() &&
             *lower_bound(Ret.begin(), Ret.end(), make_pair(s, t)) ==
                 make_pair(s, t))
      puts("1");
    else
      puts("2");
  }
  return 0;
}
