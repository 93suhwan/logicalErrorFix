#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int SIZE = 1000002;
const long long INF = 1LL << 30;
const double eps = 1e-6;
const double PI = 3.1415926535897932;
template <int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) : x(sig % MOD) {}
  ModInt(signed long long sig) : x(sig % MOD) {}
  int get() const { return (int)x; }
  ModInt pow(long long p) {
    ModInt res = 1, a = *this;
    while (p) {
      if (p & 1) res *= a;
      a *= a;
      p >>= 1;
    }
    return res;
  }
  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream &operator<<(ostream &os, ModInt a) {
    os << a.x;
    return os;
  }
};
typedef ModInt<(int)1e9 + 7> mint;
int d[200009];
unordered_map<int, vector<int>> p;
int e[200009], root[200009];
struct node {
  int cnt, lc, rc;
  long long sum;
  pair<mint, mint> hh;
} tree[4000009];
int nc = 0;
int create_node(int _lc, int _rc, int _cnt, long long _sum, pair<mint, mint> ph,
                pair<mint, mint> nh) {
  int idx = ++nc;
  tree[idx].lc = _lc;
  tree[idx].rc = _rc;
  tree[idx].cnt = _cnt;
  tree[idx].sum = _sum;
  tree[idx].hh = {ph.first + nh.first, ph.second + nh.second};
  return idx;
}
void up(int &root, int proot, int s, int e, int x, int v, pair<mint, mint> nh) {
  root = create_node(tree[proot].lc, tree[proot].rc, tree[proot].cnt + 1,
                     tree[proot].sum + v, tree[proot].hh, nh);
  if (s == e) return;
  int m = (s + e) >> 1;
  if (x > m)
    up(tree[root].rc, tree[proot].rc, m + 1, e, x, v, nh);
  else
    up(tree[root].lc, tree[proot].lc, s, m, x, v, nh);
}
int quCnt(int l, int r, int s, int e, int x, int y) {
  if (s == x && e == y) return tree[r].cnt - tree[l].cnt;
  int m = (s + e) >> 1;
  if (x > m) return quCnt(tree[l].rc, tree[r].rc, m + 1, e, x, y);
  if (y <= m) return quCnt(tree[l].lc, tree[r].lc, s, m, x, y);
  return quCnt(tree[l].lc, tree[r].lc, s, m, x, m) +
         quCnt(tree[l].rc, tree[r].rc, m + 1, e, m + 1, y);
}
long long quSum(int l, int r, int s, int e, int x, int y) {
  if (s == x && e == y) return tree[r].sum - tree[l].sum;
  int m = (s + e) >> 1;
  if (x > m) return quSum(tree[l].rc, tree[r].rc, m + 1, e, x, y);
  if (y <= m) return quSum(tree[l].lc, tree[r].lc, s, m, x, y);
  return quSum(tree[l].lc, tree[r].lc, s, m, x, m) +
         quSum(tree[l].rc, tree[r].rc, m + 1, e, m + 1, y);
}
pair<mint, mint> quHash(int l, int r, int s, int e, int x, int y) {
  if (s == x && e == y) {
    pair<mint, mint> lv = tree[l].hh, rv = tree[r].hh;
    return {rv.first - lv.first, rv.second - lv.second};
  }
  int m = (s + e) >> 1;
  if (x > m) return quHash(tree[l].rc, tree[r].rc, m + 1, e, x, y);
  if (y <= m) return quHash(tree[l].lc, tree[r].lc, s, m, x, y);
  pair<mint, mint> lv = quHash(tree[l].lc, tree[r].lc, s, m, x, m),
                   rv = quHash(tree[l].rc, tree[r].rc, m + 1, e, m + 1, y);
  return {rv.first + lv.first, rv.second + lv.second};
}
int main() {
  int n, qn;
  scanf("%d%d", &n, &qn);
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &(d[i]));
    if (((int)(p[d[i]]).size()))
      e[i] = p[d[i]].back() + 1;
    else
      e[i] = 0;
    p[d[i]].push_back(i);
  }
  for (int i = 0; i < (n); ++i) {
    up(root[i + 1], root[i], 0, n, e[i], d[i],
       {mint(d[i]) * d[i], (mint(d[i]) * d[i]) * d[i]});
  }
  for (int i = 0; i < (qn); ++i) {
    int a, b, dd;
    scanf("%d%d%d", &a, &b, &dd);
    mint dist = dd;
    if (a >= b) {
      puts("Yes");
      continue;
    }
    long long kCnt = quCnt(root[a - 1], root[b], 0, n, 0, a - 1);
    mint k = kCnt;
    mint dSum = quSum(root[a - 1], root[b], 0, n, 0, a - 1);
    mint s = dSum - dist * (((kCnt * (kCnt - 1) / 2)) % MOD);
    s /= k;
    pair<mint, mint> distH = quHash(root[a - 1], root[b], 0, n, 0, a - 1);
    mint expectSq = s * s * k + s * dist * k * (k - 1) +
                    k * (k - 1) * (k * 2 - 1) / 6 * dist * dist;
    if (expectSq.x != distH.first.x) {
      puts("No");
    } else
      puts("Yes");
  }
}
