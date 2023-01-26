#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 7 + 1e9;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
struct node {
  int idx;
  node *next;
  node *tail;
  node() { next = tail = NULL; }
};
vector<node> g(N);
void wabalabadubdub() {
  int q, t, x, y, len = -1;
  ;
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      ++len;
      node *nd = new node;
      nd->idx = len;
      if (g[x].tail != NULL)
        g[x].tail->next = nd;
      else
        g[x].next = nd;
      g[x].tail = nd;
    } else {
      cin >> x >> y;
      if (x == y) continue;
      if (g[y].tail != NULL)
        g[y].tail->next = g[x].next;
      else
        g[y].next = g[x].next;
      g[y].tail = g[x].tail;
      g[x].tail = NULL;
      g[x].next = NULL;
    }
  }
  vector<int> a(len + 1);
  for (int i = 1; i < N; ++i) {
    node *u = g[i].next;
    while (u != NULL) {
      a[u->idx] = i;
      u = u->next;
    }
  }
  for (int i : a) cout << i << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) wabalabadubdub();
}
