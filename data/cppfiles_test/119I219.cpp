#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
const long long mod = 100000000007;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
string DecimalToBinaryString(int a) {
  string binary = "";
  int mask = 1;
  for (int i = 0; i < 31; i++) {
    if ((mask & a) >= 1)
      binary = "1" + binary;
    else
      binary = "0" + binary;
    mask <<= 1;
  }
  cout << binary << endl;
  return binary;
}
string helper(string s, int k) {
  while (s.size() <= k) {
    s = s + s;
  }
  return s.substr(0, k);
}
void solve() {
  int n;
  cin >> n;
  long long a[n];
  int i;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  vector<long long> ans;
  i = 1;
  int j = n;
  while (i <= j) {
    long long t1 =
        ((a[i] + a[j]) % 2 == 0) ? (a[i] + a[j]) / 2 : (a[i] + a[j]) / 2;
    long long t2 =
        ((a[i] + a[j]) % 2 == 0) ? (a[i] + a[j]) / 2 : (a[i] + a[j]) / 2 + 1;
    ans.push_back(t1);
    ans.push_back(t2);
    i++;
    j--;
  }
  sort(ans.begin(), ans.end());
  cout << ans[ans.size() - 1] - ans[0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
