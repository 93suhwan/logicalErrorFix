#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define CHECK(...)
#endif

namespace {

template<typename Node, typename Impl>
class SegmentTreeBase {
 public:
  explicit SegmentTreeBase(int n) : n(n), tree(n << 1) {}
  virtual ~SegmentTreeBase() = default;

  template<typename Handler>
  Handler traverse_all(Handler&& handler) {
    traverse_all(std::forward<Handler>(handler), 0, n - 1);
    return handler;
  }

  template<typename Handler>
  Handler traverse(Handler&& handler, int L, int R) {
    traverse(std::forward<Handler>(handler), L, R, 0, n - 1);
    return handler;
  }

  int size() const { return n; }

 protected:
  static int get_id(int l, int r) {
    return l + r | (l != r);
  }

  Node& get_node(int l, int r) { return tree[get_id(l, r)]; }

  // Handler() :: void operator () (int l, int r, Node& u).
  // Impl::down :: void down(int l, int mid, int r, Node& u, Node& lu, Node& ru).
  // Impl::up :: void up(int l, int mid, int r, Node& u, const Node& lu, const Node& ru).

 private:
  template<typename Handler>
  void traverse_all(Handler&& handler, int l, int r) {
    if (l == r) {
      handler(l, r, get_node(l, r));
      return;
    }
    int mid = (l + r) >> 1;
    Impl::down(l, mid, r, get_node(l, r), get_node(l, mid), get_node(mid + 1, r));
    traverse_all(std::forward<Handler>(handler), l, mid);
    traverse_all(std::forward<Handler>(handler), mid + 1, r);
    Impl::up(l, mid, r, get_node(l, r), get_node(l, mid), get_node(mid + 1, r));
  }

  template<typename Handler>
  void traverse(Handler&& handler, int L, int R, int l, int r) {
    if (R < l || r < L || L > R) return;
    if (L <= l && r <= R) {
      handler(l, r, get_node(l, r));
      return;
    }
    int mid = (l + r) >> 1;
    Impl::down(l, mid, r, get_node(l, r), get_node(l, mid), get_node(mid + 1, r));
    traverse(std::forward<Handler>(handler), L, R, l, mid);
    traverse(std::forward<Handler>(handler), L, R, mid + 1, r);
    Impl::up(l, mid, r, get_node(l, r), get_node(l, mid), get_node(mid + 1, r));
  }

  int n;
  std::vector<Node> tree;
};

const int INF = 0x3f3f3f3f;

struct Monoid {
  bool id() const { return vmax < 0; }

  int vmax = -1;
};

Monoid operator*(const Monoid& lhs, const Monoid& rhs) {
  return Monoid{.vmax = std::max(lhs.vmax, rhs.vmax)};
}

struct Node {
  Monoid m;
};

struct SegmentTree : public SegmentTreeBase<Node, SegmentTree> {
  explicit SegmentTree(int n) : SegmentTreeBase(n) {}
  virtual ~SegmentTree() = default;

  static void down(int l, int mid, int r, Node& u, Node& lu, Node& ru) {
    // pass
  }

  static void up(int l, int mid, int r, Node& u, const Node& lu, const Node& ru) {
    u.m = lu.m * ru.m;
  }

  void build() {
    traverse_all([&](int l, int r, Node& u) {
      assert(l == r);
    });
  }

  void update(int p, int val) {
    traverse([&](int l, int r, Node& u) {
      u.m.vmax = std::max(val, u.m.vmax);
    }, p, p);
  }

  Monoid query(int L, int R) {
    Monoid ret{};
    traverse([&](int l, int r, Node& u) {
      ret = ret * u.m;
    }, L, R);
    return ret;
  }
};

struct Solver {

  struct Alpinist {
    int a, s;
  };

  void solve(int ca, std::istream& reader) {
    int n, d;
    reader >> n >> d;
    std::vector<Alpinist> alpinists;  // <a, s>
    std::vector<int> ss{d};
    int init_value = 0;
    for (int i = 0; i < n; ++i) {
      int s, a;
      reader >> s >> a;
      if (a <= d) {
        init_value += s >= d;
      } else {
        alpinists.emplace_back(Alpinist{.a = a, .s = s});
        ss.emplace_back(a);
        ss.emplace_back(s);
      }
    }
    n = alpinists.size();
    std::sort(ss.begin(), ss.end());
    ss.erase(std::unique(ss.begin(), ss.end()), ss.end());
    auto get = [&](int x) { return std::lower_bound(ss.begin(), ss.end(), x) - ss.begin(); };
    std::sort(alpinists.begin(), alpinists.end(), [](const Alpinist& lhs, const Alpinist& rhs) {
      if (lhs.a <= rhs.s && rhs.a <= lhs.s) {
        return lhs.a < rhs.a;
      }
      if (lhs.a == rhs.a && lhs.s == rhs.s) {
        return false;
      }
      if (lhs.a <= rhs.s) {
        return true;
      }
      return false;
    });
    SegmentTree sgt(ss.size());
    sgt.update(get(d), init_value);
    int result = init_value;
    for (const Alpinist& al : alpinists) {
      int w = sgt.query(0, get(al.s)).vmax;
      if (w >= 0) {
        result = std::max(result, w + 1);
        sgt.update(get(al.a), w + 1);
      }
    }
    printf("%d\n", result);
  }
};

}  // namespace

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

