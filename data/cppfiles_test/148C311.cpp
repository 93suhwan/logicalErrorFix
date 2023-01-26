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
  long long w, h;
  cin >> w >> h;
  long long w11, w22, h11, h22;
  cin >> w11;
  vector<long long> v1;
  for (long long i = 0; i < w11; i++) {
    long long x;
    cin >> x;
    v1.push_back(x);
  }
  long long r11, r22, r33, r44;
  r11 = v1[w11 - 1] - v1[0];
  r11 = r11 * h;
  cin >> w22;
  vector<long long> v2;
  for (long long i = 0; i < w22; i++) {
    long long x;
    cin >> x;
    v2.push_back(x);
  }
  r22 = v2[w22 - 1] - v2[0];
  r22 = r22 * h;
  cin >> h11;
  vector<long long> z1;
  for (long long i = 0; i < h11; i++) {
    long long x;
    cin >> x;
    z1.push_back(x);
  }
  r33 = z1[h11 - 1] - z1[0];
  r33 = r33 * w;
  cin >> h22;
  vector<long long> z2;
  for (long long i = 0; i < h22; i++) {
    long long x;
    cin >> x;
    z2.push_back(x);
  }
  r44 = z2[h22 - 1] - z2[0];
  r44 = r44 * w;
  long long ans = max(max(r11, r22), max(r33, r44));
  cout << ans << endl;
  return;
}
int main() {
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
