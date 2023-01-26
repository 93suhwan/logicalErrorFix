#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const long long int inf = 9e18;
class ST {
 public:
  long long int leftmost, rightmost, to_prop, val;
  ST *lchild, *rchild;
  ST(long long int l, long long int r) {
    leftmost = l;
    rightmost = r;
    val = to_prop = 0;
    lchild = rchild = nullptr;
    if (l != r) {
      long long int mid = (l + r) / 2;
      lchild = new ST(l, mid);
      rchild = new ST(mid + 1, r);
    }
  }
  void recal() {
    if (lchild) {
      val = min(lchild->get_val(), rchild->get_val());
    }
  }
  void prop() {
    if (lchild) {
      lchild->to_prop += to_prop;
      rchild->to_prop += to_prop;
      to_prop = 0;
    }
    recal();
  }
  long long int get_val() { return val + to_prop; }
  void addRange(long long int l, long long int r, long long int v) {
    if (l > rightmost or r < leftmost) return;
    if (l <= leftmost and r >= rightmost) {
      to_prop += v;
      return;
    }
    prop();
    lchild->addRange(l, r, v);
    rchild->addRange(l, r, v);
    recal();
  }
  long long int query(long long int l, long long int r) {
    if (l > rightmost or r < leftmost) return inf;
    if (l <= leftmost and r >= rightmost) {
      return get_val();
    }
    prop();
    long long int lf = lchild->query(l, r);
    long long int rf = rchild->query(l, r);
    return min(lf, rf);
  }
};
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<tuple<long long int, long long int, long long int> > in;
  long long int l, r, w;
  for (long long int i = 1; i <= n; i++) {
    cin >> l >> r >> w;
    in.emplace_back(w, 2 * (l - 1), 2 * (r - 1));
  }
  sort(in.begin(), in.end());
  m--;
  ST st(0, 2 * m);
  l = 0;
  r = -1;
  long long int ans = inf;
  while (r < n - 1) {
    while (r + 1 < n and st.get_val() == 0) {
      r++;
      auto [w, u, v] = in[r];
      st.addRange(u, v, 1);
    }
    if (st.get_val() != 0) ans = min(ans, get<0>(in[r]) - get<0>(in[l]));
    st.addRange(get<0>(in[l]), get<1>(in[l]), -1);
    l++;
  }
  cout << ans << '\n';
  return 0;
}
