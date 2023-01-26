#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long convert(long long n) {
  string bin = "";
  while (n) {
    bin += ((n % 2) + '0');
    n /= 2;
  }
  reverse(bin.begin(), bin.end());
  long long res = stoll(bin);
  return res;
}
int toint(string s) {
  stringstream geek(s);
  int x = 0;
  geek >> x;
  return x;
}
void nPermute(string str, long int n) {
  sort(str.begin(), str.end());
  long int i = 1;
  do {
    if (i == n) break;
    i++;
  } while (next_permutation(str.begin(), str.end()));
  cout << str;
}
bool isPrime(long long n);
long long power(long long x, long long y);
long long gcd(long long a, long long b);
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  unordered_set<long long> s;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    s.insert(v[i]);
  }
  for (long long i = 0; i < n; i++) {
    long long count = min(32ll, i + 2);
    long long chk = 1;
    for (long long j = 2; j < count + 1; j++) {
      if (v[i] % j != 0) {
        chk = 0;
        break;
      }
    }
    if (chk == 1) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return ((power(x, y / 2) % mod) * (power(x, y / 2) % mod)) % mod;
  else
    return ((((x % mod) * ((power(x, y / 2) % mod))) % mod *
             (power(x, y / 2) % mod)) %
            mod) %
           mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
