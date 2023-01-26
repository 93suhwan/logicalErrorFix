#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int INF = 1e9;
struct Node {
  Node* ch[2];
  int mn = INF;
  int mx = -INF;
  int minAdj = INF;
  void pull(int l) {
    mn = min(ch[0]->mn, ch[1]->mn + (1 << l));
    mx = max(ch[0]->mx, ch[1]->mx + (1 << l));
    minAdj = min(ch[0]->minAdj, ch[1]->minAdj);
    minAdj = min(minAdj, ch[1]->mn + (1 << l) - ch[0]->mx);
  }
};
Node* newNode() {
  static deque<Node> cache;
  cache.push_back(Node());
  return &cache.back();
}
vector<bool> has;
void init(Node* x, int l, int a) {
  if (l < 0) {
    if (has[a]) x->mn = x->mx = 0;
    return;
  }
  for (int i = 0; i < 2; ++i) {
    x->ch[i] = newNode();
    init(x->ch[i], l - 1, a * 2 + i);
  }
  x->pull(l);
}
void toggle(Node* x, int l, int target) {
  if (l == target) {
    swap(x->ch[0], x->ch[1]);
  } else {
    toggle(x->ch[0], l - 1, target);
    toggle(x->ch[1], l - 1, target);
  }
  x->pull(l);
}
vector<int> genGrayCode(int n) {
  if (n == 1) return {0, 1};
  auto ret = genGrayCode(n - 1);
  ret.resize(1 << n);
  for (int i = 0; i < (1 << (n - 1)); ++i)
    ret[(1 << n) - i - 1] = ret[i] | (1 << (n - 1));
  return ret;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  has.assign(1 << k, false);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    has[a] = true;
  }
  Node* root = newNode();
  init(root, k - 1, 0);
  auto g = genGrayCode(k);
  vector<int> revG(g.size());
  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < k; ++j)
      if (g[i] & (1 << j)) revG[i] |= 1 << (k - j - 1);
  }
  vector<int> ans(1 << k);
  ans[0] = root->minAdj;
  for (int i = 1; i < revG.size(); ++i) {
    int v = revG[i] ^ revG[i - 1];
    int bit = 31 - __builtin_clz(v);
    toggle(root, k - 1, bit);
    ans[revG[i]] = root->minAdj;
  }
  for (int a : ans) printf("%d ", a);
}
