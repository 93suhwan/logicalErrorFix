#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 9;
const int N2 = 1 << 13 | 9;
int a[N], vis[N2];
struct Segment_Tree {
  int n, L, R;
  int base[N2 * 4][13], K[13];
  void init(int _n) { n = _n; }
  void clear(int a[13]) { memset(a, 0, 13 * sizeof(int)); }
  void copy(int a[13], int b[13]) { memcpy(a, b, 13 * sizeof(int)); }
  void insert(int a[13], int k) {
    if (k == 0) return;
    for (int i = 0; i < 13; ++i) {
      if (k >> i & 1) {
        if (a[i])
          k ^= a[i];
        else {
          a[i] = k;
          break;
        }
      }
    }
  }
  void merge(int a[13], int b[13]) {
    for (int j = 0, k = b[0]; j < 13; k = b[++j]) {
      insert(a, k);
    }
  }
  void push_up(int o, int lc, int rc) {
    clear(base[o]);
    copy(base[o], base[lc]);
    merge(base[o], base[rc]);
  }
  void __q(int o, int l, int r) {
    if (r <= R) {
      merge(K, base[o]);
    } else {
      int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
      __q(lc, l, m);
      if (R > m) __q(rc, m + 1, r);
    }
  }
  void __upd(int o, int l, int r) {
    if (l == r) {
      merge(base[o], K);
    } else {
      int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
      if (L <= m)
        __upd(lc, l, m);
      else
        __upd(rc, m + 1, r);
      push_up(o, lc, rc);
    }
  }
  void upd(int P) {
    clear(K);
    if (P > 0) {
      R = P - 1;
      __q(1, 0, n);
    }
    L = P;
    insert(K, P);
    __upd(1, 0, n);
  }
  void __get(int o, int l, int r) {
    if (l == r) {
      for (int x = 0; x < (1 << 13); ++x) {
        bool f = false;
        for (int k = x, i = 0; i < 13; ++i) {
          if (k >> i & 1) {
            if (base[o][i])
              k ^= base[o][i];
            else {
              f = true;
              break;
            }
          }
        }
        if (!f) vis[x] = true;
      }
    } else {
      int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
      __get(lc, l, m);
      __get(rc, m + 1, r);
    }
  }
  void get_ans() { __get(1, 0, n); }
} segt;
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  segt.init(5000);
  for (int i = 1; i <= n; ++i) {
    segt.upd(a[i]);
  }
  segt.get_ans();
  vector<int> ans;
  vis[0] = true;
  for (int i = 0; i < N2; ++i) {
    if (vis[i]) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i : ans) printf("%d ", i);
  printf("\n");
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
