#include <bits/stdc++.h>
using namespace std;
bool comp(string &a, string &b) { return (a.length() < b.length()); }
void show_vec(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long fact(long long n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
bool check_prime(int n) {
  if (n <= 1) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long i, a, b;
  cin >> a >> b;
  vector<long long> v;
  long long x = abs(a - b);
  long long y = x / 2;
  bool flag = false;
  if (x % 2 == 0) flag = true;
  long long mx = ceil((x * 1.0) / 2) + (2 * min(a, b));
  for (i = x / 2; i <= mx; i++) {
    cout << i << " ";
    if (flag) i++;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, x = 1, i;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
