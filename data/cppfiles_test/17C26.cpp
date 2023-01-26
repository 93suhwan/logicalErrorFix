#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
template <typename T>
void chkmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void chkmax(T &a, T b) {
  a = max(a, b);
}
vector<int> a, b;
vector<vector<int>> G;
int n, m, k;
class LSH {
 public:
  int n;
  vector<int> p;
  LSH(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    p = x;
    n = p.size();
  }
  int hashing(int x) {
    return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
  }
  int rehashing(int i) { return p[i - 1]; }
};
class BIT {
 public:
  int n;
  vector<long long> tree;
  BIT(int n_) {
    n = n_ + 5;
    tree = vector<long long>(n);
  }
  int lowbit(int x) { return x & -x; }
  void update(int x, int v) {
    while (x < n) {
      tree[x] += v;
      x += lowbit(x);
    }
  }
  long long query(int x) {
    long long ans = 0;
    while (x) {
      ans += tree[x];
      x -= lowbit(x);
    }
    return ans;
  }
};
void multisolve(int kase) {
  cin >> n;
  a = vector<int>(n + 1);
  vector<int> allx;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    allx.push_back(a[i]);
  }
  LSH lsh(allx);
  BIT bit(lsh.n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int now = lsh.hashing(a[i]);
    int r = bit.query(lsh.n) - bit.query(now);
    int l = bit.query(now - 1);
    ans += min(l, r);
    bit.update(now, 1);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  auto t_s = clock();
  int t = 1;
  cin >> t;
  for (int kase = 1; kase <= t; kase++) multisolve(kase);
  auto t_e = clock();
  cerr << "\033[46:m";
  cerr << "cost time = " << 1.0 * (t_e - t_s) / CLOCKS_PER_SEC;
  cerr << "s\033[0m" << endl;
  return 0;
}
