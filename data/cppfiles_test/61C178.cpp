#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long primeFactors(long long n) {
  long long ans = 0;
  long long m = n;
  for (long long i = 2; i * i <= m; i++) {
    while (n % i == 0) {
      n /= i;
      ans++;
    }
  }
  if (n != 1) return ans + 1;
  return ans;
}
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2);
  ans *= ans;
  ans %= 1000000007;
  if (b % 2) {
    ans *= a;
  }
  return ans % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long total = n * (n - 1) * (n - 2) / 6;
    pair<long long, long long> p[n];
    map<long long, long long> t, d;
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      p[i] = {x, y};
      t[x]++;
      d[y]++;
    }
    long long di = 0;
    for (long long i = 0; i < n; i++) {
      di += (t[p[i].first] - 1) * (d[p[i].second] - 1);
    }
    cout << total - di << '\n';
  }
  return 0;
}
