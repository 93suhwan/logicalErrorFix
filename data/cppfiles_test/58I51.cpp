#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
const long long BIG_INF = 1e18;
const int mod = 998244353;
const int INF = mod;
const int N = 1e6 + 7;
const int T = 1 << 20;
template <class T, class G>
ostream &operator<<(ostream &os, const pair<T, G> &para) {
  os << para.first << ' ' << para.second;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (const T &el : vec) os << el << ' ';
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &el : vec) is >> el;
  return is;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long sil[N];
long long odw[N];
long long fast(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % INF;
    a = a * a % INF;
    b /= 2;
  }
  return ret;
}
long long npok(long long a, long long b) {
  if (b > a or b < 0) return 0;
  return sil[a] * odw[b] % INF * odw[a - b] % INF;
}
void prep() {
  sil[0] = 1;
  for (int i = 1; i < N; i++) sil[i] = sil[i - 1] * i % INF;
  odw[N - 1] = fast(sil[N - 1], INF - 2);
  for (int i = N - 2; i >= 0; i--) odw[i] = odw[i + 1] * (i + 1) % INF;
}
struct Treap {
  int val, prior, roz, suma;
  Treap *L, *P;
  Treap(int _v = 0)
      : val(_v), prior(rand()), roz(1), suma(_v), L(nullptr), P(nullptr) {}
  ~Treap() {
    if (L) L->~Treap();
    if (P) P->~Treap();
    delete this;
  }
};
int get_roz(Treap *t) { return t == 0 ? 0 : t->roz; }
int get_sum(Treap *t) { return t == 0 ? 0 : t->suma; }
void update(Treap *t) {
  t->roz = 1 + get_roz(t->L) + get_roz(t->P);
  t->suma = t->val + get_sum(t->L) + get_sum(t->P);
}
Treap *merge(Treap *l, Treap *p) {
  if (l == nullptr) return p;
  if (p == nullptr) return l;
  if (l->prior > p->prior) {
    l->P = merge(l->P, p);
    update(l);
    return l;
  } else {
    p->L = merge(l, p->L);
    update(p);
    return p;
  }
}
pair<Treap *, Treap *> split(Treap *t, int ile) {
  assert(get_roz(t) >= ile);
  if (t == nullptr) return {nullptr, nullptr};
  if (get_roz(t->L) >= ile) {
    pair<Treap *, Treap *> pom = split(t->L, ile);
    t->L = pom.second;
    update(t);
    return {pom.first, t};
  } else {
    pair<Treap *, Treap *> pom = split(t->P, ile - get_roz(t->L) - 1);
    t->P = pom.first;
    update(t);
    return {t, pom.second};
  }
}
Treap *insert(Treap *t, int val, int poz) {
  pair<Treap *, Treap *> pom = split(t, poz);
  return merge(merge(pom.first, new Treap(val)), pom.second);
}
Treap *erase(Treap *t, int poz) {
  assert(poz >= 1 and poz <= get_roz(t));
  pair<Treap *, Treap *> p1 = split(t, poz);
  pair<Treap *, Treap *> p2 = split(p1.first, poz - 1);
  delete p2.second;
  return merge(p2.first, p1.second);
}
int find_poz(Treap *t, int suma) {
  assert(t);
  if (get_sum(t->L) >= suma)
    return find_poz(t->L, suma);
  else if (get_sum(t->L) + (t->val) >= suma)
    return get_roz(t->L) + 1;
  else
    return get_roz(t->L) + 1 +
           find_poz(t->P, suma - (get_sum(t->L) + (t->val)));
}
void solve() {
  int n, m;
  cin >> n >> m;
  Treap *root = insert(nullptr, 0, 0);
  int ile_przegrodek = n - 1;
  int last = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int diff = a - last;
    if (diff) {
      auto pom = split(root, 1);
      Treap *nowaa = insert(nullptr, pom.first->val + diff, 0);
      root = merge(nowaa, pom.second);
    }
    last = a + 1;
    int poz = find_poz(root, a - b);
    auto pom = split(root, poz);
    if (get_sum(pom.first) == a - b) {
      if (get_sum(pom.second) == 0) {
        ile_przegrodek--;
        root = merge(root, insert(nullptr, 1, 0));
        continue;
      }
      auto dwa = split(pom.second, 1);
      Treap *nowa = insert(nullptr, dwa.first->val + 1, 0);
      root = merge(pom.first, merge(nowa, dwa.second));
    } else {
      ile_przegrodek--;
      int siema = get_roz(pom.first);
      int siema_val = get_sum(pom.first);
      auto dwa = split(pom.first, siema - 1);
      int pom_roz = (a - b) - get_roz(dwa.first);
      Treap *nowa1 = insert(nullptr, pom_roz, 0);
      Treap *nowa2 = insert(nullptr, siema_val - pom_roz + 1, 0);
      root = merge(merge(dwa.first, merge(nowa1, nowa2)), pom.second);
    }
  }
  cout << npok(n + ile_przegrodek, ile_przegrodek) << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  prep();
  int test = 1;
  cin >> test;
  for (int i = 0; i < test; i++) solve();
}
