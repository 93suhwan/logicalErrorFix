#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
bool isprime(long long n) {
  if (n <= 1) return true;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
bool ispalin(string s) {
  for (long long i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<long long> v = {a, b, c};
  sort(v.begin(), v.end());
  a = v[0], b = v[1], c = v[2];
  long long maxi = (a - 1) + (b - 1) + (c - 1);
  long long mini = max((long long)0, c - (a + b) - 1);
  if (m <= maxi && m >= mini) {
    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
  return;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
