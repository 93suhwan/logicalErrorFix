#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
struct Edge {
  int x, y, z;
  bool operator<(const Edge &b) const {
    if (z != b.z) return z < b.z;
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
};
struct Treap {
  vector<int> l, r, siz, rnd;
  vector<Edge> key;
  int root;
  Treap() {
    l.push_back(0);
    r.push_back(0);
    siz.push_back(0);
    key.push_back((Edge){0, 0, 0});
    rnd.push_back(0);
    root = 0;
  }
  int my_rand() {
    static int seed = 233333333;
    return seed = seed * 48271ll % 2147483647;
  }
  int newnode(Edge val) {
    int x = l.size();
    l.push_back(0);
    r.push_back(0);
    siz.push_back(1);
    key.push_back(val);
    rnd.push_back(my_rand());
    return x;
  }
  void pushup(int x) { siz[x] = siz[l[x]] + siz[r[x]] + 1; }
  void split(int x, int &a, int &b, Edge k) {
    if (x == 0) {
      a = b = 0;
      return;
    }
    if (!(k < key[x]))
      a = x, split(r[x], r[a], b, k);
    else
      b = x, split(l[x], a, l[b], k);
    pushup(x);
  }
  void ksplit(int x, int &a, int &b, int k) {
    if (x == 0) {
      a = b = 0;
      return;
    }
    if (siz[l[x]] < k)
      a = x, ksplit(r[x], r[a], b, k - siz[l[x]] - 1);
    else
      b = x, ksplit(l[x], a, l[b], k);
    pushup(x);
  }
  int merge(int a, int b) {
    if (a == 0 || b == 0) return a | b;
    if (rnd[a] < rnd[b]) {
      r[a] = merge(r[a], b);
      pushup(a);
      return a;
    } else {
      l[b] = merge(a, l[b]);
      pushup(b);
      return b;
    }
  }
  void insert(Edge x) {
    int a, b;
    split(root, a, b, x);
    root = merge(merge(a, newnode(x)), b);
  }
  void del(Edge x) {
    int a, b, c;
    split(root, a, b, (Edge){x.x, x.y - 1, x.z});
    split(b, b, c, x);
    b = merge(l[b], r[b]);
    root = merge(merge(a, b), c);
  }
  int rank(Edge x) {
    int a, b;
    split(root, a, b, (Edge){x.x, x.y - 1, x.z});
    int ans = siz[a];
    root = merge(a, b);
    return ans;
  }
  Edge kth(int x) {
    int a, b;
    if (x <= 0 || x > siz[root]) assert(false);
    ksplit(root, a, b, x);
    int ans = a;
    while (r[ans]) ans = r[ans];
    root = merge(a, b);
    return key[ans];
  }
  int size() { return siz[root]; }
} t[N];
int n, m, q;
bool check(int x, int y, int z) {
  Edge e = {(int)1e9, (int)1e9, z};
  int a = t[0].rank(e), b = t[x].rank(e), c = t[y].rank(e);
  return b + c - 1 == a;
}
long long query() {
  long long ans = 1ll << 60;
  Edge e = t[0].kth(1);
  int l = e.z, r = 1e9 + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(e.x, e.y, mid))
      l = mid + 1;
    else
      r = mid;
  }
  ans = min(ans, 0ll + l + e.z);
  if (t[e.x].size() >= 2 && t[e.y].size() >= 2) {
    Edge e1 = t[e.x].kth(2), e2 = t[e.y].kth(2);
    if (e1.x != e.x && e1.x != e.y) swap(e1.x, e1.y);
    if (e2.x != e.x && e2.x != e.y) swap(e2.x, e2.y);
    if (e1.y != e2.y)
      ans = min(ans, 0ll + e1.z + e2.z);
    else {
      if (t[e.x].size() >= 3) ans = min(ans, 0ll + t[e.x].kth(3).z + e2.z);
      if (t[e.y].size() >= 3) ans = min(ans, 0ll + t[e.y].kth(3).z + e1.z);
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  map<pair<int, int>, int> mp;
  for (int i = 1, x, y, z; i <= m; ++i) {
    cin >> x >> y >> z;
    if (x > y) swap(x, y);
    Edge e = (Edge){x, y, z};
    mp[make_pair(x, y)] = z;
    t[0].insert(e);
    t[x].insert(e);
    t[y].insert(e);
  }
  multiset<int> s;
  for (int i = 1; i <= n; ++i)
    if (t[i].size() >= 3) {
      s.insert(t[i].kth(1).z + t[i].kth(2).z + t[i].kth(3).z);
    }
  cin >> q;
  printf("%lld\n", min(1ll * *s.begin(), query()));
  while (q--) {
    int opt, x, y, z;
    cin >> opt >> x >> y;
    if (opt == 0) {
      if (x > y) swap(x, y);
      z = mp[make_pair(x, y)];
      Edge e = (Edge){x, y, z};
      if (t[x].size() >= 3) {
        auto it = s.find(t[x].kth(1).z + t[x].kth(2).z + t[x].kth(3).z);
        s.erase(it);
      }
      if (t[y].size() >= 3) {
        auto it = s.find(t[y].kth(1).z + t[y].kth(2).z + t[y].kth(3).z);
        s.erase(it);
      }
      t[0].del(e);
      t[x].del(e);
      t[y].del(e);
      if (t[x].size() >= 3)
        s.insert(t[x].kth(1).z + t[x].kth(2).z + t[x].kth(3).z);
      if (t[y].size() >= 3)
        s.insert(t[y].kth(1).z + t[y].kth(2).z + t[y].kth(3).z);
    } else {
      cin >> z;
      if (x > y) swap(x, y);
      Edge e = (Edge){x, y, z};
      mp[make_pair(x, y)] = z;
      if (t[x].size() >= 3) {
        auto it = s.find(t[x].kth(1).z + t[x].kth(2).z + t[x].kth(3).z);
        s.erase(it);
      }
      if (t[y].size() >= 3) {
        auto it = s.find(t[y].kth(1).z + t[y].kth(2).z + t[y].kth(3).z);
        s.erase(it);
      }
      t[0].insert(e);
      t[x].insert(e);
      t[y].insert(e);
      if (t[x].size() >= 3)
        s.insert(t[x].kth(1).z + t[x].kth(2).z + t[x].kth(3).z);
      if (t[y].size() >= 3)
        s.insert(t[y].kth(1).z + t[y].kth(2).z + t[y].kth(3).z);
    }
    printf("%lld\n", min(1ll * *s.begin(), query()));
  }
  return 0;
}
