#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
class LinkCutTree {
 private:
  struct Vertex {
    long long left, right, parent;
    bool revert;
    long long size;
    int64_t value, result, delta;
    Vertex()
        : left(-1),
          right(-1),
          parent(-1),
          revert(),
          size(1),
          value(),
          result(),
          delta() {}
  };
  vector<Vertex> t;
  bool isRoot(long long first) const {
    long long p = t[first].parent;
    return p == -1 || (t[p].left != first && t[p].right != first);
  }
  int64_t getValue(long long first) const {
    if (t[first].delta < 0) {
      return 0;
    }
    return max(t[first].delta, t[first].value);
  }
  int64_t getResult(long long first) const {
    if (t[first].delta < 0) {
      return 0;
    }
    return max(t[first].delta, t[first].result);
  }
  void push(long long first) {
    if (t[first].revert) {
      if (t[first].left != -1)
        t[t[first].left].revert = !t[t[first].left].revert;
      if (t[first].right != -1)
        t[t[first].right].revert = !t[t[first].right].revert;
      swap(t[first].left, t[first].right);
      t[first].revert = false;
    }
    t[first].value = getValue(first);
    t[first].result = getResult(first);
    if (t[first].left != -1 && t[first].delta != 0)
      t[t[first].left].delta = t[first].delta;
    if (t[first].right != -1 && t[first].delta != 0)
      t[t[first].right].delta = t[first].delta;
    t[first].delta = 0;
  }
  void keep(long long first) {
    t[first].size = 1;
    t[first].result = getValue(first);
    if (t[first].left != -1) {
      t[first].size += t[t[first].left].size;
      t[first].result = max(t[first].result, getResult(t[first].left));
    }
    if (t[first].right != -1) {
      t[first].size += t[t[first].right].size;
      t[first].result = max(t[first].result, getResult(t[first].right));
    }
  }
  void rotate(long long first) {
    long long p = t[first].parent;
    long long g = t[p].parent;
    push(p), push(first);
    if (g != -1) {
      if (t[g].left == p)
        t[g].left = first;
      else if (t[g].right == p)
        t[g].right = first;
    }
    t[first].parent = g;
    if (t[p].left == first) {
      t[p].left = t[first].right;
      if (t[p].left != -1) t[t[p].left].parent = p;
      t[first].right = p;
    } else {
      t[p].right = t[first].left;
      if (t[p].right != -1) t[t[p].right].parent = p;
      t[first].left = p;
    }
    t[p].parent = first;
    keep(p), keep(first);
  }
  void splay(long long first) {
    while (!isRoot(first)) {
      long long p = t[first].parent;
      if (!isRoot(p)) {
        long long g = t[p].parent;
        bool zigzig = (first == t[p].left) == (p == t[g].left);
        rotate(zigzig ? p : first);
      }
      rotate(first);
    }
    push(first);
  }
  long long expose(long long first) {
    long long c = -1;
    for (long long second = first; second != -1; second = t[second].parent) {
      splay(second);
      t[second].right = c;
      keep(second);
      c = second;
    }
    splay(first);
    return c;
  }

 public:
  LinkCutTree(long long n) : t(n) {}
  void evert(long long first) {
    expose(first);
    t[first].revert = !t[first].revert;
  }
  long long root(long long first) {
    expose(first);
    while (t[first].left != -1) {
      first = t[first].left;
      push(first);
    }
    expose(first);
    return first;
  }
  long long parent(long long first) {
    expose(first);
    if (t[first].left == -1) return -1;
    first = t[first].left;
    push(first);
    while (t[first].right != -1) {
      first = t[first].right;
      push(first);
    }
    return first;
  }
  bool path(long long first, long long second) {
    if (first == second) return true;
    expose(first), expose(second);
    return t[first].parent != -1;
  }
  void link(long long first, long long second) {
    if (path(first, second)) return;
    evert(first);
    t[first].parent = second;
  }
  void cut(long long first) {
    expose(first);
    if (t[first].left == -1) return;
    t[t[first].left].parent = -1;
    t[first].left = -1;
  }
  long long lca(long long first, long long second) {
    if (!path(first, second)) return -1;
    expose(second);
    return expose(first);
  }
  long long depth(long long first) {
    expose(first);
    if (t[first].left == -1) return 0;
    return t[t[first].left].size;
  }
  long long distance(long long first, long long second) {
    long long l = lca(first, second);
    if (l == -1) return -1;
    return depth(first) + depth(second) - depth(l) * 2;
  }
  int64_t query(long long first, long long second) {
    if (!path(first, second)) return 0;
    evert(second), expose(first);
    return t[first].result;
  }
  void update(long long first, long long second, int64_t value) {
    if (!path(first, second)) return;
    evert(second), expose(first);
    t[first].delta = value;
  }
};
pair<long long, long long> exclude_bounds(long long first, long long second,
                                          vector<set<long long>>& g,
                                          LinkCutTree& lct) {
  long long exp_dist = lct.distance(first, second);
  assert(exp_dist != -1);
  long long from = -1, to = -1;
  for (long long cand : g[first]) {
    if (lct.distance(cand, second) == exp_dist - 1) {
      from = cand;
      break;
    }
  }
  for (long long cand : g[second]) {
    if (lct.distance(cand, first) == exp_dist - 1) {
      to = cand;
      break;
    }
  }
  assert(from != -1 && to != -1);
  return {from, to};
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> a(m);
  for (auto& e : a) {
    cin >> e.first >> e.second;
    --e.first;
    --e.second;
  }
  LinkCutTree lct(n + m);
  long long free = n;
  ll ans = 0;
  vector<bool> intree(m);
  vector<long long> mid(m, -1);
  vector<set<long long>> g(n);
  for (long long i = m - 1, j = m - 1; i >= 0; i--) {
    mid[i] = free++;
    while (lct.path(a[i].first, a[i].second)) {
      pair<long long, long long> seg =
          exclude_bounds(a[i].first, a[i].second, g, lct);
      long long prokek = lct.query(seg.first, seg.second) - 1;
      if (prokek < 0) {
        break;
      }
      pair<long long, long long> podkek =
          exclude_bounds(a[j].first, a[j].second, g, lct);
      if (intree[j]) {
        long long other = lct.query(podkek.first, podkek.second) - 1;
        if (other > -1) {
          pair<long long, long long> nadkek =
              exclude_bounds(a[other].first, a[other].second, g, lct);
          lct.update(nadkek.first, nadkek.second, -1);
        }
        lct.evert(mid[j]);
        lct.cut(a[j].second);
        lct.cut(a[j].first);
        intree[j] = false;
        g[a[j].first].erase(mid[j]);
        g[a[j].second].erase(mid[j]);
        if (other > -1) {
          assert(other < j);
          lct.link(mid[other], a[other].first);
          lct.link(mid[other], a[other].second);
          intree[other] = true;
          g[a[other].first].insert(mid[other]);
          g[a[other].second].insert(mid[other]);
        }
      } else {
        lct.update(podkek.first, podkek.second, -1);
      }
      j--;
    }
    if (!lct.path(a[i].first, a[i].second)) {
      lct.link(mid[i], a[i].first);
      lct.link(mid[i], a[i].second);
      intree[i] = true;
      g[a[i].first].insert(mid[i]);
      g[a[i].second].insert(mid[i]);
    } else {
      pair<long long, long long> seg =
          exclude_bounds(a[i].first, a[i].second, g, lct);
      lct.update(seg.first, seg.second, i + 1);
    }
    ans += (j - i + 1);
  }
  cout << ans << endl;
  cout.flush();
  return 0;
}
