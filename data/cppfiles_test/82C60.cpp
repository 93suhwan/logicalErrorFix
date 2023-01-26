#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, Q = 3e5;
int n, q, k;
int a[N + 1];
int ma[N + 1];
struct query {
  int id, l, r;
};
vector<query> qry[N];
long long res[Q + 1];
void read(int &x) {
  char c;
  x = 0;
  while (isspace(c = getchar()))
    ;
  do {
    x = x * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return;
}
void initMinA() {
  static int h = 1, t = 0, q[N + 1];
  for (int i = 1; i <= n; ++i) {
    while ((h <= t) && (i - q[h] > k)) {
      ++h;
    }
    while ((h <= t) && (a[i] <= a[q[t]])) {
      --t;
    }
    q[++t] = i;
    ma[i] = a[q[h]];
  }
  return;
}
namespace ST {
const int L = 18;
int n, *a;
int st[L + 1][N + 1];
inline int cmin(int x, int y) { return a[x] <= a[y] ? x : y; }
void init(int _n, int _a[]) {
  n = _n, a = _a;
  iota(st[0] + 1, st[0] + n + 1, 1);
  for (int l = 1; l <= L; ++l) {
    for (int i = 1; i + (1 << l) - 1 <= n; ++i) {
      st[l][i] = cmin(st[l - 1][i], st[l - 1][i + (1 << l - 1)]);
    }
  }
  return;
}
int query(int l, int r) {
  int g = 31 - __builtin_clz(r - l + 1);
  return cmin(st[g][l], st[g][r - (1 << g) + 1]);
}
}  // namespace ST
void solve(int x) {
  static int c, v[N + 1], nex[N + 1];
  static int t, s[N + 1];
  static long long f[N + 1];
  c = 0;
  for (int i = x ? x : k; i <= n; i += k) {
    v[++c] = ma[i];
  }
  t = 0;
  for (int i = c; i; --i) {
    while (t && (v[s[t]] >= v[i])) {
      --t;
    }
    nex[i] = t ? s[t] : -1;
    s[++t] = i;
  }
  for (int i = c; i; --i) {
    if (nex[i] != -1) {
      f[i] = f[nex[i]] + 1ll * v[i] * (nex[i] - i);
    } else {
      f[i] = 1ll * v[i] * (c - i + 1);
    }
  }
  ST::init(c, v);
  for (query q : qry[x]) {
    int p = ST::query(q.l, q.r);
    res[q.id] += f[q.l] - f[p] + 1ll * v[p] * (q.r - p + 1);
  }
  return;
}
int main() {
  read(n), read(q), read(k);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  for (int i = 1, l, r; i <= q; ++i) {
    read(l), read(r);
    if (r - l >= k) {
      qry[l % k].push_back(
          query{i, (l + k - 1) / k + 1, (l + k - 1) / k + (r - l) / k});
    }
    res[i] = a[l];
  }
  initMinA();
  for (int i = 0; i < k; ++i) {
    if (!qry[i].empty()) {
      solve(i);
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%I64d\n", res[i]);
  }
  return 0;
}
