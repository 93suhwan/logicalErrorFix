#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, vector<int>& a) {
  for (auto& i : a) in >> i;
  return in;
}
ostream& operator<<(ostream& out, vector<int>& a) {
  for (auto& i : a) out << i << " ";
  return out;
}
istream& operator>>(istream& in, vector<long long>& a) {
  for (auto& i : a) in >> i;
  return in;
}
ostream& operator<<(ostream& out, vector<long long>& a) {
  for (auto& i : a) out << i << " ";
  return out;
}
const int INF = 1e9 + 7;
const long long lINF = 1e18;
const int d8x[8] = {1, 2, -1, -2, 1, 2, -1, -2},
          d8y[8] = {-2, -1, 2, 1, 2, 1, -2, -1};
const int d4x[4] = {-1, 1, 0, 0}, d4y[4] = {0, 0, -1, 1};
const int base = 1e9;
const int mxN = 2000010;
long double PI = acosl(-1.0);
void print(int x) { cerr << x << '\n'; }
void print(long x) { cerr << x << '\n'; }
void print(long long x) { cerr << x << '\n'; }
void print(unsigned x) { cerr << x << '\n'; }
void print(unsigned long x) { cerr << x << '\n'; }
void print(unsigned long long x) { cerr << x << '\n'; }
void print(float x) { cerr << x << '\n'; }
void print(double x) { cerr << x << '\n'; }
void print(long double x) { cerr << x << '\n'; }
void print(char x) { cerr << x << '\n'; }
void print(const char* x) { cerr << x << '\n'; }
void print(const string& x) { cerr << x << '\n'; }
void print(bool x) { cerr << (x ? "true\n" : "false\n"); }
double rtog(double r) { return r * 180 / PI; }
double gtor(double g) { return g * PI / 180; }
long long sum(vector<int> a) {
  long long s = 0;
  for (auto i : a) s += i;
  return s;
}
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
long long binpow(long long a, long long n, long long m) {
  if (n == 0) return 1;
  if (n & 1)
    return (binpow(a, n - 1, m) * a) % m;
  else {
    long long b = binpow(a, n / 2, m);
    return (b * b) % m;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), dp(n + 1), p(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = n, j = n - 1; i > 0; i--) {
    while (j >= i + b[i] - a[i + b[i]]) dp[j] = dp[i] + 1, p[j] = i, j--;
    if (j == i - 1) {
      cout << -1;
      return;
    }
  }
  for (int i = 0; i != n; i = p[i]) ans.push_back(i);
  reverse(ans.begin(), ans.end());
  cout << dp[0] << '\n';
  for (int i = 0; i < dp[0]; i++) cout << ans[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
