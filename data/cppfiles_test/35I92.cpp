#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &x) {
  x = 0;
  char ch = getchar();
  int f = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
  x *= f;
}
template <class T>
void cmin(T &x, T y) {
  x = min(x, y);
}
template <class T>
void cmax(T &x, T y) {
  x = max(x, y);
}
const int mod = 1e9 + 7;
template <class T>
T add(T x, T y) {
  return (x + y) % mod;
}
template <class T>
T sub(T x, T y) {
  return (x - y + mod) % mod;
}
template <class T>
T mul(T x, T y) {
  return 1ll * x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y) % mod;
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y + mod) % mod;
}
template <class T>
void Mul(T &x, T y) {
  x = 1ll * x * y % mod;
}
template <class T>
T qpow(T a, T b = mod - 2) {
  T ret = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ret, a);
  return ret;
}
const int N = 1e6 + 10, V = 1e6;
int n, a[N], L[N], top;
pair<int, int> stk[N];
vector<int> vec[V + 5];
char s[N];
int pri[V + 5], mark[V + 5], cnt, mn[V + 5];
void sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!mark[i]) pri[++cnt] = i, mn[i] = i;
    for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
      mark[i * pri[j]] = 1, mn[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
}
void ins(int x, int id) {
  L[id] = id;
  while (x > 1) {
    vec[mn[x]].push_back(id), x /= mn[x];
  }
}
void del(int x, int id) {
  if (x == 1) {
    L[id] = id;
    return;
  }
  L[id] = id;
  while (x > 1) {
    if (vec[mn[x]].empty()) {
      L[id] = 0;
      return;
    }
    cmin(L[id], vec[mn[x]].back());
    vec[mn[x]].pop_back();
    x /= mn[x];
  }
}
signed main() {
  sieve(V);
  rd(n);
  for (int i = 1; i <= n; i++) rd(a[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '*')
      ins(a[i], i);
    else
      del(a[i], i);
  }
  int pos = 0;
  long long ans = 0;
  for (int l = n; l >= 1; l--) {
    int r = l;
    while (top && L[stk[top].first] >= L[l]) {
      if (pos == top) --pos;
      r = stk[top].second;
      --top;
    }
    stk[++top] = make_pair(l, r);
    while (pos <= top && L[stk[pos].first] < l) ++pos;
    while (pos > 1 && L[stk[pos - 1].first] >= l) --pos;
    if (pos <= top && L[stk[pos].first] >= l) {
      ans += stk[pos].second - l + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
