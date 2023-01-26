#include <bits/stdc++.h>
using namespace std;
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= 1000000007) a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= 1000000007) res %= 1000000007;
    a = a * a;
    if (a >= 1000000007) a %= 1000000007;
  }
  return res;
}
static bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return (a.second == b.second) ? a.first > b.first : a.second < b.second;
}
void printArray(vector<long long> arr) {
  for (long long i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
bool prime[100000005];
void SieveOfEratosthenes(long long n) {
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long lcm(long long a, long long b) { return (a / __gcd(a, b)) * b; }
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool find_any_solution(long long a, long long b, long long c, long long &x0,
                       long long &y0, long long &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
bool checkperfectsquare(long long n) {
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    return true;
  } else {
    return false;
  }
}
bool check(long long a, long long b, long long c) {
  long long g = __gcd(a, b);
  if (c % g) {
    cout << "NO"
         << "\n";
    return false;
  }
  while (c % b && c > 0) c -= a;
  if (c >= 0)
    return true;
  else
    return false;
}
string test(string str, long long n) { return str.erase(n, 1); }
void solve() {
  long long l, r, b;
  cin >> l >> r;
  if (l > (r / 2))
    cout << r % l << "\n";
  else
    cout << (r) % ((r / 2) + 1) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
