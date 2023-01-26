#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
ll mi(ll a, ll b, ll p) {
  ll r = 1;
  while (b) {
    if (1 & b) r = r * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return r;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, y, x);
  y -= a / b * x;
}
void print(ll n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n > 9) print(n / 10);
  putchar(n % 10 + '0');
}
ll read() {
  char ch = getchar();
  ll f = 1, x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void init(){};
void solve() {
  long long n;
  string s;
  cin >> n;
  vector<long long> a, b, c(n);
  for (auto &t : c) cin >> t;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B')
      a.push_back(c[i]);
    else
      b.push_back(c[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long len = a.size(), p = a.size();
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] < i + 1) {
      cout << "NO\n";
      return;
    }
  }
  for (long long i = p; i < n; i++) {
    if (b[i - p] > i + 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
signed main() {
  init();
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
