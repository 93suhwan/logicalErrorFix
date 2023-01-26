#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long d;
  while (b) {
    d = b;
    b = a % b;
    a = d;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long _pow(long long a, long long b) {
  long long d = 1;
  while (b) {
    if (b & 1) d *= a;
    a *= a;
    b >>= 1;
  }
  return d;
}
long long mpow(long long a, long long b, long long m) {
  long long d = 1;
  while (b) {
    if (b & 1) d = (d * (a % m)) % m;
    a = ((a % m) * (a % m)) % m;
    d %= m;
    b >>= 1;
  }
  return d % m;
}
void _exgcd(long long a, long long b, long long &g, long long &x,
            long long &y) {
  if (!b) {
    g = a;
    x = 1;
    y = 0;
  } else {
    _exgcd(b, a % b, g, y, x);
    y -= x * (a / b);
  }
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
  }
}
int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
  }
}
const long long mod = 1e9 + 7;
struct dsu {
  vector<int> f;
  dsu(int n) : f(n) { iota(f.begin(), f.end(), 0); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    f[y] = x;
  }
};
const int N = 222;
int T, n, m;
int va[N];
bool check(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 1;
    }
  }
  return 0;
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    long long sum = 0, ans = n;
    for (long long i = 1; i <= n; i++) cin >> va[i], sum += va[i];
    if (check(sum)) {
      cout << ans << '\n';
      for (long long i = 1; i <= n; i++) cout << i << ' ';
      cout << '\n';
      continue;
    }
    long long sel = 0;
    for (long long i = 1; i <= n; i++) {
      if (check(sum - va[i])) {
        sel = i;
        break;
      }
    }
    cout << ans - 1 << "\n";
    for (int i = 1; i <= n; i++)
      if (i != sel) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
