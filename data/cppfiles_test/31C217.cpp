#include <bits/stdc++.h>
using namespace std;
namespace {
using T = long long;
namespace module {
inline const T m = 998244353;
void add(T& a, T b) {
  if ((a += b) >= m) a -= m;
}
void dec(T& a, T b) {
  if ((a -= b) < 0) a += m;
}
void mul(T& a, T b) { a = a * b % m; }
T radd(T a, T b) { return (a += b) >= m ? a - m : a; }
T rdec(T a, T b) { return (a -= b) < 0 ? a + m : a; }
T rmul(T a, T b) { return a * b % m; }
};  // namespace module
constexpr char endl = '\n';
const int maxN = 2e5 + 5;
int n;
T a[maxN], b[maxN];
T gcd(T n, T m) { return m ? gcd(m, n % m) : n; }
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i += 2) {
    b[i] = a[i + 1];
    b[i + 1] = -a[i];
    T g = gcd(abs(b[i]), abs(b[i + 1]));
    b[i] /= g;
    b[i + 1] /= g;
  }
  if (n & 1) {
    int i = n - 2, j = n - 1, k = n;
    if (a[j] + a[k] == 0) i = n - 1, j = n - 2, k = n;
    if (a[j] + a[k] == 0) i = n, j = n - 2, k = n - 1;
    b[i] = a[j] + a[k];
    b[j] = -a[i];
    b[k] = -a[i];
    T g = gcd(abs(b[i]), abs(b[j]));
    g = gcd(g, abs(b[k]));
    b[i] /= g;
    b[j] /= g;
    b[k] /= g;
  }
  T sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i] * b[i];
  if (sum) cerr << "NO" << endl;
  for (int i = 1; i <= n; i++) sum += abs(b[i]);
  assert(sum <= 1000000000);
  for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}
}  // namespace
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t(1);
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
}
