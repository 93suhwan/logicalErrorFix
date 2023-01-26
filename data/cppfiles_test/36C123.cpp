#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long mod = 1000000007;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long int powermod(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long int inv(long long int a) {
  return (powermod(a, mod - 2) % mod + mod) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int e = 0, o = 0;
  long long int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2)
      o++;
    else
      e++;
    s += a[i];
  }
  bool f = false;
  for (long long int i = 2; i <= sqrt(s); i++)
    if (s % i == 0) {
      f = true;
      break;
    }
  if (f) {
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << i + 1 << " ";
  } else {
    cout << n - 1 << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 1 && cnt == 0) {
        cnt++;
        continue;
      }
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
