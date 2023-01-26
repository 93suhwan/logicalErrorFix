#include <bits/stdc++.h>
using namespace std;
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << "\n";
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
long long gcd(unsigned long long a, unsigned long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long int power(long long int x, long long int y,
                    long long int m = 1000000007) {
  long long int ans = 1;
  x %= m;
  while (y) {
    if (y & 1) ans = (x * ans) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return ans;
}
long long int power_nm(long long int x, long long int y) {
  long long int ans = 1;
  while (y) {
    if (y & 1) ans = (x * ans);
    x = (x * x);
    y >>= 1;
  }
  return ans;
}
long long int ncr(vector<long long int> &fact, int n, int r) {
  return (n >= r) ? ((fact[n] * ((power(fact[r], 1000000007 - 2) *
                                  power(fact[n - r], 1000000007 - 2)) %
                                 1000000007)) %
                     1000000007)
                  : 0;
}
int mul(int x, int y) { return (x * 1ll * y) % 1000000007; }
int divide(int x, int y) { return mul(x, power(y, 1000000007 - 2)); }
int add(int x, int y) {
  x += y;
  while (x >= 1000000007) x -= 1000000007;
  while (x < 0) x += 1000000007;
  return x;
}
int sub(int x, int y) { return (x - y + 1000000007) % 1000000007; }
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = (0); i < (n); i++) cin >> arr[i];
  bool isinc = true;
  for (int i = (1); i < (n); i++) {
    if (arr[i] <= arr[i - 1]) {
      isinc = false;
      break;
    }
  }
  if ((n & 1) == 1 && isinc)
    cout << "NO\n";
  else {
    cout << "YES\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int z = 1;
  cin >> z;
  while (z--) {
    solve();
  }
  return 0;
}
