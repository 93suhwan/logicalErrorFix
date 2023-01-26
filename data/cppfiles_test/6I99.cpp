#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
vector<bool> resh(int n) {
  vector<bool> v(n + 1, false);
  for (int i = 3; i * i <= n; i += 2) {
    if (!v[i]) {
      for (int j = i * i; j <= n; j += i) {
        v[j] = true;
      }
    }
  }
  return v;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
int ei(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
void solve() {
  int n;
  cin >> n;
  vector<char> v(n), v1(n);
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  if (v[0] == '1' && v1[0] == '0') {
    ans++;
    v[0] = '0';
    v1[0] = '2';
  }
  if (v1[n - 1] == '0' && v[n - 1] == '1') {
    ans++;
    v[n - 1] = '0';
    v1[n - 1] = '2';
  }
  if (v[0] == '1' && v1[1] == '1') {
    ans++;
    v[0] = '0';
    v1[1] = '2';
  }
  if (v1[n - 2] == '1' && v[n - 1] == '1') {
    ans++;
    v[n - 1] = '0';
    v1[n - 2] = '2';
  }
  for (int i = 1; i < n - 1; i++) {
    if (i < n / 2) {
      if (v[i] == '1') {
        if (v1[i - 1] == '1') {
          ans++;
          v[i] = '0';
          v1[i - 1] = '2';
        }
        if (v[i] == '0') {
          ans++;
          v[i] = '0';
          v1[i] = '2';
        }
        if (v1[i + 1] == '1') {
          ans++;
          v[i] = '0';
          v1[i + 1] = '2';
        }
      }
    } else {
      if (v[i] == '1') {
        if (v1[i] == '0') {
          ans++;
          v[i] = '0';
          v1[i] = '2';
        }
        if (v1[i + 1] == '1') {
          ans++;
          v[i] = '0';
          v1[i + 1] = '2';
        }
        if (v1[i - 1] == '1') {
          ans++;
          v[i] = '0';
          v1[i - 1] = '2';
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
