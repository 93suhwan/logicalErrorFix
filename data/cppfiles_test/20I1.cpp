#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
long long MOD = (1ll << 31) - 1;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const long long SIZE = 2e5 + 3;
struct Seg {
  int l, r, mid;
  long long val, lazy = 0;
} seg[SIZE << 2];
void update(int l, int r, int type, int node);
void pDown(int node) {
  if (seg[node].lazy && seg[node].l != seg[node].r) {
    update(seg[node].l, seg[node].mid, seg[node].lazy, node * 2);
    update(seg[node].mid + 1, seg[node].r, seg[node].lazy, node * 2 + 1);
    seg[node].lazy = 0;
  }
}
void pUp(int node) {
  seg[node].val = max(seg[2 * node].val, seg[2 * node + 1].val);
}
void build(int l, int r, int node = 1) {
  seg[node].l = l, seg[node].r = r, seg[node].mid = (l + r) >> 1,
  seg[node].lazy = 0;
  if (l == r) {
    seg[node].val = 0;
  } else {
    build(l, seg[node].mid, 2 * node);
    build(seg[node].mid + 1, r, 2 * node + 1);
    pUp(node);
  }
}
void update(int l, int r, int type, int node = 1) {
  if (l <= seg[node].l && seg[node].r <= r) {
    seg[node].val += type, seg[node].lazy += type;
  } else {
    pDown(node);
    if (l <= seg[node].mid) update(l, r, type, 2 * node);
    if (r > seg[node].mid) update(l, r, type, 2 * node + 1);
    pUp(node);
  }
}
long long query(int l, int r, int node = 1) {
  if (l <= seg[node].l && seg[node].r <= r) {
    return seg[node].val;
  } else {
    pDown(node);
    long long ret = 0;
    if (l <= seg[node].mid) ret = max(ret, query(l, r, 2 * node));
    if (r > seg[node].mid) ret = max(ret, query(l, r, 2 * node + 1));
    return ret;
  }
}
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int T = 1;
  for (int(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n, k;
    cin >> n >> k;
    vector<long long> pos[n + 1];
    for (int(p) = (0); (p) <= ((n * k) - 1); (p)++) {
      long long col;
      cin >> col;
      pos[col].emplace_back(p + 1);
    }
    vector<tuple<long long, long long, long long, long long>> seg;
    for (int(col) = (1); (col) <= (n); (col)++) {
      for (int(i) = (0); (i) <= ((k - 1) - 1); (i)++) {
        long long r = pos[col][i + 1], l = pos[col][i];
        long long len = r - l + 1;
        ;
        seg.emplace_back(len, l, r, col);
      }
    }
    sort((seg).begin(), (seg).end());
    build(1, n * k);
    long long tot = 0, idx = 0;
    long long lim = (n + k - 2) / (k - 1);
    vector<long long> done(n + 1, 0);
    vector<pair<long long, long long>> ans(n + 1);
    while (tot < n && idx < seg.size()) {
      auto [len, l, r, col] = seg[idx++];
      if (done[col] || query(l, r) >= lim) continue;
      done[col] = 1, tot++;
      ans[col] = {l, r};
      update(l, r, 1);
    };
    for (int(col) = (1); (col) <= (n); (col)++) {
      auto [l, r] = ans[col];
      ;
      cout << l << " " << r << endl;
    }
  }
  return 0;
}
