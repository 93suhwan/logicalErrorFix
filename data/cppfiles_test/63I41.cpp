#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 7;
int m1, m2, n, p1[maxn], p2[maxn];
int find1(int x) {
  if (p1[x] == x) return x;
  return p1[x] = find1(p1[x]);
}
int find2(int x) {
  if (p2[x] == x) return x;
  return p2[x] = find2(p2[x]);
}
void combine1(int x, int y) {
  int dx = find1(x);
  int dy = find1(y);
  p1[dx] = dy;
}
void combine2(int x, int y) {
  int dx = find2(x);
  int dy = find2(y);
  p2[dx] = dy;
}
vector<pair<int, int>> ans;
using namespace std;
const long long INF(0x3f3f3f3f3f3f3f3fll);
const long long inf(0x3f3f3f3f);
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
template <typename T>
void Out(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) Out(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long pow_mod(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long fact_pow(long long n, long long p) {
  long long res = 0;
  while (n) {
    n /= p;
    res += n;
  }
  return res;
}
long long mult(long long a, long long b, long long p) {
  a %= p;
  b %= p;
  long long r = 0, v = a;
  while (b) {
    if (b & 1) {
      r += v;
      if (r > p) r -= p;
    }
    v <<= 1;
    if (v > p) v -= p;
    b >>= 1;
  }
  return r;
}
long long quick_pow(long long a, long long b, long long p) {
  long long r = 1, v = a % p;
  while (b) {
    if (b & 1) r = mult(r, v, p);
    v = mult(v, v, p);
    b >>= 1;
  }
  return r;
}
bool CH(long long a, long long n, long long x, long long t) {
  long long r = quick_pow(a, x, n);
  long long z = r;
  for (long long i = 1; i <= t; i++) {
    r = mult(r, r, n);
    if (r == 1 && z != 1 && z != n - 1) return true;
    z = r;
  }
  return r != 1;
}
bool Miller_Rabin(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;
  long long x = n - 1, t = 0;
  while (!(x & 1)) {
    x >>= 1;
    t++;
  }
  srand(time(NULL));
  long long o = 8;
  for (long long i = 0; i < o; i++) {
    long long a = rand() % (n - 1) + 1;
    if (CH(a, n, x, t)) return false;
  }
  return true;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  long long t = x;
  x = y, y = t - (a / b) * y;
}
long long INV(long long a, long long b) {
  long long x, y;
  return exgcd(a, b, x, y), (x % b + b) % b;
}
long long crt(long long x, long long p, long long mod) {
  return INV(p / mod, mod) * (p / mod) * x;
}
long long FAC(long long x, long long a, long long b) {
  if (!x) return 1;
  long long ans = 1;
  for (long long i = 1; i <= b; i++)
    if (i % a) ans *= i, ans %= b;
  ans = pow_mod(ans, x / b, b);
  for (long long i = 1; i <= x % b; i++)
    if (i % a) ans *= i, ans %= b;
  return ans * FAC(x / a, a, b) % b;
}
long long C(long long n, long long m, long long a, long long b) {
  long long N = FAC(n, a, b), M = FAC(m, a, b), Z = FAC(n - m, a, b), sum = 0,
            i;
  for (i = n; i; i = i / a) sum += i / a;
  for (i = m; i; i = i / a) sum -= i / a;
  for (i = n - m; i; i = i / a) sum -= i / a;
  return N * pow_mod(a, sum, b) % b * INV(M, b) % b * INV(Z, b) % b;
}
long long exlucas(long long n, long long m, long long p) {
  long long t = p, ans = 0, i;
  for (i = 2; i * i <= p; i++) {
    long long k = 1;
    while (t % i == 0) {
      k *= i, t /= i;
    }
    ans += crt(C(n, m, i, k), p, k), ans %= p;
  }
  if (t > 1) ans += crt(C(n, m, t, t), p, t), ans %= p;
  return ans % p;
}
long long prime[100000], minprime[100000];
void euler(long long n) {
  long long c = 0, i, j;
  for (i = 2; i <= n; i++) {
    if (!minprime[i]) prime[++c] = i, minprime[i] = i;
    for (j = 1; j <= c && i * prime[j] <= n; j++) {
      minprime[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
struct Tree {
  long long l, r, sum, lazy, maxn, minn;
} tree[100000];
inline void push_up(long long rt) {
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  tree[rt].maxn = max(tree[rt << 1].maxn, tree[rt << 1 | 1].maxn);
  tree[rt].minn = min(tree[rt << 1].minn, tree[rt << 1 | 1].minn);
}
inline void push_down(long long rt, long long length) {
  if (tree[rt].lazy) {
    tree[rt << 1].lazy += tree[rt].lazy;
    tree[rt << 1 | 1].lazy += tree[rt].lazy;
    tree[rt << 1].sum += (length - (length >> 1)) * tree[rt].lazy;
    tree[rt << 1 | 1].sum += (length >> 1) * tree[rt].lazy;
    tree[rt << 1].minn += tree[rt].lazy;
    tree[rt << 1 | 1].minn += tree[rt].lazy;
    tree[rt << 1].maxn += tree[rt].lazy;
    tree[rt << 1 | 1].maxn += tree[rt].lazy;
    tree[rt].lazy = 0;
  }
}
inline void build(long long l, long long r, long long rt, long long *aa) {
  tree[rt].lazy = 0;
  tree[rt].l = l;
  tree[rt].r = r;
  if (l == r) {
    tree[rt].sum = aa[l];
    tree[rt].minn = tree[rt].sum;
    tree[rt].maxn = tree[rt].sum;
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, rt << 1, aa);
  build(mid + 1, r, rt << 1 | 1, aa);
  push_up(rt);
}
inline void update_range(long long L, long long R, long long key,
                         long long rt) {
  if (tree[rt].r < L || tree[rt].l > R) return;
  if (L <= tree[rt].l && R >= tree[rt].r) {
    tree[rt].sum += (tree[rt].r - tree[rt].l + 1) * key;
    tree[rt].minn += key;
    tree[rt].maxn += key;
    tree[rt].lazy += key;
    return;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  if (L <= mid) update_range(L, R, key, rt << 1);
  if (R > mid) update_range(L, R, key, rt << 1 | 1);
  push_up(rt);
}
inline long long query_range(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].sum;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = 0;
  if (L <= mid) ans += query_range(L, R, rt << 1);
  if (R > mid) ans += query_range(L, R, rt << 1 | 1);
  return ans;
}
inline long long query_min(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].minn;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = (0x3f3f3f3f3f3f3f3fll);
  if (L <= mid) ans = min(ans, query_min(L, R, rt << 1));
  if (R > mid) ans = min(ans, query_min(L, R, rt << 1 | 1));
  return ans;
}
inline long long query_max(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].maxn;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = -(0x3f3f3f3f3f3f3f3fll);
  if (L <= mid) ans = max(ans, query_max(L, R, rt << 1));
  if (R > mid) ans = max(ans, query_max(L, R, rt << 1 | 1));
  return ans;
}
signed main() {
  cin >> n >> m1 >> m2;
  euler(n);
  for (long long i = 1; i <= n; i++) p1[i] = p2[i] = i;
  for (long long i = 1; i <= m1; i++) {
    long long u, v;
    cin >> u >> v;
    combine1(u, v);
  }
  for (long long i = 1; i <= m2; i++) {
    long long u, v;
    cin >> u >> v;
    combine2(u, v);
  }
  cout << min(n - m1 - 1, n - m2 - 1) << endl;
  long long fff = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (j == i) continue;
      if (i != j) {
        fff++;
      }
      if (find1(i) != find1(j) && find2(i) != find2(j))
        p1[find1(i)] = find1(j), p2[find2(i)] = find2(j);
      cout << i << " " << j << endl;
    }
  }
  return 0;
}
