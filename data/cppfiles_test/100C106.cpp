#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int mod = 998244353;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long int inv(long long int a) { return power(a, mod - 2); }
long long int add(long long int a, long long int b) { return (a + b) % mod; }
long long int sub(long long int a, long long int b) {
  return (a - b + mod) % mod;
}
long long int mul(long long int a, long long int b) { return (a * b) % mod; }
long long int divi(long long int a, long long int b) {
  return (a * inv(b)) % mod;
}
long long fact[300000 + 1];
void pre() {
  fact[0] = 1;
  for (int i = 1; i < 300000; i++) fact[i] = mul(fact[i - 1], i);
}
void solve() {
  int n;
  cin >> n;
  long long arr[n];
  map<long long, long long> m;
  long long ma = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]]++;
    ma = max(arr[i], ma);
  }
  if (m[ma] > 1)
    cout << fact[n] << "\n";
  else
    cout << sub(fact[n], divi(fact[n], m[ma] + m[ma - 1])) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int num = 1;
  cin >> num;
  for (long long int i = 0; i < num; i++) {
    solve();
  }
}
