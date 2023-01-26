#include <bits/stdc++.h>
using namespace std;
template <typename T>
long long binpow(T a, T n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans *= a;
    a *= a;
    n >>= 1;
  }
  return ans;
}
template <typename T>
T gcd(const T &a, const T &b) {}
template <typename T>
T lcm(const T &a, const T &b) {}
void fileio(std::string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
int gcd(int a, int b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void solve() {
  int n;
  cin >> n;
  cout << 2 << " " << n - 1 << endl;
}
int32_t main() {
  ios::sync_with_stdio();
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
