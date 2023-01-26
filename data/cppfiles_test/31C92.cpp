#include <bits/stdc++.h>
int getbit(long long x, int y) { return (x >> y) & 1; }
long long getoff(long long x, int y) { return x ^ ((1ll) << y); }
using namespace std;
struct node {
  int diff, ma, mi;
  node *c[2];
  node() {
    diff = 2e9;
    ma = -1e9;
    mi = 1e9;
    c[0] = nullptr;
    c[1] = nullptr;
  }
};
node *trie = new node;
int n, k, f[2000010];
void calc(node *u, int depth) {
  u->ma = -1e9;
  u->mi = 1e9;
  u->diff = 2e9;
  u->ma = max(u->c[0]->ma, (1 << depth) + u->c[1]->ma);
  u->mi = min(u->c[0]->mi, (1 << depth) + u->c[1]->mi);
  if (u->ma < 0) u->ma = -1e9;
  if (u->c[0]->ma != -1e9 && u->c[0]->ma != u->ma)
    u->mi = min(u->mi, u->c[0]->ma);
  int f1 = u->c[1]->mi;
  if (f1 == 1e9 && u->c[1]->ma != -1e9) f1 = u->c[1]->ma;
  int f2 = u->c[0]->ma;
  if (f2 == -1e9 && u->c[0]->mi != 1e9) f2 = u->c[0]->mi;
  u->diff = min(u->c[0]->diff, u->c[1]->diff);
  u->diff = min(u->diff, f1 - f2 + (1 << depth));
}
void build(node *u, int depth) {
  if (depth == -1) return;
  u->c[0] = new node;
  u->c[1] = new node;
  build(u->c[0], depth - 1);
  build(u->c[1], depth - 1);
}
void add(node *u, int L, int x, int depth) {
  if (depth == -1) {
    u->ma = x - L;
    return;
  }
  int kt = getbit(x, depth);
  if (kt == 0)
    add(u->c[kt], L, x, depth - 1);
  else
    add(u->c[kt], L + (1 << depth), x, depth - 1);
  calc(u, depth);
}
void update(node *u, int depth, int stop) {
  if (depth == stop) {
    swap(u->c[0], u->c[1]);
    calc(u, depth);
    return;
  }
  update(u->c[0], depth - 1, stop);
  update(u->c[1], depth - 1, stop);
  calc(u, depth);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  build(trie, k - 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    add(trie, 0, x, k - 1);
  }
  vector<int> lvt;
  lvt.emplace_back(0);
  for (int q = 1; q <= k; ++q) {
    int sz = lvt.size();
    while (sz--) lvt.emplace_back(lvt[sz] * 2 + 1);
    for (int i = 0; i < (1 << (q - 1)); ++i) lvt[i] <<= 1;
  }
  vector<int> vt;
  int pos;
  for (int i = 0; i < (1 << k); ++i)
    if (lvt[i] == 0) {
      pos = i;
      break;
    }
  for (int i = 1; i <= (1 << k); ++i) {
    vt.emplace_back(lvt[pos]);
    pos = (pos + 1) % (1 << k);
  }
  f[0] = trie->diff;
  for (int i = 1; i < (1 << k); ++i) {
    int mask = vt[i] ^ vt[i - 1];
    int stop;
    for (int i = 0; i < k; ++i)
      if (getbit(mask, i) == 1) {
        stop = i;
        break;
      }
    update(trie, k - 1, stop);
    f[vt[i]] = trie->diff;
  }
  for (int i = 0; i < (1 << k); ++i) cout << f[i] << " ";
  return 0;
}
