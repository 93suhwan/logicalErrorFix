#include <bits/stdc++.h>
using namespace std;
const long long dim = 300009, inf = 1e18;
struct seg {
  long long l, r, w;
} v[dim];
long long aint[dim];
void Update(long long nod, long long st, long long dr, long long l, long long r,
            long long val) {
  if (l > r) return;
  if (st == dr) {
    aint[nod] += val;
    return;
  } else {
    long long mij = (st + dr) / 2;
    Update(2 * nod, st, mij, l, min(mij, r), val);
    Update(2 * nod + 1, mij + 1, dr, max(mij + 1, l), r, val);
  }
  aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
}
long long Query(long long nod, long long st, long long dr, long long l,
                long long r) {
  if (st == l && dr == r) return aint[nod];
  long long mij = (st + dr) / 2;
  if (r <= mij)
    return Query(2 * nod, st, mij, l, r);
  else if (l >= mij + 1)
    return Query(2 * nod + 1, mij + 1, dr, l, r);
  else
    return min(Query(2 * nod, st, mij, l, mij),
               Query(2 * nod + 1, mij + 1, dr, mij + 1, r));
}
bool cmp(seg a, seg b) { return a.w <= b.w; }
set<long long> s;
signed main() {
  long long n, m, ans = inf;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i].l >> v[i].r >> v[i].w;
  }
  sort(v + 1, v + n + 1, cmp);
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    Update(1, 1, m, v[i].l, v[i].r, 1);
    s.insert(v[i].w);
    if (Query(1, 1, m, 1, m) >= 1) ans = min(ans, *s.rbegin() - *s.begin());
    while (Query(1, 1, m, 1, m) >= 1 && Query(1, 1, m, v[p].l, v[p].r) >= 2) {
      Update(1, 1, m, v[p].l, v[p].r, -1);
      s.erase(v[p].w);
      p++;
      ans = min(ans, *s.rbegin() - *s.begin());
    }
  }
  cout << ans;
}
