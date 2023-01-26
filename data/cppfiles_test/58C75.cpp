#include <bits/stdc++.h>
using namespace std;
const bool debug = 0;
const int inf = 1e9;
mt19937 rng(199999999973);
struct treap {
  pair<int, int> line;
  int pr;
  int sz;
  treap *l, *r;
  treap(pair<int, int> _line = {-1, -1}) {
    pr = rng();
    line = _line;
    sz = line.second - line.first + 1;
    l = r = nullptr;
  }
};
vector<pair<int, int> > travel;
void dfs(treap* root) {
  if (root == nullptr) return;
  dfs(root->l), travel.push_back(root->line), dfs(root->r);
}
typedef pair<treap*, treap*> pT;
treap* root = nullptr;
int getsz(treap* v) { return (v ? v->sz : 0); }
void upd(treap* v) {
  if (v) v->sz = v->line.second - v->line.first + 1 + getsz(v->l) + getsz(v->r);
}
treap* merge(treap* l, treap* r) {
  if (l == nullptr) return r;
  if (r == nullptr) return l;
  if (l->pr > r->pr) {
    l->r = merge(l->r, r);
    upd(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    upd(r);
    return r;
  }
}
pT split(treap* t, int sz) {
  if (t == nullptr) return {nullptr, nullptr};
  if (getsz(t->l) >= sz) {
    pT left = split(t->l, sz);
    t->l = left.second;
    upd(t);
    return {left.first, t};
  } else {
    if (getsz(t) - getsz(t->r) > sz) {
      treap* v = t->l;
      t->l = nullptr;
      upd(t);
      return {v, t};
    }
    pT right = split(t->r, sz - (getsz(t) - getsz(t->r)));
    t->r = right.first;
    upd(t);
    return {t, right.second};
  }
}
treap* add(treap* x, int pos, pair<int, int> line) {
  pT fir = split(x, pos);
  treap* v = new treap(line);
  int ps = getsz(fir.first);
  assert(ps <= pos);
  if (ps < pos) {
    treap* z = fir.second;
    treap* pr = nullptr;
    while (z->l) {
      pr = z, z = z->l;
    }
    if (pr) pr->l = nullptr;
    pair<int, int> kk = z->line;
    pair<int, int> KK;
    if (kk.second - kk.first + 1 <= pos - ps) assert(false);
    KK.first = kk.first, KK.second = kk.first + (pos - ps) - 1;
    kk.first = KK.second + 1;
    assert(kk.first <= kk.second);
    treap* v1 = new treap(KK);
    if (pr) {
      z->line = kk;
      upd(z);
      root = merge(fir.first, v1);
      root = merge(root, v);
      root = merge(root, z);
      root = merge(root, fir.second);
    } else {
      z->line = kk;
      upd(z);
      root = merge(fir.first, v1);
      root = merge(root, v);
      root = merge(root, fir.second);
    }
  } else {
    root = merge(merge(fir.first, v), fir.second);
  }
  return root;
}
struct comb {
  static const int COMBN = 4e5 + 10;
  static const int mod = 998244353;
  int fact[COMBN], inv[COMBN];
  int binpow(int a, int b) {
    if (b == 0) return 1;
    int ans = binpow(a, b >> 1);
    ans = (1ll * ans * ans) % mod;
    if (b & 1) ans = (1ll * ans * a) % mod;
    return ans;
  }
  void init() {
    fact[0] = 1;
    for (int i = 1; i < COMBN; ++i) fact[i] = (1ll * fact[i - 1] * i) % mod;
    inv[COMBN - 1] = binpow(fact[COMBN - 1], mod - 2);
    for (int i = COMBN - 2; i >= 0; --i) {
      inv[i] = (1ll * inv[i + 1] * (i + 1)) % mod;
    }
  }
  int Cnk(int n, int k) {
    return (1ll * fact[n] * inv[k] % mod * inv[n - k] % mod);
  }
} COMB;
void solve(int n, int m, vector<pair<int, int> > lol) {
  root = new treap({1, 1});
  int lst = 1;
  for (int f = 0; f < (int)(lol).size(); ++f) {
    if (lol[f].first - 1 > lst) {
      root = add(root, lst, make_pair(lst + 1, lol[f].first - 1));
    }
    root = add(root, lol[f].second - 1, {lol[f].first, lol[f].first});
    lst = lol[f].first;
  }
  if (lst < n) root = add(root, lst, make_pair(lst + 1, n));
  travel.clear();
  dfs(root);
  int cnt = n - 1;
  for (int f = 1; f < (int)(travel).size(); ++f) {
    if (travel[f - 1].second > travel[f].first) cnt--;
  }
  cout << COMB.Cnk(n + cnt, cnt) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  COMB.init();
  while (t--) {
    vector<pair<int, int> > lol;
    int n, m;
    if (!debug) {
      cin >> n >> m;
      for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        lol.push_back({x, y});
      }
    } else {
      n = 10, m = rng() % 10;
      vector<int> perm(n);
      iota((perm).begin(), (perm).end(), 1);
      shuffle((perm).begin(), (perm).end(), rng);
      for (int f = 0; f < m; ++f) {
        if (perm[f] != 1) lol.push_back({perm[f], rng() % (perm[f] - 1) + 1});
      }
      sort((lol).begin(), (lol).end());
      m = (int)(lol).size();
      cout << "YO\n";
      cout << n << ' ' << m << endl;
      for (auto u : lol) cout << u.first << ' ' << u.second << endl;
      cout << endl;
    }
    solve(n, m, lol);
  }
  return 0;
}
