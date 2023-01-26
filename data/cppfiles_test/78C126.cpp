#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
struct mint {
  long long x;
  mint() : x(0) {}
  mint(long long x) : x((x % mod + mod) % mod) {}
  mint& fix() {
    x = (x % mod + mod) % mod;
    return *this;
  }
  mint operator-() const { return mint(0) - *this; }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint& a) const { return mint(*this) += a; }
  mint operator-(const mint& a) const { return mint(*this) -= a; }
  mint operator*(const mint& a) const { return mint(*this) *= a; }
  bool operator<(const mint& a) const { return x < a.x; }
  bool operator==(const mint& a) const { return x == a.x; }
};
template <typename T>
void show(vector<T> v) {
  for (auto it : v) {
    cout << it << " ";
  }
  cout << "\n";
}
void solve() {
  int r, l;
  std::cin >> l >> r;
  if (l == r) {
    std::cout << 0 << "\n";
    return;
  }
  int left = (r + 1) / 2;
  if (left < l) left = l;
  int remain = r % left;
  int rr = (r - 1) % left;
  std::cout << std::max(remain, rr) << "\n";
}
int main() {
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
