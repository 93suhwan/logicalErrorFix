#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 5e5 + 10;
template <class T, class FApply>
struct FenwickTree {
  T const identity;
  std::vector<T> f;
  FApply apply;
  FenwickTree(FenwickTree const &other) = default;
  FenwickTree(int n, T const identity, FApply const &apply)
      : identity(identity), f(n + 1, identity), apply(apply) {}
  void init(int n) { f.assign(n + 1, identity); }
  void update(int x, T d) {
    for (; x < (int)f.size(); x += x & -x) {
      apply(f[x], d);
    }
  }
  T prefix(int x) {
    T ans(identity);
    for (; x > 0; x &= x - 1) {
      apply(ans, f[x]);
    }
    return ans;
  }
};
template <class T, class FApply>
FenwickTree<T, FApply> makeFenwickTree(int const &n, T const &identity,
                                       FApply const &apply) {
  return FenwickTree<T, FApply>(n, identity, apply);
}
int n, a[maxN];
void solve() {
  cin >> n;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 1; i <= (int)(n); ++i) {
    mp[a[i]]++;
  }
  for (auto &p : mp) {
    if (p.second >= 2) {
      cout << "YES\n";
      return;
    }
  }
  auto f = makeFenwickTree<int>(n, 0, [](int &x, int y) { x += y; });
  int h = 0;
  for (int i = n; i; i--) {
    h ^= (f.prefix(a[i]) & 1);
    f.update(a[i], 1);
  }
  cout << (h ? "NO" : "YES") << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
