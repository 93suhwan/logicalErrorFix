#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segment_tree {
  vector<T> tree;
  vector<T> lazy;
  vector<bool> tag;
  T neutral;
  function<T(T, T)> join;
  int size;
  segment_tree(int _size, T _neutral, function<T(T, T)> f) {
    join = f;
    size = _size;
    tree = vector<T>(4 * size);
    lazy = vector<T>(4 * size);
    tag = vector<bool>(4 * size);
    neutral = _neutral;
  }
  void prop(int l, int r, int p) {
    if (lazy[p] == 0) return;
    if (l < r) {
      if (!tag[p]) {
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
      } else {
        lazy[p << 1] = lazy[p << 1 | 1] = lazy[p];
        tree[p << 1] = tree[p << 1 | 1] = 0;
        tag[p << 1] = tag[p << 1 | 1] = 1;
      }
    }
    if (tag[p] == 1) {
      tree[p] = 0;
    }
    tag[p] = 0;
    tree[p] += lazy[p] * (r - l + 1);
    lazy[p] = 0;
  }
  void point_update(int id, T val) { point_update(1, size, id, val, 1); }
  void point_update(int l, int r, int x, T val, int p) {
    prop(l, r, p);
    if (l > x || r < x) {
      return;
    }
    if (l == r) {
      tree[p] = val;
      return;
    }
    int middle = l + r >> 1;
    point_update(l, middle, x, val, p << 1);
    point_update(middle + 1, r, x, val, p << 1 | 1);
    tree[p] = join(tree[p << 1], tree[p << 1 | 1]);
  }
  void range_update(int L, int R, T val, bool flag) {
    if (L > R) {
      return;
    }
    range_update(1, size, L, R, val, flag, 1);
  }
  void range_update(int l, int r, int L, int R, T val, bool flag, int p) {
    prop(l, r, p);
    if (L > r || l > R) return;
    if (L <= l && R >= r) {
      tag[p] = flag;
      if (flag == 0) {
        lazy[p] += val;
      } else {
        lazy[p] = val;
      }
      prop(l, r, p);
      return;
    }
    int middle = l + r >> 1;
    range_update(l, middle, L, R, val, flag, p << 1);
    range_update(middle + 1, r, L, R, val, flag, p << 1 | 1);
    tree[p] = join(tree[p << 1], tree[p << 1 | 1]);
  }
  T get(int id) { return query(id, id); }
  T query(int L, int R) {
    if (L > R) {
      return neutral;
    }
    return query(1, size, L, R, 1);
  }
  T query(int l, int r, int L, int R, int p) {
    prop(l, r, p);
    if (L > r || l > R) return neutral;
    if (L <= l && R >= r) return tree[p];
    int middle = l + r >> 1;
    T lft = query(l, middle, L, R, p << 1);
    T rgh = query(middle + 1, r, L, R, p << 1 | 1);
    return join(lft, rgh);
  }
};
const int N = 3e5 + 10;
long long L[N], R[N], tree[N][2];
int a[N], n;
void add(int x, int y, int z) {
  for (; x < N; x += x & -x) {
    tree[x][z] += y;
  }
}
long long sum(int x, int z) {
  long long ans = 0;
  for (; x > 0; x -= x & -x) {
    ans += tree[x][z];
  }
  return ans;
}
long long sum(int l, int r, int z) { return sum(r, z) - sum(l - 1, z); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  segment_tree<long long> t(
      N - 1, 0, [](long long x, long long y) -> long long { return x + y; });
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    L[i] = L[i - 1] + 1LL * a[i] * (i - 1) - t.get(a[i]);
    int cnt = 0;
    for (int x = 0; x < N; x += a[i]) {
      int y = min(x + a[i], N) - 1;
      t.range_update(x, y, 1LL * cnt * a[i], 0);
      ++cnt;
    }
  }
  for (int i = 1; i <= n; ++i) {
    R[i] = R[i - 1];
    for (int x = 0; x < N; x += a[i]) {
      int y = min(x + a[i], N) - 1;
      R[i] += sum(x, y, 1);
      R[i] -= sum(x, y, 0) * x;
    }
    add(a[i], 1, 0);
    add(a[i], a[i], 1);
  }
  for (int i = 1; i <= n; ++i) {
    cout << L[i] + R[i] << ' ';
  }
}
