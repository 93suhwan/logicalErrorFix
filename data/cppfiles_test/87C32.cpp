#include <bits/stdc++.h>
using namespace std;
void sieve(vector<long long>& v) {
  long long n = (100000000);
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      v.push_back(i);
      for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long ncr(long long n, long long r) {
  long long a = 1, b = 1;
  if (n - r < r) {
    r = n - r;
  }
  if (r != 0) {
    while (r) {
      a = a * n;
      b = b * r;
      long long g = gcd(a, b);
      a = a / g;
      b = b / g;
      n--;
      r--;
    }
  } else {
    a = 1;
  }
  return a;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[m], b[m], c[m];
  memset(b, 0, sizeof b);
  map<long long, vector<long long>> v;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    c[i] = a[i];
  }
  sort(c, c + m);
  for (long long i = 0; i < m; i++) {
    v[c[i]].push_back(i);
  }
  map<long long, vector<long long>> l;
  for (auto x : v) {
    sort(x.second.begin(), x.second.end(), greater<long long>());
    l[x.first] = x.second;
  }
  set<long long> s;
  long long cnt = 0;
  for (long long i = 0; i < m; i++) {
    long long z;
    for (auto y : l[a[i]]) {
      if (s.find(y) == s.end()) {
        z = y;
        s.insert(z);
        break;
      }
    }
    for (long long j = 0; j < m; j++) {
      if (j == z) {
        b[j] = a[i];
        break;
      }
      if (b[j] != 0) {
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
