#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  return (!a or !b) ? 0 : a * b / gcd(a, b);
}
long long poww(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
template <typename T>
static constexpr T inf = numeric_limits<T>::max() / 2;
template <class t, class u>
bool mmax(t& a, u b) {
  if (a < b) a = b;
  return a < b;
}
template <class t, class u>
bool mmin(t& a, u b) {
  if (b < a) a = b;
  return b < a;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using li = long long;
using vi = vc<int>;
using ii = pair<int, int>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto solve = [&]() {
    int n;
    cin >> n;
    vc<array<int, 3>> v(n);
    vi c(n, 0);
    for (int i = (0), ThxMK = (n); i < ThxMK; ++i) {
      int a, b;
      cin >> a >> b;
      v[i] = {b - a, a, b};
    }
    sort(begin(v), end(v));
    vi bye(n, 1);
    for (int i = (0), ThxMK = (n); i < ThxMK; ++i) {
      cout << v[i][1] << " " << v[i][2] << " ";
      for (int j = (v[i][1]), ThxMK = (v[i][2] + 1); j < ThxMK; ++j)
        if (bye[j - 1]) {
          cout << j << '\n';
          bye[j - 1] -= 1;
          break;
        }
    }
    cout << '\n';
  };
  int t;
  cin >> t;
  while (t--) solve();
}
