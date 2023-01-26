#include <bits/stdc++.h>
using namespace std;
const int mod2 = 998244353;
const int mod = 1e9 + 7;
const int maxn = INT_MAX;
template <class T>
T gcd(T a, T b) {
  while (a != 0) {
    T tmp = a;
    a = b % a;
    b = tmp;
  }
  return b;
}
vector<bool> sieve(int n) {
  vector<bool> prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }
  return prime;
}
vector<long long> noOfDivisors(int n) {
  vector<long long> div(n + 1, 0);
  div[1] = 1;
  for (long long i = (long long)2; i < (long long)n + 1; ++i) div[i] = 2;
  for (long long i = (long long)2; i < (long long)n + 1; ++i) {
    for (int j = 2 * i; j <= n; j += i) div[j]++;
  }
  return div;
}
vector<long long> divisors(long long n) {
  vector<long long> div;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (n / i != i) div.push_back(n / i);
    }
  }
  return div;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long addmod(long long a, long long b) { return (a % mod + b % mod) % mod; }
long long mulmod(long long a, long long b) { return (a % mod * b % mod) % mod; }
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}
string tobin(long long x) {
  string s = "";
  while (x != 0) {
    s += '0' + x % 2;
    x /= 2;
  }
  return rev(s);
}
long long toint(string x) {
  long long ans = 0;
  for (long long i = (long long)0; i < (long long)x.length(); ++i) {
    ans = (ans << 1) + (x[i] - '0');
  }
  return ans;
}
bool pal(string s) {
  int i = 0, j = s.length() - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
map<string, bool> mp;
bool check(string s, long long y, string par) {
  long long x = toint(s);
  if (x % 2 == 1 && y % x == 0 && ((y / x) & (y / x - 1)) == 0)
    return true;
  else if (x % 2 == 0 && x == y)
    return true;
  else if (x == 0)
    return false;
  else {
    bool ans = false;
    if (mp.find(s) != mp.end()) return mp[s];
    if (s[s.length() - 1] == '0')
      ans = false;
    else
      ans = (rev(s) != par && check(rev(s), y, s)) ||
            check(rev(s.substr(1)), y, s);
    mp[s] = ans;
    return mp[s];
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    long long a, b;
    cin >> b >> a;
    string x = tobin(a);
    if (check(x, b, ""))
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
  return 0;
}
