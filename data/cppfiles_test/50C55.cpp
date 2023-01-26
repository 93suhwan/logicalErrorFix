#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
void addU(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
int mult(int a, int b) { return (long long)a * b % mod; }
class segment_tree {
 private:
  struct node {
    int weight = 0;
    int alter_sum = 0;
    int sum = 0;
    int sign = 0;
    bool to_delete = false;
    void apply(int y, int parity, int type) {
      if (type == 1) {
        if (parity) {
          alter_sum = sub(y, alter_sum);
          sign ^= 1;
          sum = sub(mult(weight, y), sum);
        } else {
          alter_sum = add(y, alter_sum);
          addU(sum, mult(weight, y));
        }
      } else {
        alter_sum = 0;
        sum = 0;
        sign = 0;
        to_delete = true;
      }
    }
    void on_build(int w) { weight = w; }
  };
  node merge(const node &a, const node &b) const {
    node res;
    res.weight = a.weight + b.weight;
    res.sum = add(a.sum, b.sum);
    return res;
  }
  void push(int x) {
    if (tr[x].to_delete) {
      tr[x * 2].apply(0, 0, 2);
      tr[x * 2 + 1].apply(0, 0, 2);
      tr[x].to_delete = false;
    }
    tr[x * 2].apply(tr[x].alter_sum, tr[x].sign, 1);
    tr[x * 2 + 1].apply(tr[x].alter_sum, tr[x].sign, 1);
    tr[x].alter_sum = 0;
    tr[x].sign = 0;
  }
  vector<node> tr;

 public:
  int n;
  void assign(int _n) {
    n = _n;
    int z;
    for (z = 1; z < n; z <<= 1)
      ;
    tr = vector<node>(z * 2);
  }
  template <typename M>
  segment_tree(const vector<M> &v) {
    assign(v.size());
    build(1, 0, n - 1, v);
  }

 private:
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tr[x].on_build(v[l]);
    } else {
      int m = (l + r) / 2;
      build(x * 2, l, m, v);
      build(x * 2 + 1, m + 1, r, v);
      tr[x] = merge(tr[x * 2], tr[x * 2 + 1]);
    }
  }
  template <typename... M>
  void update_in(int x, int cl, int cr, int l, int r, const M &...v) {
    if (l <= cl && cr <= r) {
      tr[x].apply(v...);
    } else {
      push(x);
      int cm = (cl + cr) / 2;
      if (l <= cm) {
        update_in(x * 2, cl, cm, l, r, v...);
      }
      if (r > cm) {
        update_in(x * 2 + 1, cm + 1, cr, l, r, v...);
      }
      tr[x] = merge(tr[x * 2], tr[x * 2 + 1]);
    }
  }

 public:
  template <typename... M>
  void update(int l, int r, const M &...v) {
    assert(0 <= l && l <= r && r < n);
    update_in(1, 0, n - 1, l, r, v...);
  }
  node get() const { return tr[1]; }
};
int solve(const vector<int> &a) {
  const int n = a.size();
  vector<int> values = a;
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());
  const int SZ = values.size();
  vector<int> weights(SZ);
  for (int i = 0; i < SZ; i++) {
    weights[i] = values[i] - (i ? values[i - 1] : 0);
  }
  segment_tree st(weights);
  int index = lower_bound(values.begin(), values.end(), a[0]) - values.begin();
  st.update(0, index, 1, 1, 1);
  for (int i = 1; i < n; i++) {
    index = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    int sum = st.get().sum;
    st.update(0, index, sum, 1, 1);
    if (index + 1 < SZ) {
      st.update(index + 1, SZ - 1, 0, 0, 2);
    }
  }
  return st.get().sum;
}
void foo() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = solve(a);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
