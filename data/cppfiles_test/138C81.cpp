#include <bits/stdc++.h>
using namespace std;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], str[64];
int l = SIZE, r = SIZE;
int read(char* s) {
  while (r) {
    for (; l < r && buf[l] <= ' '; l++)
      ;
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  int cur = 0;
  while (r) {
    for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  s[cur] = '\0';
  return cur;
}
template <typename type>
bool read(type& x, int len = 0, int cur = 0, bool flag = false) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  if (flag) x = -x;
  return true;
}
template <typename type>
type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  return flag ? -x : x;
}
}  // namespace FastIO
using FastIO::read;
const int N = 5e5 + 10, MAXN = 5e3 + 10, mod = 1e9 + 7;
int a[N], b[N], idx[N], pre[N], sz[N], L[N], R[N];
long long sum[N], cal[N], ans[N], pos[N], res;
struct node {
  int val, tem;
  bool operator<(const node& n) const {
    if (val == n.val) return tem < n.tem;
    return val < n.val;
  }
} NODE[N];
int Find(int x) { return x == pre[x] ? x : pre[x] = Find(pre[x]); }
void merge(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  res -= cal[u], res -= cal[v];
  pre[v] = u;
  sz[u] += sz[v];
  L[u] = min(L[u], L[v]);
  R[u] = max(R[u], R[v]);
  cal[u] = sum[R[u]] - sum[R[u] - sz[u]];
  res += cal[u];
}
struct test {
  int u, v, cnt;
  bool operator<(const test& t) const { return cnt > t.cnt; }
};
int main() {
  int n, m, q;
  read(n), read(m), read(q);
  int tot = 0;
  for (int i = 1; i <= n; i++) read(a[i]), NODE[++tot] = {a[i], 0};
  for (int i = 1; i <= m; i++) read(b[i]), NODE[++tot] = {b[i], 1};
  sort(NODE + 1, NODE + tot + 1);
  for (int i = 1; i <= tot; i++) {
    L[i] = R[i] = pre[i] = i;
    sum[i] = sum[i - 1] + NODE[i].val;
    if (NODE[i].tem == 0) sz[i] = 1, cal[i] = NODE[i].val, res += cal[i];
  }
  priority_queue<test> PQ;
  for (int i = 2; i <= tot; i++) {
    int u = i, v = i - 1;
    u = Find(u), v = Find(v);
    if (NODE[i].val == NODE[i - 1].val) {
      merge(u, v);
    } else {
      PQ.push({u, v, NODE[i].val - NODE[i - 1].val});
    }
  }
  int Last = 0, K = 1;
  ans[K = 1] = res;
  pos[1] = 0;
  while (!PQ.empty()) {
    test p = PQ.top();
    PQ.pop();
    if (p.cnt != Last) {
      Last = p.cnt;
      K++;
      pos[K] = p.cnt;
    }
    int u = p.u, v = p.v;
    merge(u, v);
    ans[K] = res;
  }
  for (int i = 1; i <= q; i++) {
    int num;
    read(num);
    int idx = upper_bound(pos + 1, pos + K + 1, num) - pos - 1;
    printf("%lld\n", ans[idx]);
  }
  return 0;
}
