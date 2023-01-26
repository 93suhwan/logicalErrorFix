#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod1 = 998244353;
const long long mod = 1e9 + 7;
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long findMinNumber(long long n) {
  long long count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, i, j;
    cin >> n >> k;
    map<long long, long long> m;
    vector<long long> ans;
    vector<pair<long long, long long> > v;
    long long a[k][2];
    for (i = 0; i < k; i++) {
      cin >> a[i][0] >> a[i][1];
      v.push_back({a[i][0], a[i][1]});
      m[a[i][0]]++;
      m[a[i][1]]++;
    }
    for (i = 1; i < 2 * n + 1; i++)
      if (m[i] == 0) ans.push_back(i);
    for (i = 0; i < ans.size() / 2; i++) {
      v.push_back({ans[i], ans[ans.size() / 2 + i]});
    }
    long long cnt = 0;
    sort((v).begin(), (v).end());
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i != j) {
          long long x = (v[i].second - v[j].first) * (v[i].first - v[j].first);
          long long y =
              (v[i].second - v[j].second) * (v[i].first - v[j].second);
          if (x * y < 0) {
            cnt++;
          }
        }
      }
    }
    cout << cnt / 2 << '\n';
  }
  return 0;
}
