#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 1e9 + 7;
long long f[N], sum[N];
int n, m, l[N], r[N], vis[N];
struct Res {
  int st, ed, id;
  bool operator<(const Res &t) const { return st < t.st; }
} a[N];
inline int lowbit(int x) { return x & (-x); }
void update(int x, int v) {
  while (x <= 2 * n) {
    sum[x] = (sum[x] + v) % mod;
    x += lowbit(x);
  }
}
long long query(int x) {
  long long ans = 0;
  while (x) {
    ans = (ans + sum[x]) % mod;
    x -= lowbit(x);
  }
  return ans;
}
set<int> st;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    a[i] = {l[i], r[i], i};
  }
  sort(a + 1, a + 1 + n);
  for (int i = n; i >= 1; i--) {
    f[a[i].id] = (query(a[i].ed) + 1) % mod;
    update(a[i].ed, f[a[i].id]);
  }
  scanf("%d", &m);
  for (int i = 1, x; i <= m; i++) {
    scanf("%d", &x);
    vis[x] = 1;
    st.insert(r[x]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (st.size() == 0) {
      break;
    }
    if (vis[a[i].id]) {
      ans = (ans + f[a[i].id]) % mod;
      st.erase(st.find(a[i].ed));
      continue;
    }
    auto p = st.end();
    p--;
    if (*p >= a[i].ed) {
      ans = (ans + f[a[i].id]) % mod;
    }
  }
  printf("%lld\n", ans % mod);
  return 0;
}
