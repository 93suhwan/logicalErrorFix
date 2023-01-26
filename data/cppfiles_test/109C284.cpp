#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long maxn = 1e7;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else {
    return gcd(b, a % b);
  }
}
long long getSum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long countdigits(long long n) { return floor(log10(n) + 1); }
bool isSquare(long long x) {
  long long y = sqrt(x);
  return y * y == x;
}
long long prime(long long p) {
  if (p == 1) return 0;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void precisionCompute(long long x, long long y, long long n) {
  long long d = x / y;
  for (long long i = 0; i <= n; i++) {
    cout << d;
    x = x - (y * d);
    if (x == 0) break;
    x = x * 10;
    d = x / y;
    if (i == 0) cout << ".";
  }
}
void reverseStr(string& s) {
  long long n = s.length();
  for (long long i = 0; i < n / 2; i++) swap(s[i], s[n - i - 1]);
}
bool isPalindrome(string str) {
  long long low = 0;
  long long high = str.length() - 1;
  while (low < high) {
    if (str[low] != str[high]) {
      return false;
    }
    low++;
    high--;
  }
  return true;
}
bool countFreq(long long a[], long long n) {
  unordered_map<long long, long long> make_pair;
  for (long long i = 0; i < n; i++) make_pair[a[i]]++;
  for (auto x : make_pair) {
    if (x.second > 1) {
      return false;
    }
  }
  return true;
}
bool isPower(long long x, long long y) {
  if (x == 1) return (y == 1);
  long long pow = 1;
  while (pow < y) pow *= x;
  return (pow == y);
}
long long convert(string s) {
  stringstream geek(s);
  long long x = 0;
  geek >> x;
  return x;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0, c1 = 0, c2 = 0;
  for (long long i = 0; i < n; i++) {
    if (s[n - 1] == '0') {
      if (s[i] != '0') {
        ans += (s[i] - '0');
        c1++;
      }
    } else {
      if (s[i] != '0') {
        ans += (s[i] - '0');
        if (i != (n - 1)) {
          c1++;
        }
      }
    }
  }
  cout << ans + c1 << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
