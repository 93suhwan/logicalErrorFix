#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1;
int a[N], pos[N];
char s[N];
struct SegT {
  struct node {
    int mx, se, tag, cnt;
    long long sum;
    node(int _mx = 0) {
      sum = mx = _mx;
      se = -1;
      tag = -1;
      cnt = 1;
    }
  } e[N << 2];
  inline void push_up(int p) {
    int l = ((p) << 1), r = ((p) << 1 | 1);
    if (e[l].mx == e[r].mx) {
      e[p].mx = e[l].mx;
      e[p].se = max(e[l].se, e[r].se);
      e[p].cnt = e[l].cnt + e[r].cnt;
      e[p].sum = e[l].sum + e[r].sum;
    } else {
      e[p].mx = max(e[l].mx, e[r].mx);
      e[p].se = max({e[l].mx == e[p].mx ? e[r].mx : e[l].mx, e[l].se, e[r].se});
      e[p].cnt = e[l].mx == e[p].mx ? e[l].cnt : e[r].cnt;
      e[p].sum = e[l].sum + e[r].sum;
    }
  }
  void build(int p, int l, int r) {
    if (l == r) {
      e[p] = node(n);
      return;
    }
    e[p].tag = -1;
    int mid = (l + r) >> 1;
    build(((p) << 1), l, mid);
    build(((p) << 1 | 1), mid + 1, r);
    push_up(p);
  }
  inline void upt(int p, int k) {
    if (e[p].mx > k) {
      e[p].tag = k;
      e[p].sum -= 1ll * (e[p].mx - k) * e[p].cnt;
      e[p].mx = k;
    }
  }
  inline void push_down(int p) {
    if (~e[p].tag) {
      upt(((p) << 1), e[p].tag);
      upt(((p) << 1 | 1), e[p].tag);
      e[p].tag = -1;
    }
  }
  void update(int p, int l, int r, int L, int R, int k) {
    if (L <= l && r <= R && e[p].se < k) {
      upt(p, k);
      return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (L <= mid) update(((p) << 1), l, mid, L, R, k);
    if (mid < R) update(((p) << 1 | 1), mid + 1, r, L, R, k);
    push_up(p);
  }
} tr;
int p[N], v[N], ma_p[N], mi_p[N];
int phi[N], mu[N];
void get_prime() {
  phi[1] = mu[1] = 1;
  ma_p[1] = mi_p[1] = 1;
  for (int i = 2; i <= N - 1; i++) {
    if (!v[i])
      v[i] = i, p[++p[0]] = i, mi_p[i] = ma_p[i] = i, phi[i] = i - 1,
      mu[i] = -1;
    for (int j = 1; j <= p[0]; j++) {
      if (p[j] > v[i] || p[j] > (N - 1) / i) break;
      int nxt = i * p[j];
      v[nxt] = p[j];
      ma_p[nxt] = ma_p[i];
      mi_p[nxt] = p[j];
      phi[nxt] = phi[i] * (i % p[j] ? p[j] - 1 : p[j]);
      mu[nxt] = mu[i] * (i % p[j] ? -1 : 0);
    }
  }
}
vector<pair<int, int> > vp[N];
int main() {
  get_prime();
  re(n);
  for (int i = 1; i <= n; i++) re(a[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    while (a[i] > 1) {
      int tmp = mi_p[a[i]], cnt = 0;
      while (!(a[i] % tmp)) a[i] /= tmp, cnt++;
      vp[tmp].push_back({i, cnt});
    }
  }
  tr.build(1, 1, n);
  for (int i = 1; i <= 1e6; i++)
    if (vp[i].size()) {
      int tot = vp[i].size();
      auto &v = vp[i];
      stack<int> stk;
      stk.push(0);
      for (int j = 1; j <= tot; j++) {
        pos[j] = v[j - 1].first;
        a[j] = a[j - 1] + v[j - 1].second * (s[pos[j]] == '*' ? 1 : -1);
        while (!stk.empty()) {
          if (a[stk.top()] < a[j]) {
            break;
          } else if (a[stk.top()] == a[j]) {
            stk.pop();
            break;
          } else {
            tr.update(1, 1, n, pos[stk.top()] + 1, pos[j], pos[j] - 1);
            stk.pop();
          }
        }
        stk.push(j);
      }
    }
  printf("%lld\n", tr.e[1].sum - 1ll * n * (n - 1) / 2);
}
