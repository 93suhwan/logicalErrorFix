#include <bits/stdc++.h>
using namespace std;
const long long long long mod = 1e9 + 7;
const long long long long mod2 = 998244353;
long long long long power(long long long long a, long long long long b) {
  if (b == 0)
    return 1;
  else {
    long long long long x = power(a, b / 2) % mod;
    long long long long y = ((x % mod) * (x % mod)) % mod;
    if (b % 2) y = ((y % mod) * (a % mod)) % mod;
    return y % mod;
  }
}
long long long long log_a_to_base_b(long long long long a,
                                    long long long long b) {
  return log(a) / log(b);
}
bool compare_double(double x, double y) {
  double epsilon = 1e-6;
  if (fabs(x - y) < epsilon) return true;
  return false;
}
long long long long fact(long long long long n) {
  long long long long res = 1;
  for (long long long long i = 2; i <= n; i++) res = (res * i) % mod;
  return res;
}
long long long long nCr(long long long long n, long long long long r) {
  return (fact(n) / (fact(r) * fact(n - r)) % mod) % mod;
}
string dec_to_bin(long long n) {
  string ans = "";
  while (n != 0) {
    if (n % 2 == 0)
      ans += '0';
    else
      ans += '1';
    n = n / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool is_prime(long long n) {
  long long ans = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans++;
      if (i != n / i) ans++;
    }
    if (ans > 2) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> mp;
    vector<long long> vec;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (mp[a[i]] == 0 && a[i] <= n)
        mp[a[i]]++;
      else
        vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    long long ans = 0;
    long long j = 0;
    for (long long i = 1; i <= n; i++) {
      if (mp[i] == 1) continue;
      if (i <= (vec[j] - 1) / 2) {
        ans++;
        j++;
      } else {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
