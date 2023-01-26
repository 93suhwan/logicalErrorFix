#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
const double PI = acos(-1);
const double e = exp(1);
class Math {
 public:
  long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
  long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
  long long fastpower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
      if (power & 1) {
        result = result * base % mod;
      }
      power >>= 1;
      base = (base * base) % mod;
    }
    return result;
  }
  double PointToSegDist(double x, double y, double x1, double y1, double x2,
                        double y2) {
    double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
    if (cross <= 0) return ((x - x1) * (x - x1) + (y - y1) * (y - y1));
    double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (cross >= d2) return ((x - x2) * (x - x2) + (y - y2) * (y - y2));
    double r = cross / d2;
    double px = x1 + (x2 - x1) * r;
    double py = y1 + (y2 - y1) * r;
    return ((x - px) * (x - px) + (py - y) * (py - y));
  }
  int Digits(int i) {
    int z = 0;
    int c = i;
    while (c) {
      z |= (1 << (c % 10));
      c /= 10;
    }
    return __builtin_popcount(z);
  }
  int CalcBit(unsigned long long num) {
    int cnt = 1;
    while (num) {
      num /= 10;
      cnt++;
    }
    return cnt;
  }
};
class SegTree {
 public:
  vector<int> arr;
  vector<int> tree;
  int n;
  SegTree(int _n) : n(_n - 1), tree(2 * _n), arr(_n, 0) {}
  void BuildTree(int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = start + end >> 1;
      int left_node = 2 * node + 1;
      int right_node = 2 * node + 2;
      BuildTree(left_node, start, mid);
      BuildTree(right_node, mid + 1, end);
      tree[node] = tree[left_node] + tree[right_node];
    }
  }
  void UpdataTree(int node, int start, int end, int idx, int val) {
    if (start == end) {
      arr[idx] = val;
      tree[node] = val;
    } else {
      int mid = start + end >> 1;
      int left_node = 2 * node + 1;
      int right_node = 2 * node + 2;
      if (idx >= start && idx <= mid)
        UpdataTree(left_node, start, mid, idx, val);
      else
        UpdataTree(right_node, mid + 1, end, idx, val);
      tree[node] = tree[left_node] + tree[right_node];
    }
  }
  int QueryTree(int node, int start, int end, int L, int R) {
    if (end < L || start > R) {
      return 0;
    } else if (L <= start && end >= R) {
      return tree[node];
    } else if (start == end) {
      return tree[node];
    } else {
      int mid = start + end >> 1;
      int left_node = node * 2 + 1;
      int right_node = node * 2 + 2;
      int sum_left = QueryTree(left_node, start, mid, L, R);
      int sum_right = QueryTree(right_node, mid + 1, end, L, R);
      return sum_left + sum_right;
    }
  }
};
class UF {
 public:
  vector<int> fa;
  vector<int> sz;
  int n;
  int comp_cnt;

 public:
  UF(int _n) : n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
    iota(fa.begin(), fa.end(), 0);
  }
  int findset(int x) { return fa[x] == x ? x : fa[x] = findset(fa[x]); }
  void unite(int x, int y) {
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    fa[y] = x;
    sz[x] += sz[y];
    --comp_cnt;
  }
  bool findAndUnite(int x, int y) {
    int x0 = findset(x);
    int y0 = findset(y);
    if (x0 != y0) {
      unite(x0, y0);
      return true;
    }
    return false;
  }
};
inline void Init() {
  Math math();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long x[N];
int main() {
  Init();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  long long ans = 0;
  for (int i = 1; i <= n; i += 2) {
    long long sum = 0, lb = 0;
    for (int j = i + 1; j <= n; j++) {
      if (!(j & 1)) {
        long long dif = -sum;
        long long l = -lb;
        l = max(l, 1ll);
        l = max(l, 1 + dif);
        long long r = x[i];
        r = std::min(r, x[j] + dif);
        if (r >= l) ans += r - l + 1;
      }
      if (j & 1)
        sum += x[j];
      else
        sum -= x[j];
      lb = min(lb, sum);
    }
  }
  cout << ans;
}
