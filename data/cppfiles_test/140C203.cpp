#include <bits/stdc++.h>
using namespace std;
vector<long long int> primes;
void show(vector<long long int> v) {
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << endl;
}
vector<long long int> get_digits(long long int n) {
  vector<long long int> v;
  while (n > 0) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}
long long int binpow(long long int n, long long int k) {
  n %= 1000000007;
  long long int res = 1;
  while (k > 0) {
    if (k & 1) res = res * n % 1000000007;
    n = n * n % 1000000007;
    k >>= 1;
  }
  return res;
}
int binary_search(vector<long long int> v, long long int search) {
  int lo = 0;
  int hi = v.size() - 1;
  int mid = (lo + hi) / 2;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (v[mid] < search) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  if (v[lo] == search) return lo;
  if (v[hi] == search)
    return hi;
  else
    return -1;
}
bool is_prime(long long int n) {
  if (n <= 1) return false;
  if (n % 2 == 0) return false;
  if (n == 2 || n == 3) return true;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(long long int m) {
  vector<bool> v(m, true);
  for (long long int i = 2; i * i < m; i++) {
    if (v[i])
      for (long long int j = i * i; j < m; j += i) v[j] = false;
  }
  for (long long int i = 2; i < m; i++)
    if (v[i]) primes.push_back(i);
}
long long int GCD(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
bool is_palindrome(string s, int n) {
  long long int i = 0, j = n - 1;
  while (i <= j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
long long int ncr(long long int n, long long int r) {
  if (n < r) return 0;
  if (n == r) return 1;
  long long int f[n + 1];
  f[0] = 1, f[1] = 1;
  for (int i = 2; i <= n; i++) f[i] = i * f[i - 1];
  long long int ans = (f[n]) / (f[n - r] * f[r]);
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  long long int sqrt = pow(n, 0.5);
  long long int cube = pow(n, 0.3334);
  set<long long int> s;
  for (long long int i = 1; i <= sqrt; i++) {
    if (i * i <= n) {
      s.insert(i * i);
    }
  }
  for (long long int i = 1; i <= cube; i++) {
    if (i * i * i <= n) {
      s.insert(i * i * i);
    }
  }
  cout << s.size();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
