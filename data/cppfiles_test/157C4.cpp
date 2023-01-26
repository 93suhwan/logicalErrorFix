#include <bits/stdc++.h>
using namespace std;
inline long long inverse(long long a, long long md) {
  a %= md;
  if (a < 0) a += md;
  long long b = md, u = 0, v = 1;
  while (a) {
    long long t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
long long fact[5001];
long long inv[5001];
void pre() {
  fact[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i <= 5000; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= 998244353;
    inv[i] = inv[i - 1] * inverse(i, 998244353);
    inv[i] %= 998244353;
  }
}
long long ncr(long long n, long long r) {
  if (n < r) {
    return 0;
  }
  long long ans = fact[n];
  ans *= inv[r];
  ans %= 998244353;
  ans *= inv[n - r];
  ans %= 998244353;
  return ans;
}
long long calc(vector<long long>& v) {
  long long n = v.size();
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    c += v[i];
  }
  return ncr(n, c);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << 1 << "\n";
    return 0;
  }
  long long i = 0;
  vector<long long> v;
  long long c = 0;
  for (; i < n; i++) {
    c += (s[i] - '0');
    if (c <= k) {
      v.push_back(s[i] - '0');
    } else {
      break;
    }
  }
  if (c < k) {
    cout << 1 << "\n";
    return 0;
  }
  long long ans = calc(v);
  long long sz = (long long)v.size();
  while (1) {
    if (i >= n) break;
    while (v.size() > 0 and v[0] == 0) {
      v.erase(v.begin());
    }
    v.erase(v.begin());
    long long f = calc(v);
    long long c = k - 1;
    while (i < n) {
      c += (s[i] - '0');
      if (c <= k) {
        v.push_back(s[i] - '0');
        i += 1;
      } else {
        break;
      }
    }
    if (c < k) break;
    ans -= f;
    ans %= 998244353;
    ans += 998244353;
    ans %= 998244353;
    ans += calc(v);
    ans %= 998244353;
  }
  cout << ans << "\n";
}
