#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
const long long int INF = 1e18 + 5;
const long long int mod = 1e9 + 7;
template <typename T>
T power(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % mod;
    y >>= 1LL;
    x = (x * x) % mod;
  }
  return ans % mod;
}
inline long long int mul(long long int a, long long int b) {
  return (a * 1ll * b) % mod;
}
inline long long int sub(long long int a, long long int b) {
  long long int c = a - b;
  if (c < 0) c += mod;
  return c;
}
inline long long int add(long long int a, long long int b) {
  long long int c = a + b;
  if (c >= mod) c -= mod;
  return c;
}
inline long long int inv(long long int a) { return power(a, mod - 2); }
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  deque<long long int> p, q;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) continue;
    if (a[i] < 0) {
      p.push_back(abs(a[i]));
      continue;
    }
    q.push_back(a[i]);
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  reverse(p.begin(), p.end());
  reverse(q.begin(), q.end());
  long long int x = 0, y = 0, ans = INF;
  if (p.size() == 0 && q.size() == 0) {
    cout << 0 << endl;
    return;
  }
  for (long long int i = 0; i < p.size(); i += k) x += (2 * p[i]);
  for (long long int i = 0; i < q.size(); i += k) x += (2 * q[i]);
  if (p.size()) ans = min(ans, x - p[0]);
  if (q.size()) ans = min(ans, x - q[0]);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
