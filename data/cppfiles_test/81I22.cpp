#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
  Fun fun_;
  public:
  template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
  template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


struct segment_change {
  // Use a sentinel value rather than a boolean to save significant memory (4-8 bytes per object).
  static const int SENTINEL = numeric_limits<int>::lowest();

  // Note that to_set goes first, and to_add goes after.
  int to_set, to_add;

  segment_change(int _to_add = 0, int _to_set = SENTINEL) : to_set(_to_set), to_add(_to_add) {}

  bool has_set() const {
    return to_set != SENTINEL;
  }

  bool has_change() const {
    return has_set() || to_add != 0;
  }

  // Return the combined result of applying this segment_change followed by `other`.
  segment_change combine(const segment_change &other) const {
    if (other.has_set())
      return other;

    return segment_change(to_add + other.to_add, to_set);
  }
};

struct segment {
  int maximum;
  int64_t sum;
  int first, last, max_diff;

  segment(int _maximum = numeric_limits<int>::lowest(), int64_t _sum = 0, int _first = 0, int _last = 0,
      int _max_diff = -1) : maximum(_maximum), sum(_sum), first(_first), last(_last), max_diff(_max_diff) {}

  bool empty() const {
    return max_diff < 0;
  }

  void apply(int length, const segment_change &change) {
    if (change.has_set()) {
      maximum = change.to_set;
      sum = int64_t(length) * change.to_set;
      first = last = change.to_set;
      max_diff = 0;
    }

    maximum += change.to_add;
    sum += int64_t(length) * change.to_add;
    first += change.to_add;
    last += change.to_add;
  }

  void join(const segment &other) {
    if (empty()) {
      *this = other;
      return;
    } else if (other.empty()) {
      return;
    }

    maximum = max(maximum, other.maximum);
    sum += other.sum;
    max_diff = max({max_diff, other.max_diff, abs(last - other.first)});
    last = other.last;
  }

  void join(const segment &a, const segment &b) {
    *this = a;
    join(b);
  }
};

struct seg_tree {
  static int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
  }

  int tree_n = 0;
  vector<segment> tree;
  vector<segment_change> changes;

  seg_tree(int n = -1) {
    if (n >= 0)
      init(n);
  }

  void init(int n) {
    tree_n = 1;

    while (tree_n < n)
      tree_n *= 2;

    tree.assign(2 * tree_n, segment());
    changes.assign(tree_n, segment_change());
  }

  // Builds our tree from an array in O(n).
  void build(const vector<segment> &initial) {
    int n = int(initial.size());
    init(n);
    assert(n <= tree_n);

    for (int i = 0; i < n; i++)
      tree[tree_n + i] = initial[i];

    for (int position = tree_n - 1; position > 0; position--)
      tree[position].join(tree[2 * position], tree[2 * position + 1]);
  }

  void apply_and_combine(int position, int length, const segment_change &change) {
    tree[position].apply(length, change);

    if (position < tree_n)
      changes[position] = changes[position].combine(change);
  }

  void push_down(int position, int length) {
    if (changes[position].has_change()) {
      apply_and_combine(2 * position, length / 2, changes[position]);
      apply_and_combine(2 * position + 1, length / 2, changes[position]);
      changes[position] = segment_change();
    }
  }

  template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
      if (a <= start && end <= b) {
        range_op(position, end - start);
        return;
      }

      if (position >= tree_n)
        return;

      push_down(position, end - start);
      int mid = (start + end) / 2;
      if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
      if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
      if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

  segment query(int a, int b) {
    assert(0 <= a && a <= b && b <= tree_n);
    segment answer;

    process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
        answer.join(tree[position]);
        });

    return answer;
  }

  segment query_full() const {
    return tree[1];
  }

  void update(int a, int b, const segment_change &change) {
    assert(0 <= a && a <= b && b <= tree_n);

    process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
        apply_and_combine(position, length, change);
        });
  }

  vector<segment> to_array() {
    for (int i = 1; i < tree_n; i++)
      push_down(i, tree_n >> highest_bit(i));

    vector<segment> segs(tree_n);

    for (int i = 0; i < tree_n; i++)
      segs[i] = tree[tree_n + i];

    return segs;
  }

  void update_single(int index, const segment &seg) {
    assert(0 <= index && index < tree_n);
    int position = tree_n + index;

    for (int up = highest_bit(tree_n); up > 0; up--)
      push_down(position >> up, 1 << up);

    tree[position] = seg;

    while (position > 1) {
      position /= 2;
      tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }
  }

  // Finds the last subarray starting at `first` that satisifes `should_join` via binary search in O(log n).
  template<typename T_bool>
    int find_last_subarray(T_bool &&should_join, int n, int first = 0) {
      assert(0 <= first && first <= n);
      segment current;

      // Check the degenerate case.
      if (!should_join(current, current))
        return first - 1;

      return y_combinator([&](auto search, int position, int start, int end) -> int {
          if (end <= first) {
          return end;
          } else if (first <= start && end <= n && should_join(current, tree[position])) {
          current.join(tree[position]);
          return end;
          } else if (end - start == 1) {
          return start;
          }

          push_down(position, end - start);
          int mid = (start + end) / 2;
          int left = search(2 * position, start, mid);
          return left < mid ? left : search(2 * position + 1, mid, end);
          })(1, 0, tree_n);
    }
};

struct Tree {
  typedef int T;
  static constexpr T unit = 0; // f(unit, b) must equal b
  T f(T a, T b) { return a + b; } // (any associative fn)
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, d;
  cin >> n >> d;

  vii a;
  rep(i,0,n) {
    int s, p;
    cin >> s >> p;
    if (s < d) continue;
    a.eb(s, p);
  }

  auto type = [&](pii x) { // 1 if skill >= neat, 0 otherwise
    return x.fst >= x.snd;
  };

  sort(all(a), [&](pii x, pii y) {
      if (x.snd == y.snd) return type(x) < type(y);
      return x.snd < y.snd;
      });

  // compress things
  vi vals;
  for (auto &[x, y]: a) {
    vals.pb(x);
    vals.pb(y);
  }

  sort(all(vals));
  vals.resize(unique(all(vals)) - vals.begin());

  int m = sz(vals);

  // sort each p correctly
  vvi ps(m);

  for (auto &[x, y]: a) {
    x = lower_bound(all(vals), x) - vals.begin();
    y = lower_bound(all(vals), y) - vals.begin();
    ps[y].pb(x);
  }

  rep(i,0,m) sort(all(ps[i]));

  seg_tree dp(m);
  dp.build(vector<segment>(m, segment(0, 0, 0, 0, 0)));
  Tree ex(m);

  rep(i,0,m) {
    for (auto s: ps[i]) {
      int res = dp.query(0, s + 1).maximum;
      if (s + 1 < i) res += ex.query(s + 1, i);
      else ex.update(s, ex.query(s, s+1) + 1);
      if (res + 1 > dp.query(i, i + 1).maximum)
        dp.update_single(i, segment(res + 1, 0, 0, 0, 0));
    }
  }

  cout << dp.query_full().maximum << '\n';
}