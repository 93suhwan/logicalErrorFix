#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long mod = 1000000007;
long long MOD = (1e9) + 7;
long long mul(long long x, long long y) { return (x * 1ll * y) % MOD; }
long long binpow(long long x, long long y) {
  long long z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
long long inv(long long x) { return binpow(x, MOD - 2); }
long long divide(long long x, long long y) { return mul(x, inv(y)); }
int cnt_prime(int a) {
  int cn1 = 0;
  int n1_t = a;
  for (int i = 2; i * i <= a; i++) {
    while (n1_t % i == 0) {
      n1_t /= i;
      cn1++;
    }
  }
  if (n1_t != 1) {
    cn1++;
  }
  return cn1;
}
long long pw(int k) {
  long long re = 1;
  while (k--) {
    re *= 2;
  }
  return re;
}
vector<int> dp;
long long mybinpow(long long b, long long e) {
  if (e == 0) {
    return 1;
  }
  if (e % 2 == 0) {
    long long temp = mybinpow(b, e / 2) % MOD;
    return (temp * temp) % MOD;
  } else {
    long long temp = mybinpow(b, e / 2) % MOD;
    return ((temp * temp) % MOD * (b % MOD)) % MOD;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(std::numeric_limits<double>::max_digits10);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int count = 0;
    stack<int> S;
    long long K = k;
    long long ans = 0;
    long long ans2 = 0;
    for (int ind = 0; ind < n; ind++) {
      if (S.empty() or S.top() == v[ind]) {
        S.push(v[ind]);
      } else if (k > 0) {
        S.pop();
        k--;
      } else {
        S.push(v[ind]);
      }
    }
    while (!S.empty()) {
      if (k > 0) {
        if (S.size() > 2) {
          int a1 = S.top();
          S.pop();
          int a2 = S.top();
          ans += (a2 / a1);
          S.pop();
          k--;
        } else {
          ans += S.top();
          S.pop();
        }
      } else {
        ans += S.top();
        S.pop();
      }
    }
    int i;
    for (i = n - 1; count < K; i -= 2) {
      int a1 = v[i - 1];
      int a0 = v[i];
      ans2 += (a1 / a0);
      count++;
    }
    for (int j = 0; j <= i; j++) {
      ans2 += v[j];
    }
    cout << min(ans, ans2) << "\n";
  }
  return 0;
}
