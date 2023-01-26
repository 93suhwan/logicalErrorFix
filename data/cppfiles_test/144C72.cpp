#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
void visak(long long x, long long a, long long n, long long m) {
  vector<long long> vis(n + 1, 0);
  for (long long i = 0; i < (n % m); ++i) {
    long long k = f(n, m);
    cout << k << ' ';
    for (long long j = 0; j < k; ++j) {
      cout << x << ' ';
      vis[x] = 1;
      x++;
      if (x == n + 1) x = 1;
    }
    cout << '\n';
  }
  vector<long long> s;
  for (long long i = 1; i <= n; ++i)
    if (!vis[i]) s.push_back(i);
  for (long long i = 0; i < m - (n % m); ++i) {
    cout << n / m << ' ';
    for (long long j = 0; j < n / m; ++j) {
      cout << s.back() << ' ';
      s.pop_back();
    }
    cout << '\n';
  }
}
void solve(long long n, long long m, long long k) {
  long long x = 1;
  for (long long i = 0; i < k; ++i) {
    long long a = (n % m) * f(n, m);
    visak(x, a, n, m);
    x += a;
    while (x > n) x -= n;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long test;
  cin >> test;
  for (long long h = 0; h < test; ++h) {
    long long n, m, k;
    cin >> n >> m >> k;
    solve(n, m, k);
    cout << '\n';
  }
}
