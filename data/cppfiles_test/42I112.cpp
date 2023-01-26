#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksc(long long a, long long b, long long mod) {
  return ((a * b -
           (long long)((long long)((long double)a / mod * b + 1e-3) * mod)) %
              mod +
          mod) %
         mod;
}
long long ksm1(long long a, long long n, long long mod) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (t *= a) %= mod;
  return t;
}
long long ksm2(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = ksc(res, a, mod);
    b >>= 1, a = ksc(a, a, mod);
  }
  return res % mod;
}
const int N = 3e5 + 5;
struct Edge {
  int l, r, w;
} arr[N];
bool cmp(Edge n1, Edge n2) { return n1.w < n2.w; }
struct Nod {
  int l, r;
  int add, minn;
} tr[N << 2];
void pushup(int rt) {
  tr[rt].minn = min(tr[rt << 1].minn, tr[rt << 1 | 1].minn);
}
void build(int rt, int l, int r) {
  tr[rt].l = l, tr[rt].r = r;
  if (l == r) return;
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
void pushdown(int rt) {
  if (tr[rt].add != 0) {
    tr[rt << 1].minn += tr[rt].add;
    tr[rt << 1 | 1].minn += tr[rt].add;
    tr[rt].add = 0;
  }
}
void modify(int rt, int l, int r, int val) {
  if (tr[rt].l >= l && tr[rt].r <= r) {
    tr[rt].minn += val;
    tr[rt].add += val;
    return;
  }
  pushdown(rt);
  int mid = tr[rt].l + tr[rt].r >> 1;
  if (mid >= l) modify(rt << 1, l, r, val);
  if (mid + 1 <= r) modify(rt << 1 | 1, l, r, val);
  pushup(rt);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i].l >> arr[i].r >> arr[i].w;
  sort(arr + 1, arr + 1 + n, cmp);
  build(1, 1, m);
  int l = 1, r = 0;
  int res = inf;
  while (l <= n) {
    int flag = 1;
    while (flag) {
      r++;
      if (r > n) break;
      modify(1, arr[r].l, arr[r].r, 1);
      if (tr[1].minn != 0) flag = 0;
    }
    if (r <= n) res = min(res, arr[r].w - arr[l].w);
    modify(1, arr[l].l, arr[l].r, -1);
    l++;
  }
  cout << res << endl;
  return 0;
}
