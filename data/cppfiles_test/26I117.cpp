#include <bits/stdc++.h>
using namespace std;
long long Pow(long long b, long long p) {
  return p == 0 ? 1 : b * Pow(b, p - 1);
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
string to_String(long long n) {
  string s;
  while (n) {
    s.push_back(n % 10 + '0');
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long to_int(string s) {
  long long n = 0, i = 0, j = 1;
  for (long long i = 0; i < s.size(); i++) {
    n += (s[s.size() - (i + 1)] - '0') * j;
    j *= 10;
  }
  return n;
}
long long BigMod(long long b, long long p, long long m) {
  if (p == 0) return 1;
  long long ans = BigMod(b, p / 2, m);
  ans = (ans * ans) % m;
  if (p % 2 == 1) ans = (ans * b) % m;
  return ans;
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long ModInv(long long a, long long m) { return BigMod(a, m - 2, m); }
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}
long long fact(long long n) {
  if (n == 1)
    return 1;
  else
    return (n * fact(n - 1));
}
long long fun(long long n) {}
void solve() {
  long long n;
  cin >> n;
  long long cnt = 1;
  for (long long i = n * 2; i > 2; i--) {
    cnt = (cnt * 2) % 1000000007;
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  };
  return 0;
}
void sieve(vector<long long> &v) {
  v.assign(1000000007, 0);
  v[0] = v[1] = 1;
  for (int i = 4; i <= 1000000007; i += 2) v[i] = 1;
  for (int i = 3; i * i <= 1000000007; i += 2) {
    if (v[i] == 0) {
      for (int j = i * i; j <= 1000000007; j += i * 2) v[j] = 1;
    }
  }
}
