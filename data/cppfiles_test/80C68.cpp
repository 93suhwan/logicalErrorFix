#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
struct Vertex {
  int sum;
  int min_prefix_sum;
};
vector<Vertex> rmq;
void build(int i, int l, int r) {
  if (r - l == 1) {
    rmq[i].sum = 1;
    rmq[i].min_prefix_sum = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid, r);
  rmq[i].sum = rmq[2 * i + 1].sum + rmq[2 * i + 2].sum;
  rmq[i].min_prefix_sum =
      min(rmq[2 * i + 1].min_prefix_sum,
          rmq[2 * i + 1].sum + rmq[2 * i + 2].min_prefix_sum);
}
void upd(int i, int l, int r, int index, int w) {
  if (r - l == 1) {
    rmq[i].sum = w;
    rmq[i].min_prefix_sum = w;
    return;
  }
  int mid = (l + r) / 2;
  if (index < mid)
    upd(2 * i + 1, l, mid, index, w);
  else
    upd(2 * i + 2, mid, r, index, w);
  rmq[i].sum = rmq[2 * i + 1].sum + rmq[2 * i + 2].sum;
  rmq[i].min_prefix_sum =
      min(rmq[2 * i + 1].min_prefix_sum,
          rmq[2 * i + 1].sum + rmq[2 * i + 2].min_prefix_sum);
}
struct FenwickTree1 {
  vector<int> t;
  int n;
  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }
  int get(int vl, int vr) {
    if (vl > vr) return 0;
    int res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }
  void up(int v, int val) {
    for (; v < n; v = v | (v + 1)) {
      t[v] += val;
    }
  }
  FenwickTree1(int n_) {
    n = n_;
    t.assign(n, 0);
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  FenwickTree1 f(n);
  vector<pair<int, int> > farr;
  vector<int> sarr(m);
  for (int i = 0; i < n; ++i) {
    int first;
    cin >> first;
    farr.push_back(make_pair(first, i));
  }
  for (auto& first : sarr) cin >> first;
  sort(farr.begin(), farr.end());
  sort(sarr.begin(), sarr.end());
  rmq.assign(4 * n, {});
  build(0, 0, n);
  int cur = 0;
  long long ans = 0;
  int u = 0;
  int tt = 0;
  for (auto first : sarr) {
    while (u < farr.size() && farr[u].first < first) {
      cur++;
      upd(0, 0, n, farr[u++].second, -1);
    }
    tt = max(tt, u);
    while (tt < farr.size() && farr[tt].first == first) {
      upd(0, 0, n, farr[tt++].second, 0);
    }
    ans += cur + rmq[0].min_prefix_sum;
  }
  for (int i = 0; i < farr.size(); ++i) {
    ans += f.get(farr[i].second, n - 1);
    f.up(farr[i].second, 1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
