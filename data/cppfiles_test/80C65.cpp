#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
Vi compressVec(vector<int*>& vec) {
  sort((vec).begin(), (vec).end(), [](int* l, int* r) { return *l < *r; });
  Vi old;
  for (auto& e : (vec)) {
    if (old.empty() || old.back() != *e) old.push_back(*e);
    *e = int((old).size()) - 1;
  }
  return old;
}
ll countInversions(Vi perm) {
  ll ret = 0, cont = 1;
  Vi odd;
  while (cont) {
    odd.assign(int((perm).size()) + 1, 0);
    cont = 0;
    for (int i = (0); i < (int((perm).size())); i++) {
      if (perm[i] % 2)
        odd[perm[i]]++;
      else
        ret += odd[perm[i] + 1];
      cont += perm[i] /= 2;
    }
  }
  return ret;
}
ll cntInvA(vector<int> A) {
  vector<int*> aRef(int((A).size()));
  for (int i = 0; i < int((A).size()); i++) {
    aRef[i] = &A[i];
  }
  compressVec(aRef);
  return countInversions(A);
}
const int inf = 1e9;
struct Tree {
  int base = 1;
  vector<int> lazy, mini;
  int len = 0;
  Tree(int n) {
    while (base < n + 3) base *= 2;
    mini.resize(2 * base);
    lazy.resize(2 * base);
  }
  void apply(int a, int c) {
    mini[a] += c;
    lazy[a] += c;
  }
  void update(int a) { mini[a] = min(mini[2 * a], mini[2 * a + 1]); }
  void push(int a) {
    apply(2 * a, lazy[a]);
    apply(2 * a + 1, lazy[a]);
    lazy[a] = 0;
  }
  void modify(int a, int nl, int nr, int ql, int qr, int c) {
    if (nr < ql || qr < nl) return;
    if (ql <= nl && nr <= qr) {
      apply(a, c);
      return;
    }
    push(a);
    int mid = (nl + nr) / 2;
    modify(2 * a, nl, mid, ql, qr, c);
    modify(2 * a + 1, mid + 1, nr, ql, qr, c);
    update(a);
  }
  void plusSeg(int ql, int qr, int c) { modify(1, 0, base - 1, ql, qr, c); }
  int queryMin(int a, int nl, int nr, int ql, int qr) {
    if (nr < ql || qr < nl) return inf;
    if (ql <= nl && nr <= qr) {
      return mini[a];
    }
    push(a);
    int mid = (nl + nr) / 2;
    return min(queryMin(2 * a, nl, mid, ql, qr),
               queryMin(2 * a + 1, mid + 1, nr, ql, qr));
  }
  int query(int ql, int qr) { return queryMin(1, 0, base - 1, ql, qr); }
};
struct Event {
  int val, type, pos;
  bool operator<(const Event& e) const {
    return Pii(val, type) < Pii(e.val, e.type);
  }
};
void run() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  for (auto& first : (A)) cin >> first;
  for (auto& first : (B)) cin >> first;
  sort((B).begin(), (B).end());
  ll resA = cntInvA(A);
  Tree tree(n + 1);
  for (int i = 0; i < n; i++) {
    tree.plusSeg(i + 1, n, 1);
  }
  vector<Event> events;
  for (int i = 0; i < n; i++) {
    events.push_back({A[i], -1, i + 1});
    events.push_back({A[i], 1, i + 1});
  }
  for (int i = 0; i < m; i++) {
    events.push_back({B[i], 0, -1});
  }
  sort((events).begin(), (events).end());
  ll resB = 0;
  for (Event e : events) {
    if (e.type == -1) {
      tree.plusSeg(e.pos, n, -1);
    } else if (e.type == 0) {
      resB += tree.query(0, n);
    } else if (e.type == 1) {
      tree.plusSeg(0, e.pos - 1, 1);
    }
  }
  cout << resA + resB << "\n";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(18);
  int t = 1;
  cin >> t;
  for (int i = (0); i < (t); i++) {
    run();
  }
  return 0;
}
