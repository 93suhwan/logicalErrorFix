#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x) {
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
int m, n, t = 1, st, en;
struct Trie {
  struct node {
    int a[2];
    int ans, len;
    int ma, mi;
    node() {
      a[0] = a[1] = 0;
      ans = 1e9;
      len = 1;
      ma = -1e9;
      mi = 1e9;
    }
    node(int x) {
      a[0] = a[1] = 0;
      ans = 1e9;
      len = 1;
      ma = mi = 0;
    }
  } nul;
  vector<node> v;
  Trie() { v.assign(1, nul); }
  inline void push_up(int p) {
    v[p].mi = min(v[(v[p].a[0])].mi, v[(v[p].a[1])].mi + v[(v[p].a[0])].len);
    v[p].ma = max(v[(v[p].a[0])].ma, v[(v[p].a[1])].ma + v[(v[p].a[0])].len);
    v[p].ans =
        min({v[(v[p].a[0])].ans, v[(v[p].a[1])].ans,
             v[(v[p].a[1])].mi - v[(v[p].a[0])].ma + v[(v[p].a[0])].len});
    v[p].len = v[(v[p].a[0])].len + v[(v[p].a[1])].len;
  }
  int build(int p, int l, int r) {
    if (!p) v.push_back(nul), p = (int)v.size() - 1;
    if (l == r) return p;
    int mid = (l + r) >> 1;
    (v[p].a[0]) = build((v[p].a[0]), l, mid);
    (v[p].a[1]) = build((v[p].a[1]), mid + 1, r);
    push_up(p);
    return p;
  }
  void insert(int p, int dep, int val) {
    if (!(~dep)) return v[p] = node(1), void();
    insert(v[p].a[val >> dep & 1], dep - 1, val);
    push_up(p);
  }
  void rotate(int p, int dep, int lim) {
    if (dep == lim) {
      swap((v[p].a[0]), (v[p].a[1]));
      push_up(p);
      return;
    }
    rotate((v[p].a[0]), dep - 1, lim);
    rotate((v[p].a[1]), dep - 1, lim);
    push_up(p);
  }
} tr;
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  tr.build(0, 0, (1 << k) - 1);
  for (int i = 0; i < n; i++) tr.insert(1, k - 1, a[i]);
  vector<int> ans(1 << k), gray(1 << k);
  for (int i = 0; i < 1 << k; i++) {
    gray[i] = (i >> 1) ^ i;
    vector<int> tmp;
    for (int j = 0; j < k; j++, gray[i] >>= 1) tmp.push_back(gray[i] & 1);
    for (int j = 0; j < k; j++) gray[i] = gray[i] << 1 | tmp[j];
  }
  for (int i = 0; i < 1 << k; i++) {
    ans[gray[i]] = tr.v[1].ans;
    if ((i + 1) < 1 << k) {
      int pos = 31 - __builtin_clz(gray[i] ^ gray[i + 1]);
      tr.rotate(1, k - 1, pos);
    }
  }
  for (int i = 0; i < 1 << k; i++) cout << ans[i] << " \n"[i + 1 == 1 << k];
}
