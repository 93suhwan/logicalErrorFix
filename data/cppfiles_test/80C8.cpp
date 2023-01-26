#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, a[1000005], b[1000005];
pair<int, int> perm[1000005];
struct fwt {
  int dat[1000005];
  void clear() {
    for (int i = 1; i <= (int)(n); i++) dat[i] = 0;
  }
  void add(int id, int val) {
    for (id++; id <= n; id += id & -id) dat[id] += val;
  }
  int query(int id) {
    int ret = 0;
    for (id++; id > 0; id -= id & -id) ret += dat[id];
    return ret;
  }
} tre;
long long ans;
priority_queue<int> que;
void addnew(int x) {
  if (que.empty()) {
    que.push(x);
  } else if (x >= que.top())
    que.push(x);
  else {
    ans += que.top() - x;
    que.push(x);
    que.push(x);
    que.pop();
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(m); i++) scanf("%d", &b[i]);
  sort(b, b + m);
  for (int i = 0; i < (int)(n); i++) perm[i] = make_pair(a[i], i);
  sort(perm, perm + n);
  ans = 0;
  tre.clear();
  for (int i = 0; i < (int)(n); i++) {
    ans += 2 * (i - tre.query(perm[i].second));
    tre.add(perm[i].second, 1);
  }
  while (!que.empty()) que.pop();
  for (int i = 0; i < (int)(n); i++) {
    int r = upper_bound(b, b + m, a[i]) - b,
        l = lower_bound(b, b + m, a[i]) - b;
    addnew(r);
    addnew(l);
    ans -= r - l;
  }
  assert(ans % 2 == 0);
  printf("%lld\n", ans / 2);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
