#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
inline void def() {}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T>
inline void print_vector(vector<T> &a) {
  for (auto &x : a) cout << x << ' ';
  cout << endl;
}
inline long long binary_pow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long d;
  d = abs(a - b);
  if (c > 2 * d || a > 2 * d || b > 2 * d) {
    cout << "-1" << endl;
    return;
  }
  if (c + d <= 2 * d)
    cout << c + d << endl;
  else
    cout << c - d << endl;
}
int main() {
  def();
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
