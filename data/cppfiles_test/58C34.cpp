#include <bits/stdc++.h>
using namespace std;
int n, m, x[200021], y[200021];
long long fact[2 * 200021];
void init() {
  fact[0] = 1;
  for (int i = (1); i <= (2 * 200021 - 1); i++)
    fact[i] = (fact[i - 1] * i) % 998244353;
}
long long qpow(long long a, int b) {
  long long ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) (ret *= a) %= 998244353;
    (a *= a) %= 998244353;
  }
  return ret;
}
long long C(int n, int m) {
  return fact[n] * qpow(fact[m] * fact[n - m] % 998244353, 998244353 - 2) %
         998244353;
}
struct fhq_Treap {
  struct node {
    int dat, val, siz, aux;
    bool counts;
    int c[2];
  } t[200021];
  int root, cnt;
  void init() { root = cnt = 0; }
  int New(int val) {
    t[++cnt].val = val, t[cnt].siz = 1;
    t[cnt].dat = rand(), t[cnt].counts = true;
    t[cnt].c[0] = t[cnt].c[1] = t[cnt].aux = 0;
    return cnt;
  }
  void push_up(int x) { t[x].siz = t[t[x].c[0]].siz + t[t[x].c[1]].siz + 1; }
  void split(int x, int val, int &l, int &r, int lft) {
    if (x == 0) {
      l = r = 0;
      return;
    }
    int siz = t[t[x].c[0]].siz + lft;
    if (t[x].val - t[x].aux + siz <= val)
      l = x, split(t[x].c[1], val, t[x].c[1], r, siz + 1);
    else
      r = x, split(t[x].c[0], val, l, t[x].c[0], lft);
    push_up(x);
  }
  int merge(int l, int r) {
    if (l == 0 || r == 0) return l + r;
    if (t[l].dat > t[r].dat) {
      t[l].c[1] = merge(t[l].c[1], r), push_up(l);
      return l;
    } else {
      t[r].c[0] = merge(l, t[r].c[0]), push_up(r);
      return r;
    }
  }
  bool insert(int val) {
    int x, y, z;
    split(root, val - 2, x, y, 0);
    split(y, val - 1, y, z, t[x].siz);
    bool ret = !y || !t[y].counts;
    if (!ret) t[y].counts = false;
    int p = merge(x, y), q = New(val);
    t[q].aux = t[p].siz;
    root = merge(merge(p, q), z);
    return ret;
  }
} Treap;
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  init();
  while (T--) {
    cin >> n >> m;
    for (int i = (1); i <= (m); i++) cin >> x[i] >> y[i];
    int gap = n - m - 1;
    Treap.init();
    for (int i = (1); i <= (m); i++)
      if (!Treap.insert(y[i])) gap++;
    cout << C(n + gap, gap) << endl;
  }
  return 0;
}
